#include "mainFunction.h"

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
#include "timedLogOutput.h"


void mainFunction(void)
{
	char testMessage[] = "Its'a me, Mario!";

	pr_info("Main function started\r\n");
	
	pr_info("Message output test\r\n");
	if(timedLogOutput_printMessages(3, testMessage) == false)
		pr_info("%s: failed\r\n", "timedLogOutput_printMessages");

	return;
}

