#ifndef UNION_ERRINFO_H
#define UNION_ERRINFO_H
#include "unionerror.h"

#ifdef __cplusplus
extern "C" {
#endif

struct UnionErrInfo
{
    int ErrNo;
    char *ErrMsg;
    char *ErrDetailInfo;
};

struct UnionErrInfo SKVErrInfo[] = {
    { UNION_OPERATE_SUCCESS, "操作成功", "操作成功" },
    { UNION_ARGU_ERR, "参数错误", "参数错误" },
    { UNION_DATA_FMT_ERR, "输入数据格式错误", "输入数据格式错误" },
    { UNION_DB_CHARACTE_ERR, "数据库编码设置失败", "数据库编码设置失败" },
    { UNION_DB_SYNTAX_ERR, "SQL语法错误", "SQL语法错误" },
    { UNION_DB_TABLE_NOT_EXIST, "数据库表不存在", "数据库表不存在" },
    { UNION_DB_COL_NOT_EXIST, "数据库表列不存在", "数据库表列不存在" },
    { UNION_DB_FOREIGN_KEY_ERR, "无法删除或更新父行，外键约束失败", "无法删除或更新父行，外键约束失败" },
    { UNION_DB_UNIQUE_KEY_ERR, "由于唯一性限制不能写入到表", "由于唯一性限制不能写入到表" },
    { UNION_DB_TABLE_LOCKED, "表已被锁定，不能更新", "表已被锁定，不能更新" },
    { UNION_XML_NODE_NOT_EXIST, "节点名不存在", "节点名不存在" },
    { UNION_XML_NODE_NOT_UNIQUE, "节点名不唯一", "节点名不唯一" },
    { UNION_XML_NODE_INVAILD, "节点名不合法", "节点名不合法" },
    { UNION_XML_ATTRIBUTE_NOT_EXIST, "属性名不存在", "属性名不存在" },
    { UNION_XML_ATTRIBUTE_INVAILD, "属性名不合法", "属性名不合法" },
    { UNION_XML_DATA_INVAILD, "属性数据不合法", "属性数据不合法" },
    { UNION_XML_FILE_NOT_EXIST, "XML文件不存在", "XML文件不存在" },
    { UNION_XML_PARSE_ERR, "XML解析失败", "XML解析失败" },
    { UNION_XML_FILE_CREATE_ERR, "XML文件创建失败", "XML文件创建失败" },
    { UNION_XML_NODE_CREATE_ERR, "XML节点创建失败", "XML节点创建失败" },
    { UNION_XML_PATH_NOT_EXIST, "XML创建时指定文件路径不存在", "XML创建时指定文件路径不存在" },
    { UNION_ARGU_DATA_TYPE_ERR, "输入输出数据类型错误", "输入输出数据类型错误" },
    { UNION_OPER_TYPE_ERR, "未知操作类型", "未知操作类型" },
    { UNION_USER_EXIST, "用户已存在", "用户已存在" },
    { UNION_IP_LIMITED, "用户访问的IP受限", "用户访问的IP受限" },
    { UNION_USER_NO_ORGUNIT, "输入的用户没有组织级别", "输入的用户没有组织级别" },
    { UNION_EVENT_MODULE_NOT_MATCH, "事件模块不匹配", "事件模块不匹配" },
    { UNION_MEM_DEPLETE, "内存申请失败", "内存申请失败" },
    { UNION_PERMIT_DENY, "没有对指定位置的操作权限", "没有对指定位置的操作权限" },
    { UNION_DB_CONN_ERR, "数据库连接失败", "数据库连接失败" },
    { UNION_DB_IP_ERR, "数据库IP错误", "数据库IP错误" },
    { UNION_DB_PORT_ERR, "数据库端口错误", "数据库端口错误" },
    { UNION_DB_USER_PWD_ERR, "数据库用户或密码错误", "数据库用户或密码错误" },
    { UNION_DB_SOCK_ERR, "不能通过SOCK连接到本地MYSQL服务器", "不能通过SOCK连接到本地MYSQL服务器" },
    { UNION_DB_QUERY_ERR, "数据库查询失败", "数据库查询失败" },
    { UNION_DB_QUERY_NULL, "数据库未查询到指定结果集", "数据库未查询到指定结果集" },
    { UNION_DISK_NO_ENOUGH, "磁盘空间不足", "磁盘空间不足" },
    { UNION_OPER_PART_SUCCESS, "部分操作成功", "部分操作成功" },
    { UNION_USER_INVAILD, "输入用户名格式非法", "输入用户名格式非法" },
    { UNION_AUTH_NOT_MATCH, "输入用户认证数据不匹配当前认证类型", "输入用户认证数据不匹配当前认证类型" },
    { UNION_USER_NOT_ACTIVE, "用户未激活", "用户未激活" },
    { UNION_USER_EXPIRED_TIME, "用户已过期", "用户已过期" },
    { UNION_USER_PWD_ERR, "错误的用户名或密码", "错误的用户名或密码" },
    { UNION_PASS_FAILED, "口令认证失败", "口令认证失败" },
    { UNION_USER_NO_EXIST, "用户不存在", "用户不存在" },
    { UNION_ORG_NO_EXIST, "组织不存在", "组织不存在" },
    { UNION_ORG_EXIST, "组织已存在", "组织已存在" },
    { UNION_ORG_LEAST_LEVEL, "不能再添加下级组织", "父组织已经是第八级组织，不能再添加下级组织" },
    { UNION_USER_PERMIT_DENY, "没有对指定组织的操作权限", "没有对指定组织的操作权限" },
    { UNION_ORG_MAX_NUM, "一级组织中组织数达到最大值256个", "一级组织中组织数达到最大值256个" },
    { UNION_USER_PERMIT_DENY, "用户对该操作没有权限", "用户对该操作没有权限" },
    { UNION_ORG_DELETE_DENY, "当前组织存在下级组织不能删除", "当前组织存在下级组织不能删除" },
	{ UNION_MAST_HSMGRP_DELETE_DENY,"主加密机组不能删除","主加密机组不能删除"},
	{ UNION_NO_NEED_PWD,"该操作不需要密码","该操作不需要密码"},
	{ UNION_TASK_LOCKED,"任务被锁定","任务被锁定"},
	{ UNION_TASK_STATUS_ERROR,"执行错误","您没有当前操作的执行权限，如想执行该操作，请修改您的权限"},
	{ UNION_ZMK_CHECK_ERR,"zmk错误","请检查ZMK的密钥值、校验值是否正确 "},
	{ UNION_ZMK_FIND_ERR,"未找到对应ZMK","请检查输入的校验值是否正确"},
	{ UNION_SOCK_LISTEN_ERR,"SOCK监听错误","SOCK监听错误"},
	{ UNION_SOCK_ACCEPT_ERR,"SOCK接收错误","SOCK接收错误"},
	{ UNION_SOCK_WRITE_ERR,"SOCK写错误","SOCK写错误"},
	{ UNION_SOCK_READ_ERR,"SOCK读错误","SOCK读错误"},
	{ UNION_TASK_TERMINAL_NO_EXIST,"终端业务不存在","终端业务不存在"},
	{ UNION_TASK_APPLICATION_NO_EXIST,"应用业务不存在","应用业务不存在"},
	{ UNION_TASK_TERMINAL_USING,"终端业务被占用","终端业务被占用"},
	{ UNION_TASK_APPLICATION_USING,"应用业务被占用","应用业务被占用"},
	{ UNION_TERMINAL_NO_EXIST,"终端设备不存在","终端设备不存在"},
	{ UNION_APPLICATION_NO_EXIST,"应用系统不存在","应用系统不存在"},
	{ UNION_OBJECT_NO_EXIST,"对象类型不存在","对象类型不存在"},
	{ UNION_TASK_STATUS_NO_EXIST,"任务状态值不存在","任务状态值不存在"},
	{ UNION_TASK_NO_EXIST,"任务不存在","任务不存在"},
	{ UNION_APPROVAL_NO_EXIST,"业务审批配置不存在","业务审批配置不存在"},
	{ UNION_SOCK_CONNECT_ERR,"SOCK连接错误","SOCK连接错误"},
	{ UNION_OPER_ALL_FAILURE,"全部操作失败","全部操作失败"},
	{ UNION_EXISTPWD_NOT_APPROPRIATE,"操作成功","存在帐户不符合默认口令策略"},
	{ UNION_KEYVALUE_CKECKVALUE_UNMATCH,"密钥与校验值不匹配","密钥与校验值不匹配"},
	{ UNION_HSM_HSMGRP_MKNOTSAME,"加密机加密机组主密钥不相同","加密机加密机组主密钥不相同"},
	{ UNION_FOREIGN_APPLICATION,"平台删除失败","有应用系统已经关联此平台"},
	{ UNION_HSM_FOREIGN,"加密机组操作失败","有关联此加密机组的加密机"},
	{ UNION_USER_UNDEFINE_ROLE,"用户添加失败","用户未定义角色"},
	{ UNION_PRINTFMT_USED,"打印格式删除失败","已关联加密机/加密机组，请解除关联后再删除"},
	{ UNION_CANNOT_ADD_USER,"添加用户失败","操作员无添加高组织用户的权限"},
	{ UNION_KEY_GEN_ERR,"密钥生成失败","密钥生成失败"},
	{ UNION_BUSINESS_USE_HSM,"加密机删除失败","有业务正在使用该加密机"},
	{ UNION_BUSINESS_FOREIGN_APP,"应用删除失败","有业务已经关联此应用系统"},
	{ UNION_HSM_CONNECT_FAIL,"加密机连接失败","加密机IP或端口配置错误"},
	{ UNION_HSM_MSGLEN_ERR,"加密机消息头长度配置错误","加密机消息头长度配置错误"},
	{ UNION_NO_HAVE_HSM,"生成密钥失败","主加密机组下无可用加密机"},
	{ UNION_USER_DELETE_ERR,"删除用户失败","有业务关联此用户，删除前请取消关联"},
	{ UNION_OPER_PWD_ERR,"操作密码验证失败","操作密码验证失败"},
	{ UNION_DB_INSERT_ERR,"数据库插入失败","数据库插入失败"},
	{ UNION_DB_DELETE_ERR,"数据库删除失败","数据库删除失败"},
	{ UNION_DB_UPDATE_ERR,"数据库更新失败","数据库更新失败"},
	{ UNION_TASK_TERMINAL_EXIST,"终端业务已存在","终端业务已存在"},
	{ UNION_TASK_APPLICATION_EXIST,"应用业务已存在","应用业务已存在"},
	{ UNION_ORG_DELETE_ERR,"组织删除失败","组织删除失败"},
	{ UNION_ROLE_NO_EXIST,"用户角色不存在","用户角色不存在"},
	{ UNION_NTP_CONFIG_ERROR,"更新系统时间失败","请检查ntp服务器是否可用"},
	{ UNION_TASK_OPER_NO_EXIST,"操作不存在","操作不存在"},
	{ UNION_TASK_OPER_EXIST,"操作已存在","操作已存在"},
	{ UNION_REPEAT_OPERATE_ERROR,"操作失败","用户已执行过此操作"},
	{ UNION_KEYVALUE_LENGTH_ERR,"密钥值配置错误","密钥值的长度不合法"},
	{ UNION_KEYTYPE_DELETE_ERR, "密钥类型删除失败","删除失败，默认密钥类型和已关联的密钥类型不允许删除"},
	{ UNION_PERMIT_CHANGE, "操作失败", "当前操作没有权限,当前用户不存在该操作权限或权限已发生变更"},
	{ UNION_KEYTYPE_INSERT_ERR, "密钥类型添加失败", "密钥类型已存在"},
	{ UNION_LICENSE_UNAUTHORIZED, "license未授权", "license未授权，请先授权"},
	{ UNION_LICENSE_APP_OVER_LIMIT, "应用数超限制","应用数受license限制，不允许再添加应用"},
	{ UNION_LICENSE_KEY_OVER_LIMIT, "密钥数超限制", "密钥数受license限制，不允许再生成密钥"},
	{ UNION_LICENSE_TER_OVER_LIMIT,"终端数超限制","终端数受license限制，不允许再添加终端"},

	{ ULERR_NO_PNAME_FILE, "LICENSE文件错误", "无法读取系统名称"},
	{ ULERR_NO_UUID_FILE,  "LICENSE文件错误", "无法读取系统ID"},
	{ ULERR_MAC_GET_IF, "LICENSE文件错误", "无法读取网卡MAC地址列表"},
	{ ULERR_MAC_SOCK, "LICENSE文件错误", "无法创建socket"},
	{ ULERR_MAC_IOCTL, "LICENSE文件错误","无法进行IOCTL操作"},
	{ ULERR_MAC_MAX_NUM, "LICENSE文件错误", "网卡数量超出最大限制"},
	{ ULERR_ANALY_NO_CLEAR_DATA,"LICENSE文件错误", "输入明文license数据为空"},
	{ ULERR_ANALY_FIELD_NUM, "LICENSE文件错误", "license明文数据域个数错误"},
	{ ULERR_ANALY_HWINFO_MAXLEN, "LICENSE文件错误", "license明文数据HWINFO长度错误"},
	{ ULERR_ANALY_ATVTIMES_FORMAT, "LICENSE文件错误","license明文数据激活次数格式错误"},
	{ ULERR_ANALY_AUTHINFO_MAXLEN,"LICENSE文件错误","license明文数据授权信息长度错误"},
	{ ULERR_ANALY_HASH_MAXLEN,"LICENSE文件错误","license明文数据HASH数据长度错误"},
	{ ULERR_ANALY_HASH_CHEK, "LICENSE文件错误", "license明文数据HASH校验不匹配"},
	{ ULERR_NO_LICENSE_FILE, "LICENSE文件错误", "license文件不存在或不能以读方式打开license文件"},
	{ ULERR_LICENSE_FILE_MAXSIZE, "LICENSE文件错误", "license文件大小超出上限"},
	{ ULERR_LICENSE_FILE_WRITE,  "LICENSE文件错误", "不能以写方式打开License文件"},
	{ ULERR_ANALY_NO_ACTIVE_TIMES, "LICENSE文件错误","硬件信息(含激活次数)中缺少激活次数信息"},
	{ ULERR_ANALY_HWINFO_FIELD_NUM, "LICENSE文件错误","硬件信息(含激活次数)中硬件信息域个数错误"},
	{ ULERR_ANALY_HWINFO_PNAME_MAXLEN, "LICENSE文件错误","硬件信息(含激活次数)中硬件信息域个数错误"},
	{ ULERR_ANALY_HWINFO_PUUID_MAXLEN,  "LICENSE文件错误","硬件信息(含激活次数)中硬件信息域个数错误"},
	{ ULERR_ANALY_HWINFO_NOMATCH, "LICENSE文件错误","license明文数据中的HWINFO与设备不匹配"},
	{ UNION_VERSION_CHECK_FAILED, "版本号检测失败", "版本号检测失败"},
	{ UNION_DBVERSION_CHECK_FAILED, "skv版本检测失败", "skv版本检测失败"},
	{ UNION_FSVERSION_CHECK_FAILED, "skv版本检测失败", "skv版本检测失败"},
	{ UNION_DBUPDATE_FAILED, "数据库升级失败", "数据库升级失败" },
	{ UNION_XMLUPDATE_FAILED, "xml升级失败", "xml升级失败" },
	{ UNION_FILE_REPLACE_FAILED, "补丁文件替换失败", "补丁文件替换失败"},
	{ UNION_SELF_SCRIPTE_FAILED, "自定义脚本执行失败", "自定义脚本执行失败"},
	{ UNION_PATCH_DECRYPT_FAILED, "补丁文件解密失败", "补丁文件解密失败"},
	{ UNION_PATCH_UPGRADE_FAILED, "补丁升级失败", "补丁升级失败"},
	{ UNION_CHECK_EXECTIMES_ERR, "工单执行次数超出限制", "工单执行次数超出限制"},
	{ UNION_CODE_OVER_DUE, "验证码已过期", "验证码已过期，请重新申请"},
	{ UNION_FORCE_CHANGE_PASSWORD, "强制用户改密", "用户登录次数已达上限，请改密"},
	{ UNION_USER_LOCKED, "用户被锁定", "密码错误次数达上限，用户被锁定"},
	{ UNION_USER_UNLOCKED, "用户被解锁", "解锁时间到，用户被解锁"},
	{ UNION_USER_NO_APPROVED, "用户注册未审批", "用户注册还未被审批，请联系管理员进行审批"},
	{ UNION_USER_FORBIDDEN, "用户被禁用", "用户已经被管理员禁用"},
	{ UNION_USER_LOGIN_PASSWORD_ERROR, "用户原登录密码错误", "用户原登录密码错误"},
	{ UNION_USER_NEWPWD_OLDPWD_SAME, "用户新密码与旧密码相同", "用户新密码与旧密码相同"},
	{ UNION_ROLE_EXIST, "用户角色已存在", "用户角色已存在"},
	{ UNION_MODULE_EXIST, "模块已存在", "模块已存在"},
	{ UNION_MODULE_NO_EXIST, "模块不存在", "模块不存在"},
	{ UNION_CHECK_EXECTIMES_ERR, "工单执行次数超出限制", "工单执行次数超出限制"},
	{ UNION_ALL_FAILED, "全部失败", "全部失败"},
	{ UNION_PARTIAL_FAILED, "部分成功", "部分成功"},
	{ UNION_CHECK_VALID_ERR, "工单不在有效期内", "工单不在有效期内"},
	{ UNION_CHECK_EXPIRE_ERR, "工单即将过期", "工单即将过期"},
	{ UNION_COMMON_CONN_ERR, "本地服务连接失败", "本地服务连接失败"},
	{ UNION_POLICY_NO_EXIST, "策略不存在", "策略不存在"},
	{ UNION_POLICY_EXIST, "策略已经存在", "策略已经存在"},
	{ UNION_ACCOUNTLEVEL_NO_EXIST, "账户级别不存在", "账户级别不存在"},
	{ UNION_OPERPWD_NO_EXIST, "操作口令配置不存在", "操作口令配置不存在"},
	{ UNION_OPERPWD_EXIST, "操作口令配置已经存在", "操作口令配置已经存在"},
	{ UNION_BUSINESS_NO_EXIST, "业务类型不存在", "业务类型不存在"},
	{ UNION_BUSINESS_EXIST, "业务类型已经存在", "业务类型已经存在"},
	{ UNION_OPERATE_NO_EXIST, "操作类型不存在", "操作类型不存在"},
	{ UNION_OPERATE_EXIST, "操作类型已经存在", "操作类型已经存在"},
	{ UNION_ACCOUNT_INGROUP_NOTNULL, "关联帐户组中帐户不能为空", "关联帐户组中帐户不能为空"},
	{ UNION_EVENT_NO_EXIST, "事件不存在", "事件不存在"},
	{ UNION_EVENT_EXIST, "事件已经存在", "事件已经存在"},
	{ UNION_OPERATIONTYPE_NO_EXIST, "协议运维系统类型不存在", "协议运维系统类型不存在"},
	{ UNION_OPERATIONTYPE_EXIST, "协议运维系统类型已经存在", "协议运维系统类型已经存在"},
	{ UNION_DEVICE_NO_EXIST, "设备不存在", "设备不存在"},
	{ UNION_DEVICE_EXIST, "设备已经存在", "设备已经存在"},
	{ UNION_PROTOCOL_NO_EXIST, "协议不存在", "协议不存在"},
	{ UNION_PROTOCOL_EXIST, "协议已经存在", "协议已经存在"},
	{ UNION_OS_NO_EXIST, "操作系统不存在", "操作系统不存在"},
	{ UNION_OS_EXIST, "操作系统已经存在", "操作系统已经存在"},
	{ UNION_EBOX_CHECK_ERR, "Token校验失败", "Token校验失败"},
	{ UNION_EBOX_CREATE_ERR, "Token生成失败", "Token生成失败"},
	{ UNION_EBOX_EXISTING, "保管箱已存在", "保管箱已存在"},




	{ UWINERR_INVALID_PARAM, "参数错误", "参数错误"},
	{ UWINERR_SOCKET_FAILED, "创建套接字失败", "创建套接字失败"},
	{ UWINERR_ACCESS_DENIED, "权限不足", "权限不足"},
	{ UWINERR_INVALID_COMPUTER, "无效的计算机名", "无效的计算机名"},
	{ UWINERR_NOT_PRIMARY, "非域控制器", "非域控制器"},
	{ UWINERR_GROUP_EXISTS, "用户组已存在", "用户组已存在"},
	{ UWINERR_USER_EXISTS, "用户已存在", "用户已存在"},
	{ UWINERR_PASS_TOO_SHORT, "密码强度不够", "密码强度不够"},
	{ UWINERR_USER_NOT_FOUND, "用户不存在", "用户不存在"},
	{ UWINERR_INVALID_PASS, "密码错误", "密码错误"},
	{ UWINERR_GROUP_NOT_FOUND, "用户组不存在", "用户组不存在"},
	{ UWINERR_NO_SUCH_MEMBER, "用户组中没有该用户", "用户组中没有该用户"},
	{ UWINERR_MEMBER_IN_ALIAS, "成员名重复", "成员名重复"},
	{ UWINERR_INVALID_MEMBER, "成员无效", "成员无效"},
	{ UWINERR_MORE_DATA, "数据未完", "数据未完"},
	{ UWINERR_CONNECT_FAILED, "连接服务器失败", "连接服务器失败"},
	{ UWINERR_READ_SOCKET, "从套接字读取失败", "从套接字读取失败"},
	{ UWINERR_WRITE_SOCKET, "写入套接字失败", "写入套接字失败"},
	{ UWINERR_MALLOC_FAILED, "内存不足", "内存不足"},
	{ UWINERR_LAST_ADMIN, "不能删除最后一个管理员", "不能删除最后一个管理员"},
	{ UWINERR_BAD_PASSWORD, "密码无效", "密码无效"},
	{ UWINERR_UNSUPPORTED_TYPE, "不支持的操作类型", "不支持的操作类型"},
	{ UWINERR_GEN_RAND_PASS_FAILED, "生成随机密码失败", "生成随机密码失败"},
	{ UWINERR_TRUST_FAILED, "托管失败", "托管失败"},
	{ UWINERR_STATUS_FORBIDDEN, "帐户当前状态不允许该操作", "帐户当前状态不允许该操作"},
	{ UWINERR_SMB_INVALID_ARGU, "SMB脚本参数错误", "SMB脚本参数错误"},
	{ UWINERR_SMB_TERMINATE_IN_ADVANCE, "SMB脚本提前退出", "SMB脚本提前退出"},
	{ UWINERR_SMB_TIMEOUT, "SMB脚本执行超时", "SMB脚本执行超时"},
	{ UWINERR_SMB_NEWPASS_MISMATCH, "两次新密码不相同", "两次新密码不相同"},
	{ UWINERR_SMB_LOGON_FAILED, "登录失败", "登录失败"},
	{ UWINERR_SMB_CONNECT_FAILED, "连接失败", "连接失败"},
	{ UWINERR_SMB_ACCESS_DENIED, "权限不足", "权限不足" },
	{ UWINERR_SMB_PASSWORD_RESTRICTION, "密码不符合安全策略", "密码不符合安全策略"},
	{ UWINERR_SMB_GEN_RAND_PASS_FAILED, "生成随机密码失败", "生成随机密码失败"},
	{ UWINERR_SMB_TRUST_FAILED, "托管失败", "托管失败"},
	{ UWINERR_UNKNOWN, "未知错误", "未知错误"},

	{ UODBCERR_ALLOC_ENV_HANDLE, "申请环境句柄失败", "申请环境句柄失败"},
	{ UODBCERR_ALLOC_DBC_HANDLE, "申请数据库连接句柄失败", "申请数据库连接句柄失败"},
	{ UODBCERR_DRIVER_CONNECT, "ODBC连接数据库失败", "ODBC连接数据库失败"},
	{ UODBCERR_ALLOC_STATE_HANDLE, "申请语句句柄失败", "申请语句句柄失败"},
	{ UODBCERR_UNKNOWN_DB_TYPE, "不支持的数据库类型", "不支持的数据库类型"},
	{ UODBCERR_UNKNOWN_OPER_TYPE, "不支持的帐户操作类型", "不支持的帐户操作类型"},
	{ UODBCERR_ODBC_EXEC, "ODBC执行命令出错", "ODBC执行命令出错"},
	{ UODBCERR_INVALID_PARAM, "ODBC参数错误", "ODBC参数错误"},
	{ UODBCERR_GEN_RAND_PASS_FAILED, "生成随机密码失败", "生成随机密码失败"},
	{ UODBCERR_TRUST_FAILED, "托管失败", "托管失败"},
	{ UODBCERR_NO_ADMINISTRATOR, "缺少管理员", "缺少管理员"},
	{ UODBCERR_STATUS_FORBIDDEN, "帐户当前状态不允许该操作", "帐户当前状态不允许该操作"},
	{ UODBCERR_NOT_ADMINISTRATOR, "给定的帐户不是管理员", "给定的帐户不是管理员"},

	{ UNION_GENERATE_EXCEL_FAILED, "生成excel失败", "生成excel失败"},
	{ UNION_WORKNOTE_LOCK_FAILED, "工单禁用失败", "工单禁用失败"},
	{ UNION_WORKNOTE_UNLOCK_FAILED, "工单解除禁用失败", "工单解除禁用失败"},
	{ UNION_REPAIR_CODE_ERR, "抢修码校验失败", "抢修码校验失败"},

	{ USYCERR_CONN_ERR, "连接数据同步服务失败", "连接数据同步服务失败" },
	{ USYCERR_RES_INCOMPLETE, "数据同步服务应答信息不完整", "数据同步服务应答信息缺少errcode属性" },
	{ USYCERR_RES_ATTR_INCPL, "数据同步服务应答信息不完整", "数据同步服务应答信息缺少需要的属性" },
	{ USYCERR_REQ_INCOMPLETE, "数据同步请求信息不完整", "数据同步请求信息节点缺失或属性缺失" },
	{USYCERR_REQ_ATTR_INCPL , "数据同步请求信息不完整", "数据请求信息中缺少需要的属性" },
	{ USYCERR_RAND_LENTH_ERR, "随机数长度错误", "随机数长度错误" },
	{ USYCERR_XMLCREATE_ERR, "无法创建XML数据结构", "无法创建XML数据结构" },
	{ USYCERR_XMLLENTH_MAX, "XML数据长度超限", "XML数据长度超出最大值（64K）" },
	{ USYCERR_INIT_CHKCODE_ERR, "数据同步密钥初始化应答错误", "数据同步密钥初始化，服务端返回了错误的校验码" },
	{ USYCERR_INIT_RANDM_LEN_ERR, "数据同步密钥初始化随机数长度错误", "数据同步密钥初始化，服务端返回的随机数长度错误" },
	{ USYCERR_REQ_UNKNOWN, "数据同步未识别的操作类型", "数据同步，客户端请求的操作类型未知" },
	{ USYCERR_REQ_CHK_ENCLEN, "密钥校验密文长度错误", "密钥校验密文长度错误" },
	{ USYCERR_REQ_CHK_ENCCHK, "密钥校验密文校验值错误", "密钥校验密文校验值错误" },
	{ USYCERR_REQ_INITCLG_ENCCHK, "密钥初始化挑战校验错误", "密钥初始化挑战，校验密文值错误" },
	{ USYCERR_MEM_ALLOC_ERR, "系统资源不足", "没有足够的资源完成请求的操作" },
	{ USYCERR_ACC_CHK_INVALID, "帐户口令校验错误", "帐户口令校验错误" },
	{ USYCERR_ACC_ADD_EXSIT, "帐户已存在", "帐户添加错误，帐户已存在" },
	{ USYCERR_ACC_NO_EXSIT, "帐户不存在", "帐户删除/改密错误，帐户不存在" },
	{ USYCERR_ACC_PSWD_FORMAT, "口令不符合规则", "帐户口令不符合目标资源规则" },
	{ USYCERR_ACC_PSWD_QUERY, "没有查询帐户口令权限", "业务应用查询帐户口令，没有操作权限；请检查工单及帐户状态" },
	{ UNION_ACC_OPER_NOT_CONFIG, "帐户所在资源没有配置服务端口/通信密码", "帐户所在资源没有配置服务端口/通信密码" },
	{ UNION_VCENTER_AUTHMODE_FAILED, "认证方式错误", "未勾选指定的认证方式"},
	{ USYCERR_ACC_APP_CUSTOM, "业务应用自定义的错误类型", "业务应用自定义的错误类型" },
	{ UNION_USER_OVERDUE, "用户已过有效期", "用户已过有效期" },
	{ UNION_DOMAIN_ARGU_ERR, "参数错误", "未配置证书或计算机名" },
    { UNION_USER_CONTRACT_EXPIRED, "用户有效期已过期", "用户有效期已过期"},
	{ UNION_TOKEN_IS_NOT_EXIST , "令牌序列号无效", "指定令牌不存在或令牌未激活"},
	{ UNION_TOKEN_HAS_BINDED, "绑定令牌失败", "令牌已被其他用户使用"},
	{ UNION_BIND_OTHER_TOKEN, "绑定令牌失败", "用户已绑定其他令牌"},
    { UNION_DEL_TOKEN_ERR, "删除令牌失败", "存在用户已绑定该令牌"},
    { UNION_OBJECT_NUM_OVER_LIMIT, "对象个数超限", "对象个数已超出License授权限制"},
    { UNION_OTPS_CONNECT_FAILED, "OTPS连接失败", "OTPS连接失败"},
    { UNION_SEEDFILE_FORMAT_ERROR, "种子文件格式错误", "种子文件格式错误"},
    { UNION_FIRMKEY_NOT_EXIST, "未导入厂商主密钥", "未导入厂商主密钥"},
    { UNION_DYCODECHECK_FAILD, "动态码校验失败", "动态码校验失败"},
    { UNION_OTPS_KEK_NOT_EXIST, "本地未合成传输密钥", "本地未合成传输密钥"},
    { UNION_CSSP_CHECK_FAILD, "CSSP连通性测试失败", "CSSP连通性测试失败"},
	{ UNION_CSSP_KEYNAME_NOT_EXIST, "密钥名不存在", "密钥名不存在"},
	{ UNION_CSSP_CONNECT_FAILED, "CSSP连接失败", "CSSP连接失败"},
	{ UNION_SYSID_OR_APPID_UNDEFINED, "系统ID或应用ID未定义", "系统ID或应用ID未定义"},
	{ UNION_CLIENTIP_NO_AUTHORIZED, "客户端IP未被CSSP授权", "客户端IP未被CSSP授权"},
	{ UNION_DECRYPT_FAILED, "口令解密失败", "口令解密失败"},
	{ UNION_SCAN_RESOURCE_FAILED, "未扫描到新的资源", "未扫描到新的资源"},
	{ UNION_SCAN_VM_PARTIAL_COMPLETE, "VM扫描部分成功", "VM扫描: 部分设备扫描成功"},
	{ UNION_SCAN_VM_ALL_FAILED, "VM扫描失败", "VM扫描: 未扫描到任何设备"},
	{ UNION_RADIUS_CONNECT_FAILED,"Radius认证失败","Radius认证失败"},
	{ UNION_SCAN_VM_UNCONFIG_VCENTER, "配置错误", "未配置业务应用或帐户接口规范选择错误"},
	{ UNION_SCAN_VM_UNCONFIG_ESXI, "配置错误", "只支持ESXI业务应用"},
	{ UNION_SCAN_VM_UNCONFIG_SYNC_PORT, "配置错误", "数据同步端口配置错误"},
	{ UNION_RADIUS_IP_EXIST,"服务器添加失败","服务器IP已存在"},
	{ UNION_RADIUS_UNCHECK_PASSWD, "radius帐户类型不支持口令校验", "radius帐户类型不支持口令校验"},
	{ RADIUS_MYSQL_ACCOUNT_UNIQUE_ERR, "Radius帐户配置唯一性限制错误", "Radius服务器MySQL帐户由于唯一性限制无法写入到表"},
	{ UNION_CREATECERTREQ_ERR,"创建证书请求失败","创建证书请求失败"},
	{ UNION_OPENCERTFILE_ERR, "打开证书文件失败", "打开证书文件失败"},
	{ UNION_READCERTFILE_ERR, "读取证书文件失败", "读取证书文件失败"},
	{ UNION_READKEYFILE_ERR, "读取私钥文件失败", "读取私钥文件失败"},
	{ UNION_X509CHECKPRIVATEKEY_ERR, "证书私钥验证失败", "证书私钥验证失败"},
	{ UNION_DAORU_SERCERT_SUCCESS, "导入服务器证书成功", "重启后生效"},
	{ UNION_ZIQIANFA_SERCERT_SUCCESS, "自签发服务器证书成功","重启后生效"},
	{ UNION_ACTIVE_SUCCESS, "用户导入全部成功", "用户导入全部成功"},
	{ UNION_ACTIVE_SUCCESS, "用户激活码错误", "用户激活码错误"},
	{ UNION_ZIQIANFA_SERCERT_ERR,"自签发服务器证书失败","自签发服务器证书失败"},
	{ UNION_USER_PERMIT_DENY_RW, "操作失败", "当前操作没有权限,当前用户不存在该操作权限或权限已发生变更"},
	{ UNION_FINISHCERTREQ_SUCCESS, "完成证书申请成功","重启后生效"},
	{ UNION_PORT_ADD_ERR, "添加端口失败", "端口添加失败，请重启apache服务后重试"},
	{ UNION_PORT_DEL_ERR, "端口删除失败", "端口删除失败"},
	{ UNION_PORT_ADD_EXIST_ERR, "端口添加失败", "该端口已存在，请重新添加"},
	{ UNION_ACCOUNT_EXCLUSIONDRAW_LIMIT,"帐户排他性领用限制","帐户排他性领用限制" },
	{ UNION_LDAP_CONNECT_FAILED,"LDAP认证失败","LDAP认证失败"},
	{ UNION_AD_CONNECT_FAILED,"密码错误","AD用户密码错误或用户密码已到期"},
	{ UNION_SERVER_CONN_ACCOUNT,"服务器关联其他用户","服务器关联其他用户"},
	{ UNION_AUTH_DEVIDE_OVER_LIMIT,"对象个数超限","授权设备总数超过LICENSE限制"},
	{ UNION_AUTH_NET_DEVICE_OVER_LIMIT,"对象个数超限","授权网络设备总数超过LICENSE限制"},
	{ UNION_AUTH_DB_OVER_LIMIT,"对象个数超限","授权数据库总数超过LICENSE限制"},
	{ UNION_AUTH_APPLY_OVER_LIMIT,"对象个数超限","授权应用总数超过LICENSE限制"},
	{ UNION_AUTH_DB_AND_APPLY_OVER_LIMIT,"对象个数超限","授权数据库和应用总数均超过LICENSE限制"},
	{ UNION_AUTH_DB_AND_APPLY_OVER_LIMIT,"操作系统不能为空","操作系统不能为空"},
	{ UNION_AUTH_DB_AND_APPLY_OVER_LIMIT,"操作系统与SPV不匹配","操作系统与SPV不匹配"},
	{ UNION_ADUSER_NOTEXIT,"服务器上不存在此用户","服务器上不存在此用户"},
	{ UNION_ADUSER_PWDTIMEOUT,"密码错误","AD用户密码错误或用户密码已到期"},
	{ UNION_ADUSER_PWDWILLTIMEOUT,"密码即将到期。","AD用户密码即将到期，请及时更改密码"},
	{ UNION_ADUSER_PWDCHECKFAILED,"原密码校验失败","原密码校验失败，无法进行重置，请联系AD管理员进行重置用户密码"},
	{ UNION_ADUSER_PWDCHANGEFAILED,"用户密码修改失败","用户密码修改失败"},
	{ UNION_ACC_NO_EXIST,"帐户不存在","帐户不存在"},
	{ UNION_ACC_UNAUTH,"帐户未授权","帐户不在授权范围之内"},
	{ UNION_CERT_GEN_ERR,"证书文件生成失败","证书文件生成失败，请更新证书"},
	{ UNION_APPROVAL_CODE_ERR,"离线审批码错误","离线审批码错误"},
	{ UNION_UN_APPROVAL_ERR,"当前工单无此权限","当前工单无此权限"},
	{ UNION_ACC_PARTIAL_UNAUTH,"部分成功","部分帐户不在授权范围之内"},
	{ -1, NULL, NULL },
};

#ifdef __cplusplus
}
#endif

#endif


