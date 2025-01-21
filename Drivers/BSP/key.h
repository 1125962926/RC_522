#ifndef __KEY_H
#define __KEY_H 			   
#include "sys.h"  
	 
#define KEY0 	1
#define KEY1	2
#define WKUP    3

void key_init(void);
u8 key_scan(void);

#endif
