#include "main.h"

char * process_control_str[]=
	{
		"fork/vfork",
		"exit",
		"wait/waitpid/waitid/wait3/wait4",
		"exec",
		"getpriority/setpriority",
		"times",
		NULL
	};
DEMO_SHOW process_control_demo_list[]=
	{
		{NULL,NULL},
	};
