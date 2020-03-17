﻿#ifndef __DB_ACCOUNT_OBJECT_H__
#define __DB_ACCOUNT_OBJECT_H__
/************************************************************************/
/*               winsock 一定要定义在mysql之前                          */
/************************************************************************/
#include "ServerEngine.h"
#include "AVLTree.h"
#include "DBInterface/CppMysql.h"
#include "LockFreeQueue.h"
Th_RetName _SaveAccountThread( void* pParam );
struct CAccountObject
{
	UINT64		m_ID;
	std::string m_strName;
	std::string m_strPassword;
	UINT32      m_dwLastSvrID;
	UINT32      m_dwChannel;	//渠道ID
	UINT64		m_uSealTime;    //封禁结束时间
	UINT64      m_uCreateTime;  //创建时间
};


class CAccountObjectMgr : public AVLTree<UINT64, CAccountObject>
{
public:
	CAccountObjectMgr();
	~CAccountObjectMgr();

public:
	BOOL				LoadCacheAccount();
public:
	CAccountObject*		GetAccountObjectByID(UINT64 m_u64AccountID);

	CAccountObject*		CreateAccountObject(const std::string& strName, const std::string& strPwd, UINT32 dwChannel);

	BOOL				ReleaseAccountObject(UINT64 m_u64AccountID);

	BOOL				SealAccount(UINT64 m_uAccountID, const std::string& strName, UINT32 dwChannel, BOOL bSeal, UINT32 dwSealTime);

	CAccountObject*		AddAccountObject(UINT64 u64ID, const CHAR* pStrName, UINT32 dwChannel);

	CAccountObject*		GetAccountObject(const std::string& name, UINT32 dwChannel);

	BOOL				SaveAccountChange();

	BOOL				Init();

	BOOL				Uninit();

	BOOL				IsRun();

public:

	std::map<std::string, CAccountObject*>	m_mapNameObj;

	ArrayLockFreeQueue<CAccountObject*>		m_ArrChangedAccount;

	CppMySQL3DB 		m_DBConnection;

	BOOL				m_IsRun;

	HANDLE				m_hThread;

	UINT64				m_u64MaxID;

	BOOL				m_bCrossChannel;   //是否区分渠道
};

#endif //__DB_ACCOUNT_OBJECT_H__
