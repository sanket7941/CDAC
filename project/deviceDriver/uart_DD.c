#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/kref.h>
#include <linux/uaccess.h>
#include <linux/usb.h>
#include <linux/mutex.h>


/****************** defines  *********************/
#define MIN(a,b) (((a) <=(b)) ? (a):(b))

#define BULK_EP_OUT 0x08
#define BULK_EP_IN 0x82
#define MAX_PKT_SIZE 64
#define USB_MINOR_BASE	192 /* Get a minor range for your devices from the usb maintainer */
#define MAX_TRANSFER		(PAGE_SIZE - 512)
#define to_usb_uart_dev(d) container_of(d, struct usb_uart,kref)

#define USB_SPI_VENDOR_ID 0xffff
#define USB_SPI_PRODUCT_ID 0x0004

unsigned char buf[64];

/* ID table */
static struct usb_device_id uart_table[]=
{
	{  USB_DEVICE(USB_SPI_VENDOR_ID,USB_SPI_PRODUCT_ID) },
	{} //terminating entry
};

// static struct uart_driver (uart_driver);

/* Structure to hold all of our device specific st uff */
struct usb_uart
{
	struct usb_device	    *udev;			/* the usb device for this device */
	struct usb_interface	*interface;		/* the interface for this device */
  struct kref		         kref;  /*jernel reference */

  unsigned char *bulk_in_buffer;	/* the buffer to receive data */
	size_t			   bulk_in_size;		/* the size of the receive buffer */
	// size_t			bulk_in_filled;		/* number of bytes in the buffer */
	// size_t			bulk_in_copied;		/* already copied to user space */

  __u8    bulk_in_endpointAddr;	/* the address of the bulk in endpoint */
	__u8		bulk_out_endpointAddr;	/* the address of the bulk out endpoint */
	int			errors;			/* the last request tanked */
};

static struct usb_driver uart_driver;

static void usb_delete(struct kref *kref)
{
	struct usb_uart *dev = to_usb_uart_dev(kref);
	usb_put_dev(dev->udev);
	kfree(dev->bulk_in_buffer);
	kfree(dev);
}

/*  */
static int uart_open(struct inode *inode,struct file *file)
{
	struct usb_uart *dev;  /*device information*/
	struct usb_interface *interface;
	int subminor;
	int retval = 0;

	printk("open() called.....:)\n");

	subminor = iminor(inode);

	interface = usb_find_interface(&uart_driver, subminor);
	printk("open() 1 .....\n");
	if(!interface){
		printk("can not find minor for device....\n");
		retval = -ENODEV;
		goto error;
	}
	printk("open() 2 .......\n");
	dev = usb_get_intfdata(interface);
	if(!dev){
		retval = -ENODEV;
		goto error;
	}
	printk("open()3.....:)\n");
	kref_get(&dev->kref);
		/*to save our object in the file private structure*/
	file->private_data = dev;
	printk("open() succeed....:)\n");
error:
	return retval;
}

/*  */
static int uart_close(struct inode *inode,struct file *file)
{
	struct usb_uart *dev;

	dev = file->private_data;
	if(dev == NULL)
		return -ENODEV;
	kref_put(&dev->kref, usb_delete);
	return 0;
}

/*  */
static ssize_t uart_read(struct file *file,char __user *buffer,size_t count,loff_t *off)
{
  int retval;
	int cnt;
	struct usb_uart *dev;
	dev = file->private_data;
	printk("read () called... \n");
		/*read data from bulk endpoint*/
		retval = usb_bulk_msg(dev->udev,usb_rcvbulkpipe(dev->udev,dev->bulk_in_endpointAddr),dev->bulk_in_buffer,MIN(count,dev->bulk_in_size),&cnt,5000);
		/*if read was successful,copy the data to the user sapce*/

		printk("read() 1...\n");
		if(!retval)
		{
			if(copy_to_user(buffer,dev->bulk_in_buffer,MIN(cnt,count))){
				retval = -EFAULT;
			}
			else{
				retval = count;
			}
		}
		printk("read suceed ...: \n");
		return MIN(count,cnt);
}


static ssize_t uart_write(struct file *file,const char *user_buffer,size_t count,loff_t *off)
{
	int retval;
	int cnt = MIN(cnt, MAX_TRANSFER);

	struct usb_uart *dev;

	dev= file->private_data;

	printk("write() called....:)\n");

		if(copy_from_user(dev->bulk_in_buffer,user_buffer,MIN(cnt,MAX_TRANSFER)))
		{
			return -EFAULT;
		}

		/*write data into  bulk endpoint*/
		printk("write() 1 ...\n");
		retval = usb_bulk_msg(dev->udev,
			 					usb_sndbulkpipe(dev->udev,dev->bulk_out_endpointAddr),
								dev->bulk_in_buffer,
								MIN(count,MAX_TRANSFER),
								&cnt,5000);

		printk("write() 2 ......\n");
		if(retval)
		{
			printk("BULK message returned \n");
			return retval;
		}

		printk("write() succeed.......:)\n");

		return cnt;
}

