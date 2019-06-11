#include "main.h"
#include<errno.h>
#include<fcntl.h>
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
struct str_value_t{
	char * str;
	int    value;
};

struct str_value_t open_flag[] = 
	{
		{"O_RDONLY"		,00000000},
		{"O_WRONLY"		,00000001},
		{"O_RDWR"		,00000002},
		{"O_CREAT"		,00000100},
		{"O_EXCL"		,00000200},
		{"O_NOCTTY"		,00000400},
		{"O_TRUNC"		,00001000},
		{"O_APPEND"		,00002000},
		{"O_NONBLOCK"	,00004000},
		{"O_DSYNC"		,00010000},
		{"FASYNC"		,00020000},
		{"O_DIRECT"		,00040000},
		{"O_LARGEFILE"	,00100000},
		{"O_DIRECTORY"	,00200000},
		{"O_NOFOLLOW"	,00400000},
		{"O_NOATIME"	,01000000},
		{"O_CLOEXEC"	,02000000},
		{NULL,0}
	};
struct str_value_t open_mode[]=
	{
		{"S_IRWXU",00700},
		{"S_IRUSR",00400},
		{"S_IWUSR",00200},
		{"S_IXUSR",00100},
		{"S_IRWXG",00070},
		{"S_IRGRP",00040},
		{"S_IWGRP",00020},
		{"S_IXGRP",00010},
		{"S_IRWXO",00007},
		{"S_IROTH",00004},
		{"S_IWOTH",00002},
		{"S_IXOTH",00001},
		{"S_ISUID",0004000},
		{"S_ISGID",0002000},
		{"S_ISVTX",0001000},
		{NULL,0}
	};
int get_split_str(char * str,char * delim,char * strp[])
{
	char * saveptr;
	int index=0;
	strp[index] = strtok_r(str,delim,&saveptr);
	while(strp[index]!=NULL)
	{
		index++;
		strp[index] = strtok_r(NULL,delim,&saveptr);
	}
	return index;
}

/*
	extract bit params like a|b|c to a int param
*/
int params_str2int(char * str,struct str_value_t *str_value)
{
	char * tempp;	
	int param=0;
	tempp = strtok(str,"|");
	while(tempp != NULL)
	{
		int i=0;
		while(str_value[i].str !=NULL)
		{
			if(!strcmp(str_value[i].str,tempp))
			{
				param |= str_value[i].value;
				break;
			}
			i++;
		}
		tempp = strtok(NULL,"|");
	}
	return param;
}
void open_demo(void)
{
	char params_str[MAXLINE];
	char * paramsp[20];
	int index=0;
	int fd;
	char * param1;
	int  param2 = 0;
	mode_t param3 = 0;
	printf("this is open demo\n");
	printf("Prototype:\n"
			"int open(const char *pathname, int flags);\n"
			"int open(const char *pathname, int flags, mode_t mode);\n");
	printf("Input params :");

	while(fgets(params_str,MAXLINE,stdin)!=NULL)
	{
		params_str[strlen(params_str)-1] = '\0';
		index = get_split_str(params_str," ",paramsp);	
		if(index<2||index>3)
		{
			printf("wrong param count,try again");
		}
		else
		{
			break;
		}
	}
	param1 = paramsp[0];
	param2 = params_str2int(paramsp[1],open_flag);

	if(index == 3)
	{
		param3 = params_str2int(paramsp[2],open_mode);
		printf("params:%s 0x%x 0x%x\n",param1,param2,param3);
		fd = open(param1,param2,param3);
	}
	else
	{
		printf("params:%s 0x%x\n",param1,param2);
		fd = open(param1,param2);
	}
	if(fd<0)
	{
		printf("open %s failed, fd = %d error = %s\n",param1,fd,strerror(errno));
	}
	else
	{
		printf("open %s success,fd = %d status = %x\n",param1,fd,fcntl(fd,F_GETFL,0));
	}
	
	close(fd);
	return;	
}

