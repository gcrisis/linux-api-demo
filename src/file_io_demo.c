#include "main.h"
#include "file_io_demo.h"


/*
 *add new function name string here for display
 *
*/
char * file_io_str[]=
	{
		"open/openat",
		"creat",
		"close",
		"lseek",
		"read",
		"write",
		"dup/dup2",
		"sync/fsync/fdatasync",
		"fcntl",
		"ioctl",
		NULL
	};
	
/*
add new function's demo and source code path here
*/	
DEMO_SHOW file_io_demo_list[] = 
{
	{NULL,NULL},
	{open_demo ,"./src/file_io.c"},
	{creat_demo,"./src/file_io.c"},
	{close_demo,"./src/file_io.c"},
	{lseek_demo ,"./src/file_io.c"},
	{read_demo,"./src/file_io.c"},
	{write_demo,"./src/file_io.c"},
	{dup_demo ,"./src/file_io.c"},
	{sync_demo,"./src/file_io.c"},
	{fcntl_demo,"./src/file_io.c"},
	{ioctl_demo ,"./src/file_io.c"},
	
};

/*
function demo implement
*/
void open_demo(void)
{
	printf("this is open demo\n");
}

void creat_demo(void)
{
	printf("this is creat demo\n");
}
void close_demo(void)
{
	printf("this is close demo\n");
}
void lseek_demo(void)
{
	printf("this is open demo\n");
}

void read_demo(void)
{
	printf("this is creat demo\n");
}
void write_demo(void)
{
	printf("this is close demo\n");
}
void dup_demo(void)
{
	printf("this is open demo\n");
}

void sync_demo(void)
{
	printf("this is creat demo\n");
}
void fcntl_demo(void)
{
	printf("this is close demo\n");
}
void ioctl_demo(void)
{
	printf("this is close demo\n");
}
