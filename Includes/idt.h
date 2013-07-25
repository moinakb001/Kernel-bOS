#ifndef idt_h_577_4486628780058
#define idt_h_577_4486628780058
#include <term.h>
#include <stdint.h>

#define IDT_

typedef struct {
uint16_t offsetlow;
uint16_t selector;
uint8_t zero=0;
uint8_t flags;
uint16_t offsethigh;

} __attribute__((__packed__)) idtentry;
typedef struct
{
        unsigned short length;
        unsigned long base;
} __attribute__((__packed__)) tloader;
void create_descriptor_idt(uint32_t loc,uint32_t offset, uint16_t selector, uint8_t flags);
uint32_t idt_init();
#endif
