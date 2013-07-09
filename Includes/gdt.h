#include <term.h>
#include <stdint.h>
 typedef struct {
uint16_t lowlimit;
uint16_t lowbase;
uint8_t midbase;
uint8_t access;
uint32_t highlimit:4;
uint32_t flags:4;
uint8_t highbase;
} gdtentry;
void create_descriptor(uint32_t base, uint32_t limit, uint8_t flag,uint8_t );