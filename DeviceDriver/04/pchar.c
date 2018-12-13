#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h> // filesystem
#include <linux/cdev.h> // cdev
#include <linux/device.h>
#include <linux/slab.h> // Kmalloc
#include <linux/moduleparam.h> // to change any module in run time
#include <asm/uaccess.h>

#define LEN 512

typedef struct pchar
{
  char buf[LEN]; //actual char device
  dev_t dev; // device number (major + minor)
  struct cdev cdev; // char device struct
}pchar_t;

static int major=250,minor;
static struct class *pclass; // char device class pointer
/* creates entry in /sys/class/ folder */
static pchar_t *devices= NULL;
static int devcnt =2; // no. of instance creates
module_param(devcnt,int,0600);

static int pchar_open(struct inode *pinode,struct file *pfile)
{
  pchar_t *priv = container_of(pinode->i_cdev, pchar_t,cdev);
  pfile->private_data = priv;
  printk(KERN_INFO " %s : pchar_open() called forpchar %ld.\n",THIS_MODULE->name,priv-devices);
  return 0;
}


static int __init pchar_init(void)
{
	int ret , err , i;
	struct device *pdevice;
	dev_t dev;
	printk(KERN_INFO "%s: pchar_init() called.\n",THIS_MODULE->name);
	/* allocate major and minor number for device */
	dev = MKDEV(major,0);
	ret = alloc_chrdev_region(&dev,0,devcnt,"pchar");/* allocate mem in --> /proc/device location */
	if(ret < 0)
	{
		printk(KERN_INFO"%s: alloc_chrdev_region() failed.\n",THIS_MODULE->name);
		err = -1;
		goto alloc_chardev_region_faild;
	}

	major = MAJOR(dev);
	minor = MINOR(dev);
	printk(KERN_INFO "%s: alloc_chrdev_region() success: dev number = (%d,%d).\n", THIS_MODULE->name, major, minor);
	/* Create Device class & device file*/
	pclass = class_create(THIS_MODULE,"pchar_class"); /* --> sys/class/  */
	if (pclass == NULL);
	{
		printk(KERN_INFO "%s: class_create() failed.\n", THIS_MODULE->name);
		err = -1;
		goto class_create_failed;
	}

	printk(KERN_INFO "%s: class_create() success.\n", THIS_MODULE->name);

	for(i=0; i<devcnt ; i++)
	{
		dev = MKDEV(major,i);
		pdevice = device_create(pclass ,NULL,dev,NULL,"pchar%d",i);
		if(pdevice == NULL)
		{
			printk(KERN_INFO "%s: device_create() failed for pchar%d.\n", THIS_MODULE->name, i);
			err = -1;
			goto device_create_failed;
		}
		printk(KERN_INFO "%s: device_create() success for pchar%d.\n", THIS_MODULE->name, i);
	}

	//alloc memory of device private struct
	devices = (pchar_t*) kmalloc(devcnt * sizeof(pchar_t),GFP_KERNEL);
	if(devices == NULL)
	{
		err = -ENOMEM;
		printk(KERN_INFO "%s: kmalloc() failed.\n", THIS_MODULE->name);
				goto kmalloc_failed;
	}
	printk(KERN_INFO "%s: kmalloc() success for device structs.\n", THIS_MODULE->name);

	/* init cdev struct & add into kernel  */

	for (i =0 ;i<devcnt;i++)
	{
		cdev_init(&devices[i].cdev,&pchar_fops);
		devices[i].dev = MKDEV(major,i);
		ret cdev_add(&devices[i].cdev, devices[i].dev,1);
		if(ret < 0)
		{
			printk(KERN_INFO "%s: cdev_add() failed for pchar%d.\n", THIS_MODULE->name, i);
			err = -1;
			goto cdev_add_failed;
		}
		printk(KERN_INFO "%s: cdev_add() success for pchar%d.\n", THIS_MODULE->name, i);
		memset(devices[i].buf,o,LEN);
	}
	printk(KERN_INFO "%s: pchar_init() done.\n", THIS_MODULE->name);
	return 0;

cdev_add_failed:
	for(i=i-1;i>=0;i--)
		cdev_del(&devices[i].cdev);
	kfree(devices);
kmalloc_failed:
	i = devcnt;
device_create_failed:
	for(i=i-1; i>=0; i--)
	{
		dev = MKDEV(major, i);
		device_destroy(pclass, dev);
	}
	class_destroy(pclass);
class_create_failed:
	dev = MKDEV(major, 0);
	unregister_chrdev_region(dev, devcnt);
alloc_chrdev_region_failed:
	return err;
}

static void __exit pchar_exit(void)
{
	int i;
	dev_t dev;
	printk(KERN_INFO "%s: pchar_exit() called.\n",THIS_MODULE->name);
	/* deleate cdev struct from kernel*/
	for(i=devcnt-1;i>=0; i--)
	{	cdev_del(&devices[i].cdev);	}
	// release memory of device private structs
	 	kfree(devices);

	// destroy device class & device file
		for(i=devcnt-1; i>=0; i--)
		{
			dev = MKDEV(major, i);
			device_destroy(pclass, dev);
		}
		class_destroy(pclass);

		// deallocate major & minor numbers of device
		dev = MKDEV(major, 0);
		unregister_chrdev_region(dev, devcnt);
}
module_init(pchar_init);
module_exit(pchar_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sanket Naik");
MODULE_DESCRIPTION("Pseudo char device driver");
