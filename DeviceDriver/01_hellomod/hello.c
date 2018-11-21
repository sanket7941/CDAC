#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

// module init -- entrypoint
int __init init_module(void)
{
	// module init code
	
	// print some statement into the kernel log -- /var/log/messages -- dmesg
	printk("Hello, Linux Kernel!\n");
	
	// return 0 for successful loading/initializing of module
	// return -ve value for error
	return 0;
}

// module exit -- entrypoint
void __exit cleanup_module(void)
{
	// module de-init code
	
	// print some statement into the kernel log -- /var/log/messages -- dmesg
	printk("Bye, Linux Kernel!\n");
}

MODULE_INFO(license, "GPL");
MODULE_INFO(author, "Nilesh Ghule<nilesh@sunbeaminfo.com>");
MODULE_INFO(description, "Hello kernel module developed for DESD Aug 2018 batch at Sunbeam Infotech, Pune");



