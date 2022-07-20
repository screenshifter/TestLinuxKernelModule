#include "timedLogOutput.h"

#include <linux/timer.h>

static struct timer_list _timer;


static void timer_callback(struct timer_list *timer);


int timedLogOutput_printMessages(int amount, char *message)
{
	timer_setup(&_timer, timer_callback, 0);
	
	// Segmentation fault somewhere here
	
	//mod_timer(&_timer, 100);
	//add_timer(&_timer);

	return 0;
}


static void timer_callback(struct timer_list *timer)
{
	pr_info("Kernel timer expired\r\n");
}