void creat_demo(void)
{
	char params_str[MAXLINE];
	char * paramsp[20];
	int index=0;
	int fd;
	char * param1;
	int  param2 = 0;
	printf("this is creat demo\n");
	printf("Prototype:\n"
			"int creat(const char *pathname, mode_t mode);\n");
	printf("Input params :");
	while(fgets(params_str,MAXLINE,stdin)!=NULL)
	{
		params_str[strlen(params_str)-1] = '\0';
		index = get_split_str(params_str," ",paramsp);	
		if(index!=2)
		{
			printf("wrong param count,try again:");
		}
		else
		{
			break;
		}
	}
	
	param1 = paramsp[0];
	param2 = params_str2int(paramsp[1],open_mode);
	printf("params:%s 0x%x\n",param1,param2);
	fd = creat(param1,param2);
	if(fd<0)
	{
		printf("creat %s failed,fd = %d error = %s\n",param1,fd, strerror(errno));
	}
	else
	{
		printf("creat %s success,fd = %d status = %x\n",param1,fd,fcntl(fd,F_GETFL,0));
	}
	close(fd);
	return;	
}
void close_demo(void)
{
	int fd;
	printf("this is close demo\n");
	printf("Prototype:\n"
			"int close(int fd);\n");
	printf("open a file to get fd for test\n");
	fd = open("./README.md",open_flag[0].value);
	printf("fd = %d\n",fd);
	fd = close(fd);
	if(fd<0)
	{
		printf("close file failed,fd = %d error = %s\n",fd,strerror(errno));
	}
	else
	{
		printf("close file success,fd = %d\n",fd);
	}
	
}

struct str_value_t lseek_whence[]=
	{
		{"SEEK_SET",0},
		{"SEEK_CUR",1},
		{"SEEK_END",2},
		{NULL,0}
	};

void lseek_demo(void)
{
	char params_str[MAXLINE];
	char * paramsp[20];
	int index=0;
	int fd;
	int param1;
	off_t param2 = 0;
	int param3 =0;
	off_t ret_value;
	
	printf("this is lseek demo\n");
	printf("Prototype:\n"
			"off_t lseek(int fd, off_t offset, int whence);\n");
	printf("open a file to get fd for test\n");
	fd = open("./README.md",open_flag[0].value);
	printf("fd = %d\n",fd);
	printf("Input other params :");
	
	while(fgets(params_str,MAXLINE,stdin)!=NULL)
	{
		params_str[strlen(params_str)-1] = '\0';
		index = get_split_str(params_str," ",paramsp);	
		if(index!=2)
		{
			printf("wrong param count,try again:");
		}
		else
		{
			break;
		}
	}
	
	param1 = fd;
	param2 = atoi(paramsp[0]);
	param3 = params_str2int(paramsp[1],lseek_whence);
	printf("params:%d %ld %d\n",param1,param2,param3);
	
	ret_value = lseek(param1,param2,param3);
	
	if(ret_value<0)
	{
		printf("lseek failed,ret_value = %ld error = %s\n",ret_value,strerror(errno));
	}
	else
	{
		printf("lseek file success,ret_value = %ld\n",ret_value);
	}
	close(fd);
}

void read_demo(void)
{
	char params_str[MAXLINE];
	int fd;
	int param1;
	char param2[MAXLINE];
	size_t param3 =0;
	ssize_t ret_value;
	
	printf("this is read demo\n");
	printf("Prototype:\n"
			"ssize_t read(int fd, void *buf, size_t count);\n");
	printf("open a file to get fd for test\n");
	fd = open("./README.md",open_flag[0].value);
	printf("fd = %d\n",fd);
	printf("buf is param2[%d],param2 = %p\n",MAXLINE,param2);
	printf("Input other params :");
	
	fgets(params_str,MAXLINE,stdin);
	param1 = fd;
	param3 = atoi(params_str);
	printf("params:%d %p %ld\n",param1,param2,param3);
	ret_value = read(param1,param2,param3);
	
	if(ret_value<0)
	{
		printf("read failed,ret_value = %ld error = %s\n",ret_value,strerror(errno));
	}
	else
	{
		printf("read file success,ret_value = %ld,read info:\"%s\"\n",ret_value,param2);
	}
	
	close(fd);
	
}
void write_demo(void)
{
	printf("this is write demo\n");
	
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
