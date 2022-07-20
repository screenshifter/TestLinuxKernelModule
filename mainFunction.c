#include "mainFunction.h"

#include <linux/kernel.h>
#include <linux/module.h>
//#include <stdbool.h>
#include "timedLogOutput.h"


void mainFunction(void)
{
	char testMessage[] = "Its'a me, Mario!";

	pr_info("This is main function, this message is from another file\r\n");
	
	if(timedLogOutput_printMessages(10, testMessage))
		pr_info("%s: failed\r\n", "timedLogOutput_printMessages");

	return;
}

