DROP DATABASE IF EXISTS `db_log`;
CREATE DATABASE IF NOT EXISTS `db_log` ;


use db_log;

-- ----------------------------
-- Table structure for accountcreate
-- ----------------------------
DROP TABLE IF EXISTS `accountcreate`;
CREATE TABLE `accountcreate` (
  `accountid` varchar(50) DEFAULT NULL COMMENT '帐号',
  `channel` varchar(50) DEFAULT NULL COMMENT '平台ID',
  `optime` datetime DEFAULT NULL COMMENT '创建帐号时间',
  `model` varchar(50) DEFAULT NULL COMMENT '机型',
  `mei` varchar(50) DEFAULT NULL,
  `mac` varchar(50) DEFAULT NULL,
  `ip` varchar(50) DEFAULT NULL,
  `openid` varchar(50) DEFAULT NULL,
  UNIQUE KEY `account_index` (`accountid`) USING BTREE,
  KEY `operation_time_index` (`optime`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Table structure for accountlogin
-- ----------------------------
DROP TABLE IF EXISTS `accountlogin`;
CREATE TABLE `accountlogin` (
  `account_id` bigint(20) NOT NULL COMMENT '帐号ID',
  `channel` int(20) NOT NULL COMMENT '平台ID',
  `version` char(20) NOT NULL COMMENT '版本ID',
  `optime` datetime NOT NULL COMMENT '登出时间',
  `login_ip` char(50) NOT NULL COMMENT '登入IP',
  `mac_address` char(50) NOT NULL COMMENT '登入设备MAC地址',
  `device_uuid` char(50) NOT NULL COMMENT '登入设备UUID',
  `idfa` char(50) DEFAULT NULL,
  `networktype` char(20) DEFAULT NULL,
  `imei` varchar(50) DEFAULT NULL,
  `imodel` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;



