#include "timedLogOutput.h"

#include <linux/string.h>
#include <linux/timer.h>


static const uint32_t _timerJiffiesPerSecond = 250;


static struct timer_list _timer;
static uint64_t _timerMessageCounter = 0;
static char _message[256];


static void timerCallback(struct timer_list *timer);
static bool messageQueue(void);


bool timedLogOutput_printMessages(int amount, char *message)
{
	timer_setup(&_timer, timerCallback, 0);

	if(strlen(message) > sizeof(_message))
	{
		pr_info("%s: message is too large, restriction is %u bytes\r\n", __func__, sizeof(_message));
		strcpy(_message, "Kernel timer expired");
	}
	else
	{
		strcpy(_message, message);
	}

	_timerMessageCounter = amount;
	return messageQueue();
}


static void timerCallback(struct timer_list *timer)
{
	pr_info("%s: %s\r\n", __func__, _message);
	
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
