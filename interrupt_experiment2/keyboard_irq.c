#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>

#define	KEYBOARD_IRQ	1
#define	MODULE_NAME	"my_keyboard_handler"

static irqreturn_t keyboard_handler(int irq, void *dev_id) {
	static int count = 0;

	if (in_interrupt()) {
		printk(KERN_INFO "Keyboard Handler: Interrupt handled! (Count: %d)\n", ++count);
	}

	return IRQ_HANDLED;
}

static int __init my_irq_init(void){
	int result;
	
	result = request_irq(KEYBOARD_IRQ, keyboard_handler, IRQF_SHARED, MODULE_NAME, (void*)(keyboard_handler));

	if (result < 0) {
		printk(KERN_ERR "Keyboard Handler: Faild to register IRQ handler\n");
		return result;
	}

	printk(KERN_INFO "Keyboard Handler: Module loaded. Press any key\n");
	return 0;
}

static void __exit my_irq_exit(void) {
	free_irq(KEYBOARD_IRQ, (void*)(keyboard_handler));
	printk(KERN_INFO "Keyboard Handler: Module unloaded.\n");
}

module_init(my_irq_init);
module_exit(my_irq_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("KIM MINJUN");
MODULE_DESCRIPTION("A simple Keyboard Interrupt Handler");

