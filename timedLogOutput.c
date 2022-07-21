#include "timedLogOutput.h"

#include <linux/timer.h>


static const uint32_t _timerJiffiesPerSecond = 250;


static struct timer_list _timer;
static uint64_t _timerMessageCounter = 0;


static void timerCallback(struct timer_list *timer);
static bool messageQueue(void);


bool timedLogOutput_printMessages(int amount, char *message)
{
	timer_setup(&_timer, timerCallback, 0);

	_timerMessageCounter = amount;
	return messageQueue();
}


static void timerCallback(struct timer_list *timer)
{
	pr_info("Kernel timer expired\r\n");
	
	if(messageQueue() == false)
		pr_info("%s: all messages are printed\r\n", __func__);
	
	return;
}


static bool messageQueue(void)
{
	if(_timerMessageCounter > 0)
	{
		mod_timer(&_timer, jiffies + _timerJiffiesPerSecond / 4);
		_timerMessageCounter--;
		return true;
	}
	else
		return false;
}
