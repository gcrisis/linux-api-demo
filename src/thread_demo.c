#include "main.h"
#include "thread_demo.h"
#include <pthread.h>

       
char * thread_str[]=
	{
		"pthread_create",
		"pthread_exit/pthread_join",
		"pthread_cancel",
		"pthread_cleanup_push/pthread_cleanup_pop",
		"pthread_detach",
		"pthread_mutex_init/pthread_mutex_destroy",
		"pthread_mutex_lock/pthread_mutex_trylock/pthread_mutex_unlock/pthread_mutex_timedlock",
		"pthread_rwlock_init/pthread_rwlock_destroy",
		"pthread_rwlock_rdlock/pthread_rwlock_wrlock/pthread_rwlock_unlock",
		NULL
	};
DEMO_SHOW thread_demo_list[]=
	{
		{NULL,NULL},
		{pthread_create_demo,""},
		{pthread_exit_demo,""},
		{pthread_cancel_demo,""},
		{NULL,""},
		{NULL,""},
		{pthread_mutex_demo,""},
	};
	
void * thr1(void * a)
{
		pthread_t thr;
	thr = pthread_self();
	printf("pid = %d \nthis is child thread %lx\n",getpid(),thr);
	
	return ((void *)0);
}
void pthread_create_demo()
{
	pthread_t thr_child;
	pthread_t thr_fath;
	pthread_create(&thr_child,NULL,thr1,NULL);
	thr_fath = pthread_self();
	printf("pid = %d \nthis is fath thread %lx\n",getpid(),thr_fath);
	sleep(1);
}

void * fn1(void *arg)
{
	printf("thread 1 return\n");
	return((void *)1);
}
void * fn2(void *arg)
{
	printf("thread 2 exit\n");
	pthread_exit((void *)2);
}
void pthread_exit_demo()
{
	pthread_t thr_child[2];
	void * tret;
	pthread_create(&thr_child[0],NULL,fn1,NULL);
	pthread_create(&thr_child[1],NULL,fn2,NULL);
	
	pthread_join(thr_child[0],&tret); /*get thread return status*/
	printf("thread 1 return %p\n",tret);
	pthread_join(thr_child[1],&tret);
	printf("thread 2 return %p\n",tret);
}

void pthread_cancel_demo()
{
	
}
void pthread_mutex_demo()
{
	
}
