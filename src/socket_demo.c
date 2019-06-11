/*the header has order,if one use something defined
 *in other headers,these headers must #include before 
 *who use it
 */

#include "main.h"
#include "socket_demo.h"
/*
 *add new function name string here for display
 *
*/
char * socket_str[]=
	{
		"socket",
		NULL
	};
	
/*
add new function's demo and source code path here
*/	
DEMO_SHOW socket_demo_list[] = 
{
	{NULL,NULL},	
	{socket_infc_demo,""}
};

void socket_infc_demo()
{}
