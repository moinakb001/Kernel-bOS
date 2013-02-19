#include <stdint.h>
static uint16_t *vidpoint=0xB8000;
void print(uint8_t *point,uint32_t size){

while(size>0){
printchar7(*point,0x07)
point++;
size--;
}
return 0;

}
void printchar7(uint8_t charac, uint8_t attrib){
uint16_t sh=charac<<8|attrib;
*vidpoint=sh;
vidpoint++;
if(vidpoint==0xC0000){
vidpoint=0xB8000;
}
}
void movecur7(uint8_t x, uint8_t y){
vidpoint=y*80+x;

}