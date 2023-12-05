#include <linux/types.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/delay.h>
void *ptr = NULL;
static int noinline test_init(void)
{
   ptr = kmalloc(8*1024, GFP_KERNEL);
   if (ptr == NULL) {
	printk("kmalloc memory failed\n");
	return -1;
   }
   return 0;
}

static int __init test_init_module(void)
{
  return test_init();
}

static void noinline test_exit(void)
{
   kfree(ptr);   
}

static void __exit test_exit_module(void)
{
   test_exit();
}
module_init(test_init_module);
module_exit(test_exit_module);
