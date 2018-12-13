#include<linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <asm/uaccess.h>

#define LEN 512
static char buf[LEN];

static int major=250,minor;
static dev_t dev;
static struct cdev cdev;
static struct class *pclass;

static int pchar_open(struct inode *pinode,struct file *pfile)
{
  printk(KERN_INFO "%s: pchar_open() called.\n", THIS_MODULE->name);
  return 0;
}
static int pchar_close(struct inode *pinode, struct file *pfile)
{
	// nothing
	printk(KERN_INFO "%s: pchar_close() called.\n", THIS_MODULE->name);
	return 0;
}

static ssize_t pchar_write(struct file *pfile, const char __user *ubuf, size_t len,loff_t *poffset)
{
  int max_bytes,bytes_to_write,nbytes;
	printk(KERN_INFO "%s: pchar_write() called : buf len = %lu.\n", THIS_MODULE->name, len);
  max_bytes = LEN - *poffset;
  bytes_to_write =len <max_bytes ? len : max_bytes;
  if(bytes_to_write <=0)
  {
    printk(KERN_INFO "%s: pchar_write() - no space avail on device buffer.\n", THIS_MODULE->name);
    return -ENOSPC;
  }
  nbytes = bytes_to_write - copy_from_user(buf + *poffset, ubuf,bytes_to_write);
  *poffset += nbytes;
  return nbytes;
}

static ssize_t pchar_read(struct file *pfile, char __user *ubuf, size_t len, loff_t *poffset)
{
	// copy data from device buf to user buf
	int max_bytes, bytes_to_read, nbytes;
	printk(KERN_INFO "%s: pchar_read() called.\n", THIS_MODULE->name);
	max_bytes = LEN - *poffset;
	bytes_to_read = len < max_bytes ? len : max_bytes;
	nbytes = bytes_to_read - copy_to_user(ubuf, buf+*poffset, bytes_to_read);
	*poffset += nbytes;
	return nbytes;
}

static loff_t pchar_lseek(struct file *pfile, loff_t offset, int origin)
{
	loff_t newpos = 0;
	printk(KERN_INFO "%s: pchar_lseek() called.\n", THIS_MODULE->name);
	switch(origin)
	{
	case SEEK_SET:
		newpos = 0 + offset;
		break;
	case SEEK_CUR:
		newpos = pfile->f_pos + offset;
		break;
	case SEEK_END:
		newpos = LEN + offset;
		break;
	}
	if(newpos < 0 || newpos > LEN)
		return -EINVAL;
	pfile->f_pos = newpos;
	return newpos;
}
static struct file_operations pchar_fops = {
	.owner = THIS_MODULE,
	.open = pchar_open,
	.release = pchar_close,
	.read = pchar_read,
	.write = pchar_write,
	.llseek = pchar_lseek
};
static int __init pchar_init(void)
{
  int ret ,err,i;
  struct device *pdevice;
  	printk(KERN_INFO "%s: pchar_init() called.\n", THIS_MODULE->name);
    dev = MKDEV(major,0);
    ret= alloc_chrdev_region(&dev,0,1,"pchar");
    if(ret < 0)
    {
  		printk(KERN_INFO "%s: alloc_chrdev_region() failed.\n", THIS_MODULE->name);
  		err = -1;
  		goto alloc_chrdev_region_failed;
  	}
    major = MAJOR(dev);
    minor = MINOR(dev);
    printk(KERN_INFO "%s: alloc_chrdev_region() success:dev num =(%d,%d).\n",THIS_MODULE->name,major,minor);
    pclass = class_create(THIS_MODULE, "pchar_class"); // --> /sys/classes/
  	if(pclass == NULL)
  	{
  		printk(KERN_INFO "%s: class_create() failed.\n", THIS_MODULE->name);
  		err = -1;
  		goto class_create_failed;
  	}
  	printk(KERN_INFO "%s: class_create() success.\n", THIS_MODULE->name);

  	i = 0;
  	pdevice = device_create(pclass, NULL, dev, NULL, "pchar%d", i); // --> /dev/
  	if(pdevice == NULL)
  	{
  		printk(KERN_INFO "%s: device_create() failed.\n", THIS_MODULE->name);
  		err = -1;
  		goto device_create_failed;
  	}
  	printk(KERN_INFO "%s: device_create() success.\n", THIS_MODULE->name);

  	// init cdev struct & add into kernel
  	cdev_init(&cdev, &pchar_fops);
  	ret = cdev_add(&cdev, dev, 1);
  	if(ret < 0)
  	{
  		printk(KERN_INFO "%s: cdev_add() failed.\n", THIS_MODULE->name);
  		err = -1;
  		goto cdev_add_failed;
  	}
  	printk(KERN_INFO "%s: cdev_add() success.\n", THIS_MODULE->name);

  	memset(buf, 0, LEN);

  	printk(KERN_INFO "%s: pchar_init() done.\n", THIS_MODULE->name);
  	return 0;

  cdev_add_failed:
  	device_destroy(pclass, dev);
  device_create_failed:
  	class_destroy(pclass);
  class_create_failed:
  	unregister_chrdev_region(dev, 1);
  alloc_chrdev_region_failed:
  	return err;
}
static void __exit pchar_exit(void)
{
	printk(KERN_INFO "%s: pchar_exit() called.\n", THIS_MODULE->name);

	// delete cdev struct from kernel
	cdev_del(&cdev);

	// destroy device class & device file
	device_destroy(pclass, dev);
	class_destroy(pclass);

	// deallocate major & minor numbers of device
	unregister_chrdev_region(dev, 1);
}

module_init(pchar_init);
module_exit(pchar_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("SankeAt www.nustaSankat.com>");
MODULE_DESCRIPTION("Pseudo char device driver");
