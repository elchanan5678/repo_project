#include "isr.h"
#include "screen.h"

void (*isr_callbacks[16])();

void isr_handler(registers_t regs)
{
	screen_print("Recieved interrupt: ");
	screen_print_int(regs.int_no,16);
	screen_print("\n");
}

void irq_handler(registers_t regs)
{
	outb(0x20, 0x20);
	if (regs.int_no >= IRQ8){
		outb(0xA0, 0x20);
	}
	if (isr_callbacks[regs.int_no-IRQ0]!=0){
		(*isr_callbacks[regs.int_no-IRQ0])();
	}
	else{
		screen_print("Recieved IRQ: ");
		screen_print_int(regs.int_no,16);
		screen_print("\n");
	}
}

void register_isr_callback(int irq,void (*callback)()){
	isr_callbacks[irq-IRQ0]=callback;
}
