#ifndef _GAME_SERVICE_H_
#define _GAME_SERVICE_H_
#include "CAIMsgHandler.h"
#include "ServerEngine.h"
class CGameService  : public IPacketDispatcher
{
private:
	CGameService(void);
	virtual ~CGameService(void);

public:
	static CGameService* GetInstancePtr();

public:

	BOOL		Init();

	BOOL		Uninit();

	BOOL		Run();

	BOOL		OnNewConnect(CConnection* pConn);

	BOOL		OnCloseConnect(CConnection* pConn);

	BOOL		OnSecondTimer();

	BOOL		DispatchPacket( NetPacket* pNetPacket);

public:
	CAIMsgHandler m_dwAIMsgHandler;
public:
	//*********************消息处理定义开始******************************
	//*********************消息处理定义结束******************************
};

#endif
