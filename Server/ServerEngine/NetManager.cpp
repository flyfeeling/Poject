﻿#include "stdafx.h"
#include "NetManager.h"
#include "Connection.h"
#include "CommonSocket.h"
#include "DataBuffer.h"
#include "PacketHeader.h"


CNetManager::CNetManager(void)
{
	m_hListenThread		= (THANDLE)NULL;
	m_hListenSocket		= NULL;
	m_hCompletePort		= NULL;
	m_bCloseEvent		= TRUE;
	m_pBufferHandler	= NULL;
}

CNetManager::~CNetManager(void)
{
}

BOOL CNetManager::CreateEventThread(UINT32 nNum )
{
	if(nNum == 0)
	{
		nNum = CommonFunc::GetProcessorNum();
	}

	ERROR_RETURN_FALSE(nNum > 0);

	m_bCloseEvent = FALSE;

	//目前linux使用单线程
#ifndef WIN32
	nNum = 1;
#endif

	for(UINT32 i = 0; i < nNum; ++i)
	{
		THANDLE hThread = CommonThreadFunc::CreateThread(_NetEventThread, (void*)NULL);
		m_vtEventThread.push_back(hThread);
	}

	return TRUE;
}

BOOL CNetManager::WorkThread_Listen()
{
	sockaddr_in Con_Addr;
	socklen_t nLen = sizeof(Con_Addr);
	while(TRUE)
	{
		memset(&Con_Addr, 0, sizeof(Con_Addr));
		SOCKET hClientSocket = accept(m_hListenSocket, (sockaddr*)&Con_Addr, &nLen);
		if(hClientSocket == INVALID_SOCKET)
		{
			break;
		}
		CommonSocket::SetSocketUnblock(hClientSocket);
		CConnection* pConnection = AssociateCompletePort(hClientSocket, FALSE);
		if(pConnection != NULL)
		{
			pConnection->m_dwIpAddr = Con_Addr.sin_addr.s_addr;

			pConnection->SetConnectionOK(TRUE);

			m_pBufferHandler->OnNewConnect(pConnection);

			//在Windows的IOCP模式，一个新的连接必须首先调一次接收， 而EPOLL模型下，只要关注了读事件就可以等事件到了之后发读的操作。
#ifdef WIN32
			if(!pConnection->DoReceive())
			{
				pConnection->Close();
			}
#endif
		}
		else
		{
			CLog::GetInstancePtr()->LogError("accept 错误 原因:%s!", CommonSocket::GetLastErrorStr(CommonSocket::GetSocketLastError()).c_str());
		}
	}

	return TRUE;
}

BOOL CNetManager::StartListen(UINT16 nPortNum)
{
	sockaddr_in SvrAddr;
	SvrAddr.sin_family		= AF_INET;
	SvrAddr.sin_port		= htons(nPortNum);
	
	SvrAddr.sin_addr.s_addr = htonl(INADDR_ANY);		//支持多IP地址监听

	m_hListenSocket = CommonSocket::CreateSocket(AF_INET, SOCK_STREAM, 0);
	if(m_hListenSocket == INVALID_SOCKET)
	{
		CLog::GetInstancePtr()->LogError("创建监听套接字失败原因:%s!", CommonSocket::GetLastErrorStr(CommonSocket::GetSocketLastError()).c_str());
		return FALSE;
	}

	CommonSocket::SetSocketReuseable(m_hListenSocket);

	if(!CommonSocket::BindSocket(m_hListenSocket, (sockaddr*)&SvrAddr, sizeof(SvrAddr)))
	{
		CLog::GetInstancePtr()->LogError("邦定套接字失败原因:%s!", CommonSocket::GetLastErrorStr(CommonSocket::GetSocketLastError()).c_str());
		return FALSE;
	}

	if(!CommonSocket::ListenSocket(m_hListenSocket, 20))
	{
		CLog::GetInstancePtr()->LogError("监听线程套接字失败:%s!", CommonSocket::GetLastErrorStr(CommonSocket::GetSocketLastError()).c_str());
		return FALSE;
	}

	if((m_hListenThread = CommonThreadFunc::CreateThread(_NetListenThread,  (void*)NULL)) == NULL)
	{
		CLog::GetInstancePtr()->LogError("创建监听线程失败:%s!", CommonSocket::GetLastErrorStr(CommonSocket::GetSocketLastError()).c_str());
		return FALSE;
	}

	return TRUE;
}


