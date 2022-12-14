#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("Dual BSD/GPL");

static int __init	hello_init(void)
{
	printk(KERN_ALERT "Hello, world\n");
	printk(KERN_ALERT "The process is \"%s\" (pid %i)\n", current->comm, current->pid);
	
	return 0;
}

static void __exit	hello_exit(void)
{
	printk(KERN_ALERT "Goodbye, cruel world\n");
}
module_init(hello_init);
module_exit(hello_exit);