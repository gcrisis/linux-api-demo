#include "main.h"

char * signal_str[]=
	{
		"signal",
		"kill/raise",
		"alarm/pause",
		"sigemptyset/sigfillset/sigaddset/sigdelset/sigismember",
		"sigprocmask",
		"sigpending",
		"sigaction",
		"sigsetjmp/siglongjmp",
		"sigsuspend",
		"abort",
		"sigqueue",
		NULL
	};
DEMO_SHOW signal_demo_list[]=
	{
		{NULL,NULL},
	};
