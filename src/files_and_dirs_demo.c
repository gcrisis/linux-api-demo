#include "main.h"
#include"files_and_dirs_demo.h"

char * files_and_directorys_str[]=
	{
		"stat/fstat/fstatat/lstat",
		"access/faccessat",
		"umask",
		"chmod/fchmod/fchmodat",
		"chown/fchown/fchownat/lchown",
		"link/linkat/unlink/unlinkat/remove",
		"rename/renameat",
		NULL
	};
DEMO_SHOW files_and_dirs_demo_list[]=
	{
		{NULL,NULL},
	};
