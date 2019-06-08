#include "main.h"

       
char * thread_str[]=
	{
		"pthread_create",
		"pthread_exit",
		"pthread_join",
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
	};
