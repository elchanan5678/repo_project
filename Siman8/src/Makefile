CC:=gcc
CFLAGS:=-fno-stack-protector -O2 -c -Wall -m32
LD:=ld
LDFLAGS:=-T linker.ld -o kernel.bin -m elf_i386 -s
ASM:=nasm
ASMFLAGS:=-f elf

all: kernel.o boot.o
	$(LD) $(LDFLAGS) kernel.o boot.o screen.o asmisr.o gdt.o idt.o descriptors.o isr.o tools.o

kernel.o: screen.o descriptors.o
	$(CC) $(CFLAGS) kernel/kernel.c

boot.o: kernel.o
	$(ASM) $(ASMFLAGS) -o boot.o boot/boot.asm

gdt.o:
	$(ASM) $(ASMFLAGS) -o gdt.o kernel/gdt.asm

idt.o: isr.o
	$(ASM) $(ASMFLAGS) -o idt.o kernel/idt.asm

asmisr.o:
	$(ASM) $(ASMFLAGS) -o asmisr.o kernel/asmisr.asm

tools.o:
	$(CC) $(CFLAGS) kernel/tools.c

descriptors.o: asmisr.o gdt.o idt.o tools.o isr.o
	$(CC) $(CFLAGS) kernel/descriptors.c

screen.o: tools.o
	$(CC) $(CFLAGS) kernel/screen.c

isr.o:
	$(CC) $(CFLAGS) kernel/isr.c

clean:
	$(shell rm -rf *.o kernel.bin)
