# LogHelper

# using it like this
# init handle
	CLogHelper::read_config_init("loginit-demo.conf");
# print log msg
	PROCESS_LOG("test",LERROR,"Test Error Message!");
	PROCESS_LOG("test",LWARN,"Test Warning Message!");
	PROCESS_LOG("test",LNOTICE,"Test Notice Message!");
	PROCESS_LOG("test",LINFO,"Test Info Message!");
	PROCESS_LOG("test",LDEBUG,"Test Debug Message!");
