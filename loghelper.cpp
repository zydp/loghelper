#include <iostream> 
#include <sstream>
#include "loghelper.h"
#include <log4cpp/Category.hh>
#include <log4cpp/PropertyConfigurator.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Layout.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/Export.hh>
#include <stdarg.h>
using namespace log4cpp;

#define PROCESS_CATEGORY "process"

bool CLogHelper::FormatInit(const char* confile)
{
	try
	{
		log4cpp::PropertyConfigurator::configure(confile);
		return true;
	}
	catch (log4cpp::ConfigureFailure& f)
	{
		std::cout << "Configure Problem " << f.what() << std::endl;
		return false;
	}
	catch (...) {
		std::cout << "Configure read failure " << std::endl;
		return false;
	}
}

void CLogHelper::RecordLog(const std::string& file, const int& line, const std::string module, const LOGLV& level, const std::string &message)
{
	Category& process = Category::getInstance(PROCESS_CATEGORY);

	std::ostringstream oss;
	oss << "[" << module << "] " << file << ":" << line << "\t[message]: " << message;

	switch (level)
	{
	case LOGLV::LERROR:
		process.error(oss.str());
		break;
	case LOGLV::LWARN:
		process.warn(oss.str());
		break;
	case LOGLV::LNOTICE:
		process.notice(oss.str());
		break;
	case LOGLV::LINFO:
		process.info(oss.str());
		break;
	case LOGLV::LDEBUG:
	default:
		process.debug(oss.str());
		break;
	}
}

void CLogHelper::RecordLogWithArgs(const std::string& file, const int& line, const std::string module, const LOGLV& level, const std::string &format, ...)
{
	Category& process = Category::getInstance(PROCESS_CATEGORY);
	char logMsg[LOG_BUF_SIZE] = { 0 };
	std::ostringstream oss;
	oss << "[" << module << "] " << file << ":" << line << "\t[message]: ";
	va_list argvs;
	va_start(argvs, format);
#ifdef WIN32 
	vsnprintf_s(logMsg, LOG_BUF_SIZE, format.c_str(), argvs);
#else
	vsnprintf(logMsg, LOG_BUF_SIZE, format.c_str(), argvs);
#endif
	va_end(argvs);
	oss << logMsg;
	switch (level)
	{
	case LOGLV::LERROR:
		process.error(oss.str());
		break;
	case LOGLV::LWARN:
		process.warn(oss.str());
		break;
	case LOGLV::LNOTICE:
		process.notice(oss.str());
		break;
	case LOGLV::LINFO:
		process.info(oss.str());
		break;
	case LOGLV::LDEBUG:
	default:
		process.debug(oss.str());
		break;
	}
}
