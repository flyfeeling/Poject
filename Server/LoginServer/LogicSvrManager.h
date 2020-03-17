﻿#ifndef _LOGIC_SEVER_MANAGERH_
#define _LOGIC_SEVER_MANAGERH_
#include "ServerEngine.h"
#include "DBInterface/CppMysql.h"
enum EServerStatue
{
	ESS_NONE		= 0,//未知
	ESS_GOOD		= 1,//流畅
	ESS_BUSY		= 2,//拥挤
	ESS_MAINTAIN	= 3,//维护
	ESS_SHUTDOWN	= 4,//关闭
	ESS_REVIEW		= 5,//评审
};

struct LogicServerNode
{
	LogicServerNode()
	{
		m_dwConnID		= 0;
		m_dwServerID	= 0;
		m_dwPort		= 0;
		m_dwHttpPort	= 0;
		m_dwWatchPort	= 0;
		m_Statue		= ESS_GOOD;
		m_Flag			= 0;
		m_bDelete		= FALSE;
		m_uLastUpdate	= 0;
	}

	BOOL CheckIP(UINT32 dwIPaddr);

	BOOL CheckChannel(UINT32 dwChannel);

	BOOL CheckVersion(std::string strVersion);

	UINT32		m_dwConnID;		//连接ID
	UINT32		m_dwServerID;	//服务器ID
	UINT32		m_dwPort;		//游戏端口号
	UINT32      m_dwHttpPort;	//http端口
	UINT32      m_dwWatchPort;	//监视端口
	UINT32		m_Statue;		//服务器状态
	UINT32		m_Flag;			//服务器标记
	UINT32		m_dwMinVersion; //最小可见版本
	UINT32		m_dwMaxVersion; //最大可见版本
	std::string m_strSvrName;	//服务器名字
	std::string m_strIpAddr;	//服务器IP地址
	UINT64		m_uLastUpdate;	//服务器最后更新时间

	std::set<UINT32> m_CheckIpList;	  //过滤的IP地址
	std::set<INT32>       m_CheckChannelList; //可以看见的渠道

	BOOL		m_bDelete;
};

class LogicSvrManager : public std::map<UINT32, LogicServerNode*>
{
public:
	LogicSvrManager(void);
	~LogicSvrManager(void);

public:
	BOOL	Init();

	BOOL	Uninit();

	BOOL	RegisterLogicServer(UINT32 dwConnID, UINT32 dwServerID, UINT32 dwPort, UINT32 dwHttpPort, UINT32 dwWatchPort, const std::string& strSvrName);

	BOOL	UnregisterLogicServer(UINT32 dwConnID, UINT32 dwServerID);

	BOOL	IsReviewVersion(std::string strClientVersion);

	BOOL	ReloadServerList(UINT32 dwServerID = 0);

	BOOL	ReloadReviewVersion();

	UINT32	GetLogicConnID(UINT32 dwServerID);

	LogicServerNode* GetRecommendServerInfo();

	LogicServerNode* GetLogicServerInfo(UINT32 dwServerID);

public:
	UINT32 m_dwRecommendSvrID;

	std::set<std::string> m_setReviewVersion;

	CppMySQL3DB 		m_DBConnection;
};

#endif //_LOGIC_SEVER_MANAGERH_