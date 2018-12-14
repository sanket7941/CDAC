#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

extern int exported_number;
void exported_function(void);

static int __init importmod_init(void)
{
	printk(KERN_INFO "%s: import module init.\n", THIS_MODULE->name);
	exported_function();
	printk(KERN_INFO "%s: exported_number = %d.\n", THIS_MODULE->name, exported_number);
	exported_number++;
	return 0;
}

static void __exit importmod_exit(void)
{
	exported_function();
	printk(KERN_INFO "%s: import module exit.\n", THIS_MODULE->name);
}

module_init(importmod_init);
module_exit(importmod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sanket Naik");
MODULE_DESCRIPTION("This module is importing variable & function from exportmod.");
