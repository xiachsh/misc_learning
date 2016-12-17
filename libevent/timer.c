#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


#include <event2/event_struct.h>
#include <event.h>

/*
 *void (*)(int,  short int,  void *)
 */
void cb_print(int sock,short event ,void *argv)
{
	printf ("FILE:%s LINE:%d\n",__FILE__,__LINE__);
	struct timeval tv;
	tv.tv_sec = 1 ;
	tv.tv_usec = 0;
	event_add((struct event *) argv,&tv);
}


int main()
{
	event_init();
	struct event evTimer;

	evtimer_set(&evTimer,cb_print,&evTimer);

	struct timeval tv;

	tv.tv_sec = 1;
	tv.tv_usec = 0 ;

	event_add(&evTimer,&tv);

	event_dispatch();


	return 0;


}
