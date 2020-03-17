﻿#ifndef _NET_MANAGER_H_
#define _NET_MANAGER_H_
#include "IBufferHandler.h"
#include "CommonThreadFunc.h"
#include "CommonMsgQueue.h"

Th_RetName _NetEventThread( void* pParam );

Th_RetName _NetListenThread( void* pParam );

struct EventNode
{
	UINT32		dwEvent;
	void*		pPtr;
};

////////////////////////////////////////////////

class CNetManager
{
	CNetManager(void);

	virtual ~CNetManager(void);
public:
	static CNetManager* GetInstancePtr()
	{
		static CNetManager NetManager;

		return &NetManager;
	}
public:
	BOOL	Start(UINT16 nPortNum,  UINT32 nMaxConn, IDataHandler* pBufferHandler);

	BOOL	Close();

	BOOL	SendMessageByConnID(UINT32 dwConnID,  UINT32 dwMsgID, UINT64 u64TargetID, UINT32 dwUserData,  const char* pData, UINT32 dwLen);

	BOOL    SendMsgBufByConnID(UINT32 dwConnID, IDataBuffer* pBuffer);
public:
	BOOL	InitNetwork();

	BOOL	UninitNetwork();

	BOOL	StartListen(UINT16 nPortNum);

	BOOL	StopListen();

	//以下是完成端口部分
public:
	BOOL	CreateCompletePort();

	BOOL	DestroyCompletePort();

	BOOL	CreateEventThread(UINT32 nNum);

	BOOL    CloseEventThread();

	BOOL	WorkThread_ProcessEvent(UINT32 nParam);

	BOOL	WorkThread_Listen();

	BOOL	EventDelete(CConnection* pConnection);

	BOOL	PostSendOperation(CConnection* pConnection, BOOL bCheck = TRUE);

	CConnection*	AssociateCompletePort(SOCKET hSocket, BOOL bConnect);

	CConnection*	ConnectTo_Sync(std::string strIpAddr, UINT16 sPort);

	CConnection*	ConnectTo_Async(std::string strIpAddr, UINT16 sPort);

public:
	SOCKET				m_hListenSocket;

	HANDLE				m_hCompletePort;

	BOOL				m_bCloseEvent;		//是否关闭事件处理线程

	IDataHandler*		m_pBufferHandler;
	THANDLE				 m_hListenThread;
	std::vector<THANDLE> m_vtEventThread;

#ifndef WIN32

	static void SignalHandler(int nValue)
	{
		return;
	}

	BOOL  ClearSignal()
	{
		m_NewAct.sa_handler = CNetManager::SignalHandler;

		sigemptyset(&m_NewAct.sa_mask); //清空此信号集

		m_NewAct.sa_flags = 0;

		sigaction(SIGPIPE, &m_NewAct, &m_OldAct);

		return TRUE;
	}

	BOOL RestoreSignal()
	{
		sigaction(SIGPIPE, &m_OldAct, NULL); //恢复成原始状态

		return TRUE;
	}

	struct sigaction m_NewAct, m_OldAct;

#endif

};

#endif