#ifdef WIN32

BOOL CNetManager::WorkThread_ProcessEvent(UINT32 nParam)
{
	ERROR_RETURN_FALSE(m_hCompletePort != INVALID_HANDLE_VALUE);

	DWORD dwNumOfByte = 0;
	ULONG_PTR CompleteKey = 0;
	LPOVERLAPPED lpOverlapped = NULL;
	DWORD dwWaitTime = 1000;
	BOOL  bRetValue = FALSE;

	while(!m_bCloseEvent)
	{
		bRetValue = GetQueuedCompletionStatus(m_hCompletePort, &dwNumOfByte, &CompleteKey, &lpOverlapped, dwWaitTime);
		if(!bRetValue)
		{
			if(lpOverlapped == NULL)
			{
				if(ERROR_ABANDONED_WAIT_0 == CommonSocket::GetSocketLastError())
				{
					CLog::GetInstancePtr()->LogError("完成端口被外部关闭!");
					return FALSE;
				}

				if(CommonSocket::GetSocketLastError() == WAIT_TIMEOUT)
				{
					continue;
				}
			}
		}

		NetIoOperatorData* pIoPeratorData = (NetIoOperatorData*)lpOverlapped;
		switch( pIoPeratorData->dwCmdType )
		{
			case NET_MSG_RECV:
			{
				CConnection* pConnection = (CConnection*)CompleteKey;
				if(pConnection == NULL)
				{
					CLog::GetInstancePtr()->LogError("触发了NET_MSG_RECV1, pConnection == NULL");
					break;
				}

				if(dwNumOfByte == 0)
				{
					//说明对方己经关闭
					if(pConnection->GetConnectionID() != pIoPeratorData->dwConnID)
					{
						CLog::GetInstancePtr()->LogError("触发了NET_MSG_RECV2, 对方己经关闭连接，但可能我们这边更快, 连接己经被重用了。nowid:%d, oldid:%d", pConnection->GetConnectionID(), pIoPeratorData->dwConnID);
						break;
					}
					pConnection->Close();
				}
				else
				{
					if(pConnection->GetConnectionID() != pIoPeratorData->dwConnID)
					{
						CLog::GetInstancePtr()->LogError("触发了NET_MSG_RECV3，确实有数据, 但连接己经被重用了。nowid:%d, oldid:%d", pConnection->GetConnectionID(), pIoPeratorData->dwConnID);
						break;
					}

					if(pConnection->IsConnectionOK())
					{
						if(!pConnection->HandleRecvEvent(dwNumOfByte))
						{
							//收数据失败，基本就是连接己断开
							if(pConnection->GetConnectionID() != pIoPeratorData->dwConnID)
							{
								CLog::GetInstancePtr()->LogError("触发了NET_MSG_RECV4, 但连接己经被关闭重用了。nowid:%d, oldid:%d", pConnection->GetConnectionID(), pIoPeratorData->dwConnID);
								break;
							}
							pConnection->Close();
						}
					}
					else
					{
						CLog::GetInstancePtr()->LogError("严重的错误, 没有连接上，却收到的数据!", pConnection);
						ASSERT_FAIELD;
					}
				}
			}
			break;
			case NET_MSG_SEND:
			{
				pIoPeratorData->pDataBuffer->Release();
				CConnection* pConnection = (CConnection*)CompleteKey;
				if (pConnection == NULL)
				{
					CLog::GetInstancePtr()->LogError("触发了NET_MSG_SEND, pConnection == NULL。");
					ASSERT_FAIELD;
					break;
				}

				if(pConnection->GetConnectionID() != pIoPeratorData->dwConnID)
				{
					CLog::GetInstancePtr()->LogError("触发了NET_MSG_SEND, 但连接己经被关闭重用了。");
					break;
				}

				pConnection->DoSend();
			}
			break;
			case NET_MSG_POST:
			{
				CConnection* pConnection = (CConnection*)CompleteKey;
				if (pConnection == NULL)
				{
					CLog::GetInstancePtr()->LogError("触发了NET_MSG_POST1, pConnection == NULL。");
					ASSERT_FAIELD;
					break;
				}

				if (pConnection->GetConnectionID() != pIoPeratorData->dwConnID)
				{
					CLog::GetInstancePtr()->LogError("触发了NET_MSG_POST2, 但连接己经被关闭重用了。");
					break;
				}

				pConnection->DoSend();
			}
			break;
			case NET_MSG_CONNECT:
			{
				CConnection* pConnection = (CConnection*)CompleteKey;
				if (pConnection == NULL)
				{
					CLog::GetInstancePtr()->LogError("触发了NET_MSG_CONNECT, pConnection == NULL。");
					break;
				}

				if (pConnection->GetConnectionID() != pIoPeratorData->dwConnID)
				{
					CLog::GetInstancePtr()->LogError("触发了NET_MSG_CONNECT, 事件ID和连接ID不一致。");
					break;
				}

				if(bRetValue)
				{
					pConnection->SetConnectionOK(TRUE);
					m_pBufferHandler->OnNewConnect(pConnection);

					if(!pConnection->DoReceive())
					{
						pConnection->Close();
					}
				}
				else
				{
					pConnection->SetConnectionOK(FALSE);
					pConnection->Close();
				}
			}
			break;
		}
	}

	return TRUE;
}


