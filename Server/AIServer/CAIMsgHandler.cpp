#include "ServerEngine.h"
#include "CAIMsgHandler.h"
#include "PacketHeader.h"
#include "../Message/ProtoInclude.h"
CAIMsgHandler::CAIMsgHandler()
{

}

CAIMsgHandler::~CAIMsgHandler()
{

}

BOOL CAIMsgHandler::Init()
{
	return TRUE;
}

BOOL CAIMsgHandler::Uninit()
{
	return TRUE;
}

BOOL CAIMsgHandler::DispatchPacket(NetPacket* pNetPacket)
{
	PacketHeader* pPacketHeader = (PacketHeader*)pNetPacket->m_pDataBuffer->GetBuffer();
	ERROR_RETURN_FALSE(pPacketHeader != NULL);

	switch (pNetPacket->m_dwMsgID)
	{
		PROCESS_MESSAGE_ITEM(MSG_GS_REGISTER_AISVR_REQ, OnMsgGameSvrRegister);
	}

	return TRUE;
}

BOOL CAIMsgHandler::OnNewConnect(CConnection* pConn)
{
	return TRUE;
}

BOOL CAIMsgHandler::OnCloseConnect(CConnection* pConn)
{
	return TRUE;
}

BOOL CAIMsgHandler::OnMsgGameSvrRegister(NetPacket* pPacket)
{
	SvrRegToSvrReq Req;
	Req.ParsePartialFromArray(pPacket->m_pDataBuffer->GetData(), pPacket->m_pDataBuffer->GetBodyLenth());

	m_mapSvrIDtoConnID.insert(std::make_pair(Req.serverid(), pPacket->m_dwConnID));

	SvrRegToSvrAck Ack;
	Ack.set_retcode(MRC_SUCCESSED);
	ServiceBase::GetInstancePtr()->SendMsgProtoBuf(pPacket->m_dwConnID, MSG_GS_REGISTER_AISVR_ACK, 0, 0, Ack);
	return TRUE;
}