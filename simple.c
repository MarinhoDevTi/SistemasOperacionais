#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

/* Essa fun��o � chamada quando o m�dulo � carregado. */
int simple_init(void)
{
       printk(KERN_INFO "Loading Module\n");

       return 0;
}

/* Essa fun��o � chamada quando o m�dulo � removido. */
void simple_exit(void) {
	printk(KERN_INFO "Removing Module\n");
}

/* Macros para o registro dos pontos de entrada e sa�da do m�dulo. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