BOOL CNetManager::CreateCompletePort()
{
	m_hCompletePort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, 0, 0, -1);
	ERROR_RETURN_FALSE(m_hCompletePort != NULL);

	return TRUE;
}

CConnection* CNetManager::AssociateCompletePort( SOCKET hSocket, BOOL bConnect)
{
	CConnection* pConnection = CConnectionMgr::GetInstancePtr()->CreateConnection();
	ERROR_RETURN_NULL(pConnection != NULL);
	pConnection->SetSocket(hSocket);
	pConnection->SetDataHandler(m_pBufferHandler);
	if(NULL == CreateIoCompletionPort((HANDLE)hSocket, m_hCompletePort, (ULONG_PTR)pConnection, 0))
	{
		pConnection->Close();
		return pConnection;
	}
	return pConnection;
}

BOOL CNetManager::DestroyCompletePort()
{
	CloseHandle(m_hCompletePort);

	return TRUE;
}


BOOL CNetManager::EventDelete(CConnection* pConnection)
{
	return TRUE;
}

#else

BOOL CNetManager::CreateCompletePort()
{
	m_hCompletePort = epoll_create(10000);

	ERROR_RETURN_FALSE(m_hCompletePort != -1);

	return TRUE;
}

CConnection* CNetManager::AssociateCompletePort( SOCKET hSocket, BOOL bConnect)
{
	CConnection* pConnection = CConnectionMgr::GetInstancePtr()->CreateConnection();

	pConnection->SetSocket(hSocket);

	pConnection->SetDataHandler(m_pBufferHandler);

	if (hSocket == INVALID_SOCKET || hSocket == 0)
	{
		pConnection->Close();

		return pConnection;
	}

	struct epoll_event EpollEvent;
	EpollEvent.data.ptr = pConnection;
	if (bConnect)
	{
		EpollEvent.events = EPOLLIN | EPOLLOUT | EPOLLET;
	}
	else
	{
		EpollEvent.events = EPOLLIN | EPOLLET;
	}

	if(-1 == epoll_ctl(m_hCompletePort, EPOLL_CTL_ADD, hSocket, &EpollEvent))
	{
		pConnection->Close();

		return pConnection;
	}

	return pConnection;
}

BOOL CNetManager::DestroyCompletePort()
{
	close(m_hCompletePort);

	return TRUE;
}

