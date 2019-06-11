#ifndef __PROCESS_CONTROL_DEMO_H
#define __PROCESS_CONTROL_DEMO_H


extern char * process_control_str[];
extern DEMO_SHOW process_control_demo_list[];


void fork_demo(void);
void exit_demo();
void wait_demo();
void exec_demo();
void nice_demo();
void times_demo();
#endif
