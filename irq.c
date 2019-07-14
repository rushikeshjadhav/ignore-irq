#include <linux/module.h>       /* Needed by all modules */
#include <linux/kernel.h>       /* Needed for KERN_INFO */
#include <linux/init.h>         /* Needed for the macros */
#include <linux/interrupt.h>    /* Needed for interrupt handling */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rushikesh Jadhav");

static int irq = 9999;

module_param(irq, int, 0660);

static int __init irq_start(void)
{
printk(KERN_INFO "Ignoring IRQ %d\n",irq);
disable_irq(irq);
printk(KERN_INFO "Done\n");
return 0;
}

static void __exit irq_end(void)
{
printk(KERN_INFO "Exiting IRQ\n");
}

module_init(irq_start);
module_exit(irq_end);
