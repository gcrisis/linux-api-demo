#ifndef __THREAD_DEMO_H
#define __THREAD_DEMO_H


extern char * thread_str[];
extern DEMO_SHOW thread_demo_list[];

void pthread_create_demo();
void pthread_exit_demo();
void pthread_cancel_demo();
void pthread_mutex_demo();

#endif
