#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

int exported_number = 123;

void exported_function(void)
{
	printk(KERN_INFO "%s: exported function called.\n", THIS_MODULE->name);
	printk(KERN_INFO "%s: exported number = %d.\n", THIS_MODULE->name, exported_number);
}

static int __init exportmod_init(void)
{
	printk(KERN_INFO "%s: export module init.\n", THIS_MODULE->name);
	return 0;
}

static void __exit exportmod_exit(void)
{
	printk(KERN_INFO "%s: export module exit.\n", THIS_MODULE->name);
}

EXPORT_SYMBOL(exported_function);
EXPORT_SYMBOL(exported_number);

module_init(exportmod_init);
module_exit(exportmod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sanket Naik");
MODULE_DESCRIPTION("This module is exporting a variable & a function.");
