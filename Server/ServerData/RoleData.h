﻿#ifndef __ROLE_DATA_OBJECT_H__
#define __ROLE_DATA_OBJECT_H__
#include "ServerEngine.h"
#include "DBInterface/DBStoredProc.h"
#include "DBInterface/DBInterface.h"
#include "ServerDefine.h"
struct RoleDataObject : public ShareObject
{
	RoleDataObject()
	{
		m_uRoleID		= 0;			//角色ID
		m_uAccountID	= 0;			//账号ID
		m_Level			= 0;				//等级
		m_Exp			= 0;			//经验
		m_nLangID		= 0;			//语言ID
		m_u64Fight		= 0;			//战力
		m_VipLvl		= 0;			//VIP等级
		m_VipExp		= 0;			//VIP经验
		m_CityCopyID	= 0;			//主城副本类型
		m_bDelete       = FALSE;        //是否删除
		m_CarrerID      = 0;
		m_uCreateTime	= 0;
		m_uLogonTime	= 0;	  //本次登录时间
		m_uLogoffTime	= 0;	  //离线时间
		memset(m_szName, 0, ROLE_NAME_LEN);
	}

	UINT64		m_uRoleID;			//角色ID
	UINT64		m_uAccountID;	//账号ID
	CHAR		m_szName[ROLE_NAME_LEN];	//角色名
	INT32		m_CarrerID;      //职业ID
	INT32		m_Level;			//等级
	INT64		m_Action[ACTION_NUM];		//所有的体力
	INT64		m_Actime[ACTION_NUM];		//体力恢复时间
	INT64		m_Exp;			//经验
	INT32		m_nLangID;		//语言ID
	INT64		m_u64Fight;		//战力
	INT32		m_VipLvl;			//VIP等级
	INT32		m_VipExp;			//VIP经验
	INT32		m_CityCopyID;		//主城副本类型
	BOOL		m_bDelete;        //是否删除
	INT64       m_uQQ;            //QQ号
	UINT64      m_uCreateTime;	  //角色创建时间
	UINT64      m_uLogonTime;	  //本次登录时间
	UINT64      m_uLogoffTime;	  //离线时间

	//签到数据
	INT32		m_nSignNum;        //签到天数
	UINT32		m_nSignDay;        //最新的签到时间
	UINT32		m_RecvAction;	   //领取体力标记

	BOOL Create(IDBInterface* pDB)
	{
		static CDBStoredProcedure csp("REPLACE INTO player (id, account_id, name, carrerid,level, citycopyid,exp, langid, action1, action2, action3,action4, actime1, actime2, actime3,actime4, createtime, logontime, logofftime) \
			VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?);");
		csp.set_uint64(0, m_uRoleID);
		csp.set_uint64(1, m_uAccountID);
		csp.set_string(2, m_szName, strlen(m_szName));
		csp.set_int32(3, m_CarrerID);
		csp.set_int32(4, m_Level);
		csp.set_int64(5, m_CityCopyID);
		csp.set_int64(6, m_Exp);
		csp.set_int32(7, m_nLangID);
		csp.set_int64(8, m_Action[0]);
		csp.set_int64(9, m_Action[1]);
		csp.set_int64(10, m_Action[2]);
		csp.set_int64(11, m_Action[3]);
		csp.set_int64(12, m_Actime[0]);
		csp.set_int64(13, m_Actime[1]);
		csp.set_int64(14, m_Actime[2]);
		csp.set_int64(15, m_Actime[3]);
		csp.set_int64(16, m_uCreateTime);
		csp.set_int64(17, m_uLogonTime);
		csp.set_int64(18, m_uLogoffTime);
		pDB->Execute(&csp);
		return TRUE;
	}

	BOOL Update(IDBInterface* pDB)
	{
		static CDBStoredProcedure csp("REPLACE INTO player (id, account_id, name, carrerid,level, citycopyid,exp, langid, action1, action2, action3,action4, actime1, actime2, actime3,actime4, createtime, logontime, logofftime) \
		VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?);");
		csp.set_uint64(0, m_uRoleID);
		csp.set_uint64(1, m_uAccountID);
		csp.set_string(2, m_szName, strlen(m_szName));
		csp.set_int32(3, m_CarrerID);
		csp.set_int32(4, m_Level);
		csp.set_int64(5, m_CityCopyID);
		csp.set_int64(6, m_Exp);
		csp.set_int32(7, m_nLangID);
		csp.set_int64(8, m_Action[0]);
		csp.set_int64(9, m_Action[1]);
		csp.set_int64(10, m_Action[2]);
		csp.set_int64(11, m_Action[3]);
		csp.set_int64(12, m_Actime[0]);
		csp.set_int64(13, m_Actime[1]);
		csp.set_int64(14, m_Actime[2]);
		csp.set_int64(15, m_Actime[3]);
		csp.set_int64(16, m_uCreateTime);
		csp.set_int64(17, m_uLogonTime);
		csp.set_int64(18, m_uLogoffTime);
		pDB->Execute(&csp);
		return TRUE;
	}

	BOOL Delete(IDBInterface* pDB)
	{
		static CDBStoredProcedure csp("update player set delete = 1 where id = ?");
		csp.set_uint64(0, m_uRoleID);
		pDB->Execute(&csp);

		return TRUE;
	}
};


#endif //__SERVER_STRUCT_H__