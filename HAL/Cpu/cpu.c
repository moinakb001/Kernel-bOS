#include <gdt.h>
#include <idt.h>
#include <term.h>
#include <sysops.h>
#include <cpu.h>
uint32_t cpuinit(){

if(gdtinit()!=0|idtinit()!=0){
while(1){
hlt();
}
}
sti();
return 0;
}



