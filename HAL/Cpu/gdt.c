#include <gdt.h>
#include <term.h>
#include <stdint.h>

gdtentry entries[32];
void default_handler(void) {
    __asm__("pushad");
    printf("Interrupt issued.",0,0, make_color(COLOR_RED, COLOR_WHITE) );
    __asm__("popad; leave; iret"); 
}


void lgdt( void * base, unsigned short size )
{
    struct
    {
        unsigned short length;
        unsigned long base;
    } __attribute__((__packed__)) GDTR;
 
    GDTR.length = size;
    GDTR.base = (unsigned long)base;
    asm( "lgdt (%0)"
         : : "p"(&GDTR) );
}

uint8_t gdtinit(){

}
