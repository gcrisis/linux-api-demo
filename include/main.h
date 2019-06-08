#ifndef __MAIN_H
#define __MAIN_H

#include "apue.h"

typedef void (*f)(void);

typedef struct content {
	char **str;
	struct content * up;
	struct content * (*handle)(int index);
}CONTENT;

typedef struct demo_show{
	f demo;
	char *path;
}DEMO_SHOW;

void show_source_code(char * str);



#endif