BOOL CNetManager::WorkThread_ProcessEvent(UINT32 nParam)
{
	struct epoll_event EpollEvent[20];
	int nFd = 0;
	while (!m_bCloseEvent)
	{
		nFd = epoll_wait(m_hCompletePort, EpollEvent, 20, 1000);
		if (nFd == -1)
		{
			continue;
		}

		for (int i = 0; i < nFd; ++i)
		{
			CConnection* pConnection = (CConnection*)EpollEvent[i].data.ptr;
			if (pConnection == NULL)
			{
				CLog::GetInstancePtr()->LogError("---Invalid pConnection Ptr------------!", nFd);
				continue;
			}

			if ((EpollEvent[i].events & EPOLLERR) || (EpollEvent[i].events & EPOLLHUP))
			{
				EventDelete(pConnection);
				pConnection->Close();
				continue;
			}

			int nError;
			socklen_t len;
			if (getsockopt(pConnection->GetSocket(), SOL_SOCKET, SO_ERROR, (char*)&nError, &len) < 0)
			{
				CLog::GetInstancePtr()->LogError("-------getsockopt Error:%d--------失败----!", nError);
				continue;
			}

			if (nError != 0)
			{
				if (EpollEvent[i].events & EPOLLIN)
				{
					CLog::GetInstancePtr()->LogError("-------EPOLLIN---------失败---!");
				}

				if (EpollEvent[i].events & EPOLLOUT)
				{
					CLog::GetInstancePtr()->LogError("-------EPOLLOUT----失败-------!");
				}

				continue;
			}

			if (EpollEvent[i].events & EPOLLIN)
			{
				if (!pConnection->IsConnectionOK())
				{
					pConnection->SetConnectionOK(TRUE);
					m_pBufferHandler->OnNewConnect(pConnection);
				}

				if (!pConnection->HandleRecvEvent(0))
				{
					//基本表明连接己断开，可以关闭连接了。
					EventDelete(pConnection);
					pConnection->Close();
					continue;
				}
			}

			if (EpollEvent[i].events & EPOLLOUT)
			{
				if (!pConnection->IsConnectionOK())
				{
					pConnection->SetConnectionOK(TRUE);
					m_pBufferHandler->OnNewConnect(pConnection);
				}

				UINT32 nRet = pConnection->DoSend();
				if (nRet == E_SEND_ERROR)
				{
					EventDelete(pConnection);
					pConnection->Close();
				}
				else if (nRet == E_SEND_UNDONE)
				{
					PostSendOperation(pConnection);
				}
				else if (nRet == E_SEND_SUCCESS)
				{
					struct epoll_event EpollEvent;
					EpollEvent.data.ptr = pConnection;
					EpollEvent.events = EPOLLIN | EPOLLET;
					epoll_ctl(m_hCompletePort, EPOLL_CTL_MOD, pConnection->GetSocket(), &EpollEvent);
				}
			}
		}
	}

	return TRUE;
}


BOOL CNetManager::EventDelete(CConnection* pConnection)
{
	struct epoll_event delEpv = { 0, { 0 } };
	delEpv.data.ptr = pConnection;
	if (-1 == epoll_ctl(m_hCompletePort, EPOLL_CTL_DEL, pConnection->GetSocket(), &delEpv))
	{
		CLog::GetInstancePtr()->LogError("---epoll_ctl----epoll_ctl------失败------!");
		return FALSE;
	}

	return TRUE;
}

#endif


BOOL CNetManager::Start(UINT16 nPortNum, UINT32 nMaxConn, IDataHandler* pBufferHandler)
{
	ERROR_RETURN_FALSE(pBufferHandler != NULL);

	m_pBufferHandler = pBufferHandler;

	CConnectionMgr::GetInstancePtr()->InitConnectionList(nMaxConn);

	if(!InitNetwork())
	{
		CLog::GetInstancePtr()->LogError("初始化网络失败！！");
		return FALSE;
	}

	if(!CreateCompletePort())
	{
		CLog::GetInstancePtr()->LogError("创建完成端口或Epoll失败！！");
		return FALSE;
	}

	if(!CreateEventThread(0))
	{
		CLog::GetInstancePtr()->LogError("创建网络事件处理线程失败！！");
		return FALSE;
	}

	if(!StartListen(nPortNum))
	{
		CLog::GetInstancePtr()->LogError("开启监听失败！！");
		return FALSE;
	}

#ifndef WIN32
	ClearSignal();
#endif

	return TRUE;
}

BOOL CNetManager::InitNetwork()
{
	return CommonSocket::InitNetwork();
}

BOOL CNetManager::UninitNetwork()
{
	return CommonSocket::UninitNetwork();
}

