#include "screen.h"
#include "descriptors.h"


int kmain(void *mbd,unsigned int magic){
	screen_clear();
	if (magic!=0x2BADB002){
		screen_print("Invalid multiboot header.");
		return -1;
	}
	screen_print("Hello World!\n");
	screen_print("Setting up the GDT.\n");
	gdt_setup();
	screen_print("GDT set.\n");
	screen_print("Setting up the IDT.\n");
	idt_setup();
	screen_print("IDT set.\n");
	screen_print("Sending interrupt.\n");
	__asm__("int $0x00");
	__asm__("int $0x80");
	//__asm__("int $0x23");
	while(1){
		;
	}
	return 0;
}

