# LogHelper
	you need the liblog4cpp,the log4cpp download address:
	http://log4cpp.sourceforge.net/
# init handle
	#define LOGFORMAT "loginit-demo.conf"
	CLogHelper::FormatInit(LOGFORMAT)；
# print log msg
	#define AMODULE "ModuleA"
	LOGRS(AMODULE, LOGLV::LERROR, "Test Error Message!");
	LOGRS(AMODULE, LOGLV::LWARN, "Test Warning Message!");
	LOGRS(AMODULE, LOGLV::LNOTICE, "Test Notice Message!");
	LOGRS(AMODULE, LOGLV::LINFO, "Test Info Message!");
	LOGRS(AMODULE, LOGLV::LDEBUG, "Test Debug Message! %s, %d, %f", "123", 456, 78.9);
