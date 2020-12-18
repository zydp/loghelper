#ifndef _LOG_HELPER_H_
#define _LOG_HELPER_H_
#include <iostream>
//The log buf size
#define LOG_BUF_SIZE 4096

// The log level
enum class loglevel
{
	LERROR,		// 错误
	LWARN,		// 警告
	LNOTICE,	// 通知
	LINFO,		// 相关信息
	LDEBUG,		// 调式信息
};
using LOGLV = loglevel;
class CLogHelper
{
public:
	static bool FormatInit(const char* confile);
	static void RecordLog(const std::string& file, const int& line, const std::string module, const LOGLV& level, const std::string &message);
	static void RecordLogWithArgs(const std::string& file, const int& line, const std::string module, const LOGLV& level, const std::string &format, ...);
private:
	CLogHelper(){};
	~CLogHelper(){};
};


//#define LOGRQ(module, loglv, message) CLogHelper::RecordLog(__FILE__, __LINE__, module, loglv, message)
#define LOGRS(module, loglv, format, ...) CLogHelper::RecordLogWithArgs(__FILE__, __LINE__, module, loglv, format, ##__VA_ARGS__)




#endif
