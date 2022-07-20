#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include "mainFunction.h"


MODULE_LICENSE("MIT");
MODULE_AUTHOR("Screenshifter");
MODULE_DESCRIPTION("Hehe, Linux Kernel Module, live with this now");


#define _INITDATA_BUFFERSIZE	256


static char __initdata inputParameters[_INITDATA_BUFFERSIZE];


module_param_string(TestInput, inputParameters, _INITDATA_BUFFERSIZE, 0);
MODULE_PARM_DESC(TestInput, "Parameters list, it takes any string and outputs it");


static int __init initModule(void)
{
	pr_info("Test module started\r\n");
	pr_info("%s\r\n", inputParameters);
	
	mainFunction();
	
	return 0;
}


module_init(initModule);