BOOL CNetManager::Close()
{
	StopListen();

	CloseEventThread();

	CConnectionMgr::GetInstancePtr()->CloseAllConnection();

	DestroyCompletePort();

	UninitNetwork();

	CConnectionMgr::GetInstancePtr()->DestroyAllConnection();

	return TRUE;
}

BOOL CNetManager::StopListen()
{
	CommonSocket::CloseSocket(m_hListenSocket);

	CommonThreadFunc::WaitThreadExit(m_hListenThread);

	return TRUE;
}

CConnection* CNetManager::ConnectTo_Sync( std::string strIpAddr, UINT16 sPort )
{
	SOCKET hSocket = CommonSocket::CreateSocket(AF_INET, SOCK_STREAM, 0);
	if(hSocket == INVALID_SOCKET)
	{
		CommonSocket::CloseSocket(hSocket);
		CLog::GetInstancePtr()->LogError("创建套接字失败!!");
		return NULL;
	}

	CommonSocket::SetSocketBlock(hSocket);

	CommonSocket::SetSocketNoDelay(hSocket);

	if(!CommonSocket::ConnectSocket(hSocket, strIpAddr.c_str(), sPort))
	{
		CommonSocket::CloseSocket(hSocket);
		return NULL;
	}

	CConnection* pConnection = AssociateCompletePort(hSocket, TRUE);
	if(pConnection == NULL)
	{
		CLog::GetInstancePtr()->LogError("邦定套接字到完成端口失败!!");
		return NULL;
	}

	CommonSocket::SetSocketUnblock(hSocket);

	pConnection->SetConnectionOK(TRUE);

	m_pBufferHandler->OnNewConnect(pConnection);

	if(!pConnection->DoReceive())
	{
		pConnection->Close();
	}

	return pConnection;
}

CConnection* CNetManager::ConnectTo_Async( std::string strIpAddr, UINT16 sPort )
{
	SOCKET hSocket = CommonSocket::CreateSocket(AF_INET, SOCK_STREAM, 0);
	if(hSocket == INVALID_SOCKET || hSocket == 0)
	{
		CommonSocket::CloseSocket(hSocket);
		CLog::GetInstancePtr()->LogError("创建套接字失败!!");
		return NULL;
	}

	CommonSocket::SetSocketUnblock(hSocket);

	CommonSocket::SetSocketNoDelay(hSocket);

#ifdef WIN32
	CConnection* pConnection = AssociateCompletePort(hSocket, TRUE);
	if (pConnection == NULL)
	{
		CLog::GetInstancePtr()->LogError("邦定套接字到完成端口失败!!");

		return NULL;
	}

	pConnection->m_IoOverlapRecv.Reset();

	pConnection->m_IoOverlapRecv.dwCmdType = NET_MSG_CONNECT;

	pConnection->m_IoOverlapRecv.dwConnID = pConnection->GetConnectionID();

	pConnection->m_dwIpAddr = CommonSocket::IpAddrStrToInt((CHAR*)strIpAddr.c_str());

	BOOL bRet = CommonSocket::ConnectSocketEx(hSocket, strIpAddr.c_str(), sPort, (LPOVERLAPPED)&pConnection->m_IoOverlapRecv);

	if(!bRet)
	{
		pConnection->Close();
	}

#else
	BOOL bRet = CommonSocket::ConnectSocket(hSocket, strIpAddr.c_str(), sPort);
	if (!bRet)
	{
		CommonSocket::CloseSocket(hSocket);
		return NULL;
	}
		
	CConnection* pConnection = AssociateCompletePort(hSocket, TRUE);
	if (pConnection == NULL)
	{
		CLog::GetInstancePtr()->LogError("邦定套接字到完成端口失败!!");

		return NULL;
	}
#endif
	
	return pConnection;
}

