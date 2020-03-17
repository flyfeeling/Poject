#include "GameService.h"
#include "TimerManager.h"
CGameService::CGameService(void)
{
}

CGameService::~CGameService(void)
{
}

CGameService* CGameService::GetInstancePtr()
{
	static CGameService _GameService;

	return &_GameService;
}

BOOL CGameService::Init()
{
	CommonFunc::SetCurrentWorkDir("");

	if(!CLog::GetInstancePtr()->StartLog("AIServer", "log"))
	{
		return FALSE;
	}

	CLog::GetInstancePtr()->LogError("---------服务器开始启动-----------");

	if(!CConfigFile::GetInstancePtr()->Load("servercfg.ini"))
	{
		CLog::GetInstancePtr()->LogError("配制文件加载失败!");
		return FALSE;
	}

	CLog::GetInstancePtr()->SetLogLevel(CConfigFile::GetInstancePtr()->GetIntValue("ai_log_level"));

	UINT16 nPort = CConfigFile::GetInstancePtr()->GetIntValue("ai_svr_port");
	INT32  nMaxConn = CConfigFile::GetInstancePtr()->GetIntValue("ai_svr_max_con");

	if(!ServiceBase::GetInstancePtr()->StartNetwork(nPort, nMaxConn, this))
	{
		CLog::GetInstancePtr()->LogError("启动服务失败!");
		return FALSE;
	}
	ERROR_RETURN_FALSE(m_dwAIMsgHandler.Init());
	CLog::GetInstancePtr()->LogError("---------服务器启动成功!--------");

	return TRUE;
}


BOOL CGameService::Uninit()
{
	ServiceBase::GetInstancePtr()->StopNetwork();
	google::protobuf::ShutdownProtobufLibrary();
	return TRUE;
}

BOOL CGameService::Run()
{
	while(TRUE)
	{
		ServiceBase::GetInstancePtr()->Update();
		
		CommonFunc::Sleep(1);
	}

	return TRUE;
}

BOOL CGameService::OnNewConnect(CConnection* pConn)
{
	CLog::GetInstancePtr()->LogWarnning("New session is connected ! ConnectID = [%d]", pConn->GetConnectionID());
	m_dwAIMsgHandler.OnNewConnect(pConn);
	return TRUE;
}

BOOL CGameService::OnCloseConnect(CConnection* pConn)
{
	m_dwAIMsgHandler.OnCloseConnect(pConn);
	return TRUE;
}

BOOL CGameService::OnSecondTimer()
{
	return TRUE;
}

BOOL CGameService::DispatchPacket(NetPacket* pNetPacket)
{
	if (m_dwAIMsgHandler.DispatchPacket(pNetPacket))
	{
		return TRUE;
	}
	return FALSE;
}
