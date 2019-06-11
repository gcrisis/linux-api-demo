#include "main.h"
#include "process_control_demo.h"
#include <sys/wait.h>
#include <pwd.h>
#include <sys/resource.h>
#include <sys/times.h>

char * process_control_str[]=
	{
		"fork/vfork",
		"exit",
		"wait/waitpid/waitid/wait3/wait4",
		"exec",
		"nice/getpriority/setpriority",
		"times",
		NULL
	};
DEMO_SHOW process_control_demo_list[]=
	{
		{NULL,NULL},
		{fork_demo,""},
		{exit_demo,""},
		{wait_demo,""},
		{exec_demo,""},
		{nice_demo,""},
		{times_demo,""},
	};

int global_a = 10;	
void fork_demo(void)
{
	int a = 10;
	pid_t pid;
	pid = fork();
	if(pid == 0 )
	{
		global_a = 20;
		a = 20;
		printf("this is child process global_a = %d a=%d,\n",global_a,a);
		printf("pid = %d ppid = %d uid = %d euid = %d gid = %d egid = %d\n",
				getpid(),getppid(),getuid(),geteuid(),getgid(),getegid());
		
		pid = fork();
		if(pid == 0)
		{
			printf("wait father process exit\n");
			sleep(1);
			printf("this is child child process global_a = %d a=%d,\n",global_a,a);
			printf("pid = %d ppid = %d uid = %d euid = %d gid = %d egid = %d\n",
				getpid(),getppid(),getuid(),geteuid(),getgid(),getegid());
			printf("login %s\n",getlogin());
		}		
		exit(0);
	}
	else
	{
		sleep(2);
		printf("this is father process global_a = %d a=%d,\n",global_a,a);
		printf("pid = %d ppid = %d uid = %d euid = %d gid = %d egid = %d\n",
				getpid(),getppid(),getuid(),geteuid(),getgid(),getegid());
		char * name = getlogin();
		printf("login %s\n",name);
		struct passwd *pwd;
		pwd = getpwnam(name);
		printf("%s %s %d %d %s %s %s\n",pwd->pw_name,pwd->pw_passwd,pwd->pw_uid,pwd->pw_gid,
										pwd->pw_gecos,pwd->pw_dir,pwd->pw_shell);
		
	}
}
void exit_demo()
{}

void wait_demo()
{
	pid_t pid[4];
	int i;
	int statloc;
	
	for(i=0;i<4;i++)
	{
		pid[i] = fork();
		if(pid[i] ==0)
		{
			printf("this is child %d\n",getpid());
			sleep(i);
			switch(i)
			{
				case 0:
					exit(0);
					break;
				case 1:
					exit(7);
					break;
				case 2:
					abort();
					break;
				case 3:
					statloc/=0;
					break;
			}
	
		}
	}
	pid_t ret_pid;
	ret_pid = waitpid(pid[2],&statloc,0);
	printf("waitpid get child %d exit\n",ret_pid);
	printf("exit status %d\n",statloc);
	pr_exit(statloc);
	while(1)
	{
		ret_pid = wait(&statloc);
		if(ret_pid == -1)
			break;
		printf("wait get child %d exit\n",ret_pid);
		printf("exit status %d\n",statloc);
		pr_exit(statloc);
	}
}
void exec_demo()
{}

void nice_demo()
{
	int a;
	a = nice(0);
	printf("nice = %d nzero = %d \n",a,_SC_NZERO);
	a = getpriority(PRIO_PROCESS,0);
	printf("proi = %d\n",a);
	setpriority(PRIO_PROCESS,0,2);
	a = nice(0);
	printf("nice = %d nzero = %d \n",a,_SC_NZERO);
}
void times_demo()
{
	clock_t sclock,eclock;
	struct tms s,e;
	sclock = times(&s);
		sleep(1);
	eclock = times(&e);

	printf("clock = %ld time:%ld %ld %ld %ld\n",sclock/sysconf(_SC_CLK_TCK),s.tms_utime,s.tms_stime,s.tms_cutime,s.tms_cstime);
	printf("clock = %ld time:%ld %ld %ld %ld\n",eclock/sysconf(_SC_CLK_TCK),e.tms_utime,e.tms_stime,e.tms_cutime,e.tms_cstime);
}


