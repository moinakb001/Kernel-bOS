#include <stdint.h>
#define PAGE_ALIGN(X)	(X&0xFFFFF000)
typedef struct {
uint32_t addr:20;
uint32_t avail:3;
uint32_t g:1;
uint32_t s:1;
uint32_t zer:1;
uint32_t a:1;
uint32_t d:1;
uint32_t w:1;
uint32_t u:1;
uint32_t r:1;
uint32_t p:1;
} P_Dir;

typedef struct {
uint32_t addr:20;
uint32_t avail:3;
uint32_t g:1;
uint32_t zer:1;
uint32_t d:1;
uint32_t a:1;
uint32_t c:1;
uint32_t w:1;
uint32_t u:1;
uint32_t r:1;
uint32_t p:1;

} P_Entry;
void init_paging_identity();
