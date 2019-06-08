#include <getopt.h>
#include <dirent.h>
#include "main.h"
#include "file_io_demo.h"
#include "files_and_dirs_demo.h"
#include "process_control_demo.h"
#include "std_io_demo.h"
#include "signal_demo.h"
#include "thread_demo.h"


char * main_content_str[]=
	{
		"file i/o",
		"file and directories",
		"stand i/o library",
		"process control",
		"signal",
		"thread",
		NULL
	};

char * function_child_content[]=
	{
		"show demo",
		"source code",
		NULL
	};
	
CONTENT *main_content_handle(int index);
CONTENT *file_io_content_handle(int index);
CONTENT *files_and_dirs_content_handle(int index);
CONTENT *std_io_content_handle(int index);
CONTENT *process_control_content_handle(int index);
CONTENT *signal_content_handle(int index);
CONTENT *thread_content_handle(int index);
CONTENT *child_content_handle(int index);


CONTENT main_content = {main_content_str,&main_content,main_content_handle};

CONTENT second_contents[] = 
	{
		{NULL,NULL,NULL},
		{file_io_str               	,&main_content,file_io_content_handle },
		{files_and_directorys_str  	,&main_content,files_and_dirs_content_handle},
		{standard_io_lib_str        ,&main_content,std_io_content_handle},
		{process_control_str       	,&main_content,process_control_content_handle},
		{signal_str                	,&main_content,signal_content_handle},
		{thread_str       			,&main_content,thread_content_handle},		
	};
	
static void usage()
{
  fprintf(stderr,"Type \"linux-api-demo %s\" for help.\n", "--help");
  exit(1);
}
/* Give some help information */
static void helpthem(void)
{

  printf(
    "Usage: linux-api-demo [OPTION]... [configuration]\n"
    "A linux api test program for Linux and other unix-like systems .\n\n"
    "  -h, --help             : show this help information\n"
    "  -v, --version          : output version information and exit\n");
}
	
static int print_content(char * str[])
{
	int i=0;

	while(str[i]!=NULL)
	{
		printf("\t%d.%s\n",i+1,str[i]);
		i++;
	}
	if(str == main_content.str)
	{
		printf("[1-%d]:",i);
	}
	else
	{
		printf("[1-%d,b back]:",i);	
	}
	return i;
}

CONTENT * main_content_handle(int index)
{
	return &second_contents[index];
}

CONTENT temp;
DEMO_SHOW *p;

CONTENT *third_content_handle(int index)
{
	switch(index)
	{
		case 1:
			p->demo();
			break;
		case 2:
			show_source_code(p->path);
	}
	return &temp;
}

CONTENT * file_io_content_handle(int index)
{
	p = &file_io_demo_list[index];
	temp.str =  function_child_content;
	temp.up = NULL;
	temp.handle = third_content_handle;	
	return &temp;
}
CONTENT * files_and_dirs_content_handle(int index)
{
	p = &files_and_dirs_demo_list[index];
	temp.str =  function_child_content;
	temp.up = NULL;
	temp.handle = third_content_handle;	
	return &temp;
}
CONTENT * std_io_content_handle(int index)
{
	p = &std_io_demo_list[index];
	temp.str =  function_child_content;
	temp.up = NULL;
	temp.handle = third_content_handle;	
	return &temp;
}
CONTENT * process_control_content_handle(int index)
{
	p = &process_control_demo_list[index];
	temp.str =  function_child_content;
	temp.up = NULL;
	temp.handle = third_content_handle;	
	return &temp;
}
CONTENT * signal_content_handle(int index)
{
	p = &signal_demo_list[index];
	temp.str =  function_child_content;
	temp.up = NULL;
	temp.handle = third_content_handle;	
	return &temp;
}
CONTENT * thread_content_handle(int index)
{
	p = &thread_demo_list[index];
	temp.str =  function_child_content;
	temp.up = NULL;
	temp.handle = third_content_handle;	
	return &temp;
}


void show_source_code(char * str)
{
	char cmd[20];
	int exist = access(str,F_OK);
	if(!exist)
	{
		sprintf(cmd,"%s %s","vim",str);
		system(cmd);
	}
	else
	{
		printf("Not found source code %s\n",str);
	}
}

int main(int argc ,char * argv[])
{
	int c;
	char buf[MAXLINE];
	char *args[20];		/* New argv pointer */
  	int argk = 1;			/* New argc */
  	
	static struct option long_options[] =
	{
		{ "help",          no_argument,       NULL, 'h' },
		{ "ptty",          required_argument, NULL, 'p' },
		{ "version",       no_argument,       NULL, 'v' },
		{ NULL, 0, NULL, 0 }
	};
	
	printf("Linux API DEMO\n\n");
	
	args[0] = "linux-api-demo";
	  /* Add command - line options */
  	for(c = 1; c < argc && argk < 19; c++)
    	args[argk++] = argv[c];
  	args[argk] = NULL;
  	
  	do
  	{
		while ((c = getopt_long(argk, args, "vh",
		                        long_options, NULL)) != EOF)
			switch(c) {
			case 'v':
				printf("%s version %s", "linux-api", "1.0.0");
				#ifdef __DATE__
				printf(" (compiled %s)", __DATE__);
				#endif
				printf("\n");
				printf("Copyright (C) Miquel van Smoorenburg.\n\n");
				printf("This program is free software; you can redistribute it and/or\n"
					 "modify it under the terms of the GNU General Public License\n"
						 "as published by the Free Software Foundation; either version\n"
						 "2 of the License, or (at your option) any later version.\n\n");
				exit(1);
			  break;
			  case 'h':
		      	helpthem();
		      	exit(1);
		      break;
		      default:
		     	 usage();
		      break;

			}
	/* Loop again if more options */
	}while (optind < argk);
	
	/*display content	*/
	CONTENT * contentp=NULL;
	contentp = &main_content;
	int index_cnt = print_content(contentp->str);
	
	while(fgets(buf,MAXLINE,stdin)!=NULL)
	{
		if(buf[0]=='b')
		{
			contentp = contentp->up;
			index_cnt = print_content(contentp->str);
		}
		else
		{
			int index = atoi(buf);
			if(index>0&&index<=index_cnt)
			{
				CONTENT *temp = contentp->handle(index);
				if(temp != contentp)
				{
					temp->up = contentp;
					contentp = temp;
				}
				index_cnt = print_content(contentp->str);
			}
			else
			{
				printf("Invalid input index,Try again:");
			}
		}
		
	}
	
	return 0;
}
