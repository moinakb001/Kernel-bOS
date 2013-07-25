#include <idt.h>
#include <term.h>
#include <stdint.h>
idtentry idtentries[256]
void default_handler(void) {
    __asm__("pushad");
    printf("Interrupt issued.",0,0, make_color(COLOR_RED, COLOR_WHITE) );
    __asm__("popad; leave; iret"); 
	
}
uint32_t lidt( void * base, uint16_t size )
{
	tloader	IDTR;//struct in header
 
    IDTR.length = size;
   IDTR.base = (unsigned long)base;
    asm( "lidt (%0)": : "p"(&IDTR) );//inline loading gdt
	return 0;
		 
}
void create_descriptor_idt(uint8_t loc,uint32_t offset, uint16_t selector, uint8_t flags){
idtentries[(uint32_t)loc].selector=(/*__builtin_bswap16*/ (selector));
idtentries[(uint32_t)loc].offsetlow=(uint16_t)(/*__builtin_bswap32*/ (offset)&(0x0000FFFF));
idtentries[(uint32_t)loc].offsethigh=(uint16_t)(/*__builtin_bswap32*/ (offset)&(0xFFFF0000));
idtentries[(uint32_t)loc].flags=flags;
}
uint32_t idt_init(){
uint8_t i=0;

do{
create_descriptor_idt(i,default_handler,0,0b11100001);
i++;
}while(i!=0);

lidt(idtentries,255*8+7);
return 0;
}