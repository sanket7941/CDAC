#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

// module init -- entrypoint
static int __init desd_init(void)
{
	// module init code
	
	// print some statement into the kernel log -- /var/log/messages -- dmesg
	printk(KERN_INFO "%s: Hello, Linux Kernel!\n", THIS_MODULE->name);
	
	// return 0 for successful loading/initializing of module
	// return -ve value for error
	return 0;
}

// module exit -- entrypoint
static void __exit desd_exit(void)
{
	// module de-init code
	
	// print some statement into the kernel log -- /var/log/messages -- dmesg
	printk(KERN_INFO "%s: Bye, Linux Kernel!\n", THIS_MODULE->name);
}

module_init(desd_init);
module_exit(desd_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("SANKET NAIK");
MODULE_DESCRIPTION("basic code for device driver ");



