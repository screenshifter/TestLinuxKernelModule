#include "timedLogOutput.h"

#include <linux/timer.h>


static const uint32_t _timerJiffiesPerSecond = 250;


static struct timer_list _timer;
static uint64_t _timerMessageCounter = 0;


static void timer_callback(struct timer_list *timer);


int timedLogOutput_printMessages(int amount, char *message)
{
	timer_setup(&_timer, timer_callback, 0);

	_timerMessageCounter = amount;
	mod_timer(&_timer, jiffies + _timerJiffiesPerSecond / 4);

	return 0;
}


static void timer_callback(struct timer_list *timer)
{
	pr_info("Kernel timer expired\r\n");
	
	if(_timerMessageCounter == 0)
	{
		pr_info("%s: all messages are printed", __func__);
		return;
	}

	_timerMessageCounter--;
	mod_timer(&_timer, jiffies + _timerJiffiesPerSecond / 4);
	
	return;
}
