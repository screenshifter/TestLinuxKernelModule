#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>


MODULE_LICENSE("MIT");


static void __exit exitModule(void)
{
	pr_info("Test module finished!\r\n");
}


module_exit(exitModule);

