#include "timedLogOutput.h"

#include <linux/timer.h>

static struct timer_list _timer;
static uint64_t _timerMessageCounter = 0;


static void timer_callback(struct timer_list *timer);


int timedLogOutput_printMessages(int amount, char *message)
{
	timer_setup(&_timer, timer_callback, 0);

	_timerMessageCounter = amount;
	
	add_timer(&_timer);
	mod_timer(&_timer, 100);

	return 0;
}


static void timer_callback(struct timer_list *timer)
{
	pr_info("Kernel timer expired\r\n");

	if(_timerMessageCounter > 0)
		_timerMessageCounter--;
		
	if(_timerMessageCounter > 0)
		add_timer(timer);

	return;
}
