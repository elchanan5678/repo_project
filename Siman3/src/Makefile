CC:=gcc
CFLAGS:=-c -Wall -m32
LD:=ld
LDFLAGS:=-T linker.ld -o kernel.bin -m elf_i386 -s
ASM:=nasm
ASMFLAGS:=-f elf

all: kernel.o boot.o
	$(LD) $(LDFLAGS) kernel.o boot.o screen.o

kernel.o: screen.o
	$(CC) $(CFLAGS) kernel/kernel.c

boot.o: kernel.o
	$(ASM) $(ASMFLAGS) -o boot.o boot/boot.asm

screen.o:
	$(CC) $(CFLAGS) kernel/screen.c

clean:
	$(shell rm -rf *.o kernel.bin)
