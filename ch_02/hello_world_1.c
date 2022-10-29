#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("Dual BSD/GPL");

static int __init	hello_init(void)
{
	printk(KERN_ALERT "Hello, world\n");
	printk(KERN_ALERT "The process is \"%s\" (pid %i)\n", current->comm, current->pid);
	
	int err;
	
	/* регистрация использует указатель и имя */
	err = register_this(ptr1, "skull");
	if (err)
		goto fail_this;
	err = register_that(ptr2, "skull");
	if (err)
		goto fail_that;
	err = register_those(ptr3, "skull");
	if (err)
		goto fail_those;

	return 0;

	fail_those: unregister_that(ptr2, "skull");
	fail_that: unregister_this(ptr1, "skull");
	fail_this: return err; /* передать ошибку для наследования */
}

static void __exit	hello_exit(void)
{
	printk(KERN_ALERT "Goodbye, cruel world\n");

	unregister_those(ptr3, "skull");
	unregister_that(ptr2, "skull");
	unregister_this(ptr1, "skull");
	return;
}
module_init(hello_init);
module_exit(hello_exit);