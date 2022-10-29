#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/stat.h>

static int howmany = 2;
static char *whom = "world";
module_param(howmany, int, S_IRUGO);
module_param(whom, charp, S_IRUGO);

MODULE_LICENSE("Dual BSD/GPL");

static int __init	hello_init(void)
{
	for(int i = 0; i < howmany; ++i)
		printk(KERN_ALERT "Hello, %s\n", whom);
	printk(KERN_ALERT "The process is \"%s\" (pid %i)\n", current->comm, current->pid);
	
	return 0;
}

static void __exit	hello_exit(void)
{
	printk(KERN_ALERT "Goodbye, cruel world\n");
}
module_init(hello_init);
module_exit(hello_exit);