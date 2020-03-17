﻿#include "AccountMsgHandler.h"
#include "PacketHeader.h"
#include "GameService.h"
#include "../Message/ProtoInclude.h"


CAccountMsgHandler::CAccountMsgHandler()
{

}

CAccountMsgHandler::~CAccountMsgHandler()
{

}

BOOL CAccountMsgHandler::Init(UINT32 dwReserved)
{
	m_AccountManager.Init();

	return TRUE;
}

BOOL CAccountMsgHandler::Uninit()
{
	return TRUE;
}


BOOL CAccountMsgHandler::DispatchPacket(NetPacket* pNetPacket)
{
	switch(pNetPacket->m_dwMsgID)
	{
		PROCESS_MESSAGE_ITEM(MSG_ACCOUNT_REG_REQ, OnMsgAccountRegReq);
		PROCESS_MESSAGE_ITEM(MSG_ACCOUNT_LOGIN_REQ, OnMsgAccontLoginReq);
		PROCESS_MESSAGE_ITEM(MSG_SEAL_ACCOUNT_REQ, OnMsgSealAccountReq);
	}

	return FALSE;
}


BOOL CAccountMsgHandler::OnMsgAccountRegReq(NetPacket* pPacket)
{
	AccountRegReq Req;

	Req.ParsePartialFromArray(pPacket->m_pDataBuffer->GetData(), pPacket->m_pDataBuffer->GetBodyLenth());

	PacketHeader* pHeader = (PacketHeader*) pPacket->m_pDataBuffer->GetBuffer();

	ERROR_RETURN_TRUE(pHeader->dwUserData != 0);

	AccountRegAck Ack;

	CAccountObject* pAccount = m_AccountManager.GetAccountObject(Req.accountname(), Req.channel());
	if(pAccount != NULL)
	{
		Ack.set_retcode(MRC_ACCOUNT_EXIST);
		ServiceBase::GetInstancePtr()->SendMsgProtoBuf(pPacket->m_dwConnID, MSG_ACCOUNT_REG_ACK, 0, pHeader->dwUserData, Ack);
		return TRUE;
	}

	UINT64 u64ID = 0;
	UINT32 dwChannel = 0;
	std::string strPwd;
	pAccount = m_AccountManager.CreateAccountObject(Req.accountname(), Req.password(), Req.channel());
	if(pAccount == NULL)
	{
		Ack.set_retcode(MRC_UNKNOW_ERROR);
		CLog::GetInstancePtr()->LogError("Error CAccountMsgHandler::OnMsgAccountRegReq RetCode:MRC_FAILED");
	}
	else
	{
		Ack.set_retcode(MRC_SUCCESSED);
		Ack.set_accountid(pAccount->m_ID);
	}

	ServiceBase::GetInstancePtr()->SendMsgProtoBuf(pPacket->m_dwConnID, MSG_ACCOUNT_REG_ACK, 0, pHeader->dwUserData, Ack);

	return TRUE;
}

BOOL CAccountMsgHandler::OnMsgAccontLoginReq(NetPacket* pPacket)
{
	AccountLoginReq Req;
	Req.ParsePartialFromArray(pPacket->m_pDataBuffer->GetData(), pPacket->m_pDataBuffer->GetBodyLenth());

	PacketHeader* pHeader = (PacketHeader*) pPacket->m_pDataBuffer->GetBuffer();
	ERROR_RETURN_TRUE(pHeader->dwUserData != 0);

	AccountLoginAck Ack;
	CAccountObject* pAccObj = m_AccountManager.GetAccountObject(Req.accountname(), Req.channel());
	if(pAccObj != NULL)
	{
		ERROR_RETURN_FALSE(pAccObj->m_ID != 0);
		if (pAccObj->m_uSealTime != 0 && CommonFunc::GetCurrTime() < pAccObj->m_uSealTime)
		{
			Ack.set_retcode(MRC_ACCOUNT_SEALED);
			Ack.set_lastsvrid(0);
			Ack.set_accountid(0);
		}
		else if(Req.password() == pAccObj->m_strPassword)
		{
			Ack.set_retcode(MRC_SUCCESSED);
			Ack.set_lastsvrid(pAccObj->m_dwLastSvrID);
			Ack.set_accountid(pAccObj->m_ID);
		}

		ServiceBase::GetInstancePtr()->SendMsgProtoBuf(pPacket->m_dwConnID, MSG_ACCOUNT_LOGIN_ACK, 0, pHeader->dwUserData, Ack);
		return TRUE;
	}

	//如果没有这个账号，就要判断是从哪里来到登录请求
	if (Req.fromchannel() == 1)
	{
		UINT64 u64ID = 0;
		UINT32 dwChannel = 0;
		std::string strPwd;
		pAccObj = m_AccountManager.CreateAccountObject(Req.accountname(), Req.password(), Req.channel());
		if (pAccObj == NULL)
		{
			Ack.set_retcode(MRC_UNKNOW_ERROR);
			CLog::GetInstancePtr()->LogError("Error CAccountMsgHandler::OnMsgAccontLoginReq RetCode:MRC_FAILED");
		}
		else
		{
			Ack.set_retcode(MRC_SUCCESSED);
			Ack.set_accountid(pAccObj->m_ID);
			Ack.set_lastsvrid(0);
		}
	}
	else
	{
		Ack.set_retcode(MRC_INVALID_ACCNAME);
		Ack.set_lastsvrid(0);
		Ack.set_accountid(0);
	}

	ServiceBase::GetInstancePtr()->SendMsgProtoBuf(pPacket->m_dwConnID, MSG_ACCOUNT_LOGIN_ACK, 0, pHeader->dwUserData, Ack);

	return TRUE;
}


BOOL CAccountMsgHandler::OnMsgSealAccountReq(NetPacket* pPacket)
{
	SealAccountReq Req;
	Req.ParsePartialFromArray(pPacket->m_pDataBuffer->GetData(), pPacket->m_pDataBuffer->GetBodyLenth());
	PacketHeader* pHeader = (PacketHeader*) pPacket->m_pDataBuffer->GetBuffer();
	ERROR_RETURN_TRUE(pHeader->dwUserData != 0);

	SealAccountAck Ack;

	if (m_AccountManager.SealAccount(Req.accountid(), Req.accountname(), Req.channel(), Req.seal(), Req.sealtime()))
	{
		Ack.set_retcode(MRC_SUCCESSED);
	}
	else
	{
		Ack.set_retcode(MRC_UNKNOW_ERROR);
	}

	ServiceBase::GetInstancePtr()->SendMsgProtoBuf(pPacket->m_dwConnID, MSG_SEAL_ACCOUNT_ACK, 0, pHeader->dwUserData, Ack);

	return TRUE;
}