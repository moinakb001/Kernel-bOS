#include <gdt.h>
#include <idt.h>
#include <term.h>

void cpuinit(){
gdtinit();

idtinit();

}



