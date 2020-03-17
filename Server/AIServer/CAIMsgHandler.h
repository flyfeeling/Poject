#ifndef CAIMsgHandler_h__
#define CAIMsgHandler_h__
#include "ServerEngine.h"
class CAIMsgHandler 
{
public:
	CAIMsgHandler();

	~CAIMsgHandler();

	BOOL		Init();

	BOOL		Uninit();

	BOOL		DispatchPacket(NetPacket* pNetPacket);

	BOOL		OnNewConnect(CConnection* pConn);

	BOOL		OnCloseConnect(CConnection* pConn);

	BOOL		OnMsgGameSvrRegister(NetPacket* pPacket);
public:
	std::map<UINT32, UINT32> m_mapSvrIDtoConnID;
};

#endif // CAIMsgHandler_h__
