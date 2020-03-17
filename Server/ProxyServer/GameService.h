﻿#ifndef _GAME_SERVICE_H_
#define _GAME_SERVICE_H_
#include "ProxyMsgHandler.h"
class  CConnection;

class CGameService  : public IPacketDispatcher
{
private:
	CGameService(void);
	virtual ~CGameService(void);

public:
	static CGameService* GetInstancePtr();

	BOOL		Init();

	BOOL		Uninit();

	BOOL		Run();

	BOOL		OnNewConnect(CConnection* pConn);

	BOOL		OnCloseConnect(CConnection* pConn);

	BOOL		OnSecondTimer();

	BOOL		DispatchPacket( NetPacket* pNetPacket);

	UINT32		GetLogicConnID();

	BOOL		ConnectToLogicSvr();
public:
	//处理普通的网络连接
	CProxyMsgHandler	m_ProxyMsgHandler;

	UINT32				m_dwLogicConnID;
public:
	//*********************消息处理定义开始******************************
	//*********************消息处理定义结束******************************
};

#endif