/*  */
static struct file_operations uart_fops =
  {
    .owner   = THIS_MODULE,
  	.open    = uart_open,
  	.release = uart_close,
  	.read    = uart_read,
  	.write   = uart_write,
  };

	static struct usb_class_driver uart_class = {
		.name =		"uart%d",
		.fops =		&uart_fops,
		.minor_base =	USB_MINOR_BASE,
	};


	/* (probe) device ditection */
	static int uart_probe(struct usb_interface *interface, const struct usb_device_id *id)
	{
		struct usb_uart *dev;
		struct usb_host_interface *iface_desc;
		struct usb_endpoint_descriptor* endpoint;//, *bulk_in, *bulk_out;
		size_t buffer_size;
		int retval = -ENOMEM;
		int i;

		printk("Skeleton  now alloted");
		/* allocate memory for our device state and initialize it */
		dev = kzalloc(sizeof(*dev), GFP_KERNEL);
		if (!dev)
			return -ENOMEM;

		kref_init(&dev->kref);

		dev->udev = usb_get_dev(interface_to_usbdev(interface)); //inc ref cnt of usb dev structure
		dev->interface = interface;

		/* set up the endpoint information */
		/* use only the first bulk-in and bulk-out endpoints */
		/* retval = usb_find_common_endpoints(interface->cur_altsetting,&bulk_in, &bulk_out, NULL, NULL);
		if (retval)
		{
			dev_err(&interface->dev,
				"Could not find both bulk-in and bulk-out endpoints\n");
			goto error;
		}*/
		iface_desc = interface->cur_altsetting;
		for (i = 0; i < iface_desc->desc.bNumEndpoints;i++)
		{
			endpoint = &iface_desc->endpoint[i].desc;

			if (!dev->bulk_in_endpointAddr &&
					usb_endpoint_is_bulk_in(endpoint))
					{
						buffer_size = usb_endpoint_maxp(endpoint);
						dev->bulk_in_size = buffer_size;
						dev->bulk_in_endpointAddr = endpoint->bEndpointAddress;
						dev->bulk_in_buffer = kmalloc(dev->bulk_in_size, GFP_KERNEL);
							if (!dev->bulk_in_buffer) {
								retval = -ENOMEM;
								goto error;
							}
					}

			if (!dev->bulk_out_endpointAddr &&
					usb_endpoint_is_bulk_out(endpoint)){
						dev->bulk_out_endpointAddr = endpoint->bEndpointAddress;
					}
			}

			if (!(dev->bulk_in_endpointAddr && dev->bulk_out_endpointAddr)) {
				dev_err(&interface->dev,
						"Could not find both bulk-in and bulk-out endpoints\n");
				goto error;
			}

		/* save our data pointer in this interface device */
		usb_set_intfdata(interface, dev);

		/* we can register the device now, as it is ready */
		retval = usb_register_dev(interface, &uart_class);
		if (retval) {
			/* something prevented us from registering this driver */
			dev_err(&interface->dev,"Not able to get a minor for this device.\n");
			usb_set_intfdata(interface, NULL);
			goto error;
		}

		/* let the user know what node this device is now attached to */
		dev_info(&interface->dev,"USB uart device now attached to USBSkel-%d",
			 interface->minor);
		return retval;

	error:
		/* this frees allocated memory */
		if(dev)
			kref_put(&dev->kref,usb_delete);
		return retval;
	}

	/* divice disconnect  */
	static void uart_disconnect(struct usb_interface *interface)
	{
	    struct usb_uart *dev;
	    int minor = interface->minor;
			printk(KERN_INFO"usb uart now disconnected");
	    /* prevent skel_open( ) from racing skel_disconnect( ) */

	    dev = usb_get_intfdata(interface);
	    usb_set_intfdata(interface, NULL);
	    /* give back our minor */
	    usb_deregister_dev(interface, &uart_class);

	    /* decrement our usage count */

			kref_put(&dev->kref,usb_delete);
			dev_info(&interface->dev,"USB Skeleton #%d now disconnected", minor);
	}

	static struct usb_driver uart_driver =
	  {
	  	// .owner=THIS_MODULE,
	    .name    =  "uart_driver",
	    .id_table=  uart_table,
	    .probe   =  uart_probe,
	    .disconnect=uart_disconnect,
	  };

void module_uart_driver( uart_driver);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("sanket<sanketn7941@gmail.com");
MODULE_DESCRIPTION("this is USB_Device Driver Module for  BBonboard uart");
