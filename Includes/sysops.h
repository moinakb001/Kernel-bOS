#ifndef sysops_h_436_5755521100552
#define sysops_h_436_5755521100552
#include <stdint.h>

void hlt(){

    asm( "hlt": : );
	return 0;

}void cli(){

    asm( "cli": : );
	return 0;

}void sti(){

    asm( "sti": : );
	return 0;

}uint8_t inb(uint16_t port){
uint8_t a;
    asm("mov %1,%dx;"
		"in %dx,%al;"
		"mov %ax,%0;"
	:"=r"(a) : r(port));
	
 
    
	return a;

}void outb(uint8_t commd, uint16_t port){

    asm("mov %1,%dx;"
		"mov %0,%al;"
		"out %al,%dx;"
		
	: : r(commd),r(port));
	

}

#endif