BOOL CNetManager::SendMessageByConnID(UINT32 dwConnID,  UINT32 dwMsgID, UINT64 u64TargetID, UINT32 dwUserData,  const char* pData, UINT32 dwLen)
{
	if (dwConnID <= 0)
	{
		return FALSE;
	}
	
	CConnection* pConn = CConnectionMgr::GetInstancePtr()->GetConnectionByConnID(dwConnID);
	if(pConn == NULL)
	{
		//表示连接己经失败断开了，这个连接ID不可用了。
		return FALSE;
	}

	if(!pConn->IsConnectionOK())
	{
		CLog::GetInstancePtr()->LogError("CNetManager::SendMessageByConnID FAILED, 连接己断开");
		return FALSE;
	}

	IDataBuffer* pDataBuffer = CBufferAllocator::GetInstancePtr()->AllocDataBuff(dwLen + sizeof(PacketHeader));
	ERROR_RETURN_FALSE(pDataBuffer != NULL);

	PacketHeader* pHeader = (PacketHeader*)pDataBuffer->GetBuffer();
	pHeader->CheckCode = 0x88;
	pHeader->dwUserData = dwUserData;
	pHeader->u64TargetID = u64TargetID;
	pHeader->dwSize = dwLen + sizeof(PacketHeader);
	pHeader->dwMsgID = dwMsgID;
	pHeader->dwPacketNo = 1;

	memcpy(pDataBuffer->GetBuffer() + sizeof(PacketHeader), pData, dwLen);

	pDataBuffer->SetTotalLenth(pHeader->dwSize);

	if (pConn->SendBuffer(pDataBuffer))
	{
		PostSendOperation(pConn);
		return TRUE;
	}

	return FALSE;
}

BOOL CNetManager::SendMsgBufByConnID(UINT32 dwConnID, IDataBuffer* pBuffer)
{
	ERROR_RETURN_FALSE(dwConnID != 0);
	CConnection* pConn = CConnectionMgr::GetInstancePtr()->GetConnectionByConnID(dwConnID);
	if(pConn == NULL)
	{
		//表示连接己经失败断开了，这个连接ID不可用了。
		return FALSE;
	}
	if(!pConn->IsConnectionOK())
	{
		CLog::GetInstancePtr()->LogError("CNetManager::SendMsgBufByConnID FAILED, 连接己断开");
		return FALSE;
	}

	pBuffer->AddRef();
	if (pConn->SendBuffer(pBuffer))
	{
		PostSendOperation(pConn);
		return TRUE;
	}

	return FALSE;
}

BOOL CNetManager::CloseEventThread()
{
	m_bCloseEvent = TRUE;

	for(std::vector<THANDLE>::iterator itor = m_vtEventThread.begin(); itor != m_vtEventThread.end(); ++itor)
	{
		CommonThreadFunc::WaitThreadExit(*itor);
	}

	return TRUE;
}

Th_RetName _NetEventThread( void* pParam )
{
	CNetManager* pNetManager = CNetManager::GetInstancePtr();

	pNetManager->WorkThread_ProcessEvent(0);

	CommonThreadFunc::ExitThread();

	return Th_RetValue;
}

Th_RetName _NetListenThread( void* pParam )
{
	CNetManager* pNetManager = CNetManager::GetInstancePtr();

	pNetManager->WorkThread_Listen();

	CommonThreadFunc::ExitThread();

	return Th_RetValue;
}


BOOL CNetManager::PostSendOperation(CConnection* pConnection, BOOL bCheck)
{
	if (pConnection == NULL)
	{
		ASSERT_FAIELD;
		return FALSE;
	}

	if (!pConnection->m_IsSending || !bCheck)
	{
#ifdef WIN32
		pConnection->m_IsSending = TRUE;
		pConnection->m_IoOverLapPost.Reset();
		pConnection->m_IoOverLapPost.dwCmdType = NET_MSG_POST;
		pConnection->m_IoOverLapPost.dwConnID = pConnection->GetConnectionID();
		PostQueuedCompletionStatus(m_hCompletePort, pConnection->GetConnectionID(), (ULONG_PTR)pConnection, (LPOVERLAPPED)&pConnection->m_IoOverLapPost);
#else
		struct epoll_event EpollEvent;
		EpollEvent.data.ptr = pConnection;
		EpollEvent.events = EPOLLOUT | EPOLLET;
		epoll_ctl(m_hCompletePort, EPOLL_CTL_MOD, pConnection->GetSocket(), &EpollEvent);
#endif
	}
	return TRUE;
}