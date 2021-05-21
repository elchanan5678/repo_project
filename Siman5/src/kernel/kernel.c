#include "screen.h"
int kmain(void *mbd,unsigned int magic){
	screen_clear();
	screen_print("Hello World!");
	return 0;
}

