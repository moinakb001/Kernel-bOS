#include "stdint.h"
typedef struct{uint8_t charac; uint8_t attrib;} vid;
static vid *vidpoint=0xB8000;
void print(uint8_t *point,uint32_t size){

while(size>0){
printchar7(*point,0x07);
point++;
size--;
}
return 0;

}
void printchar7(uint8_t charac, uint8_t attrib){
vidpoint->charac=charac;
vidpoint->attrib=attrib;
vidpoint++;
if(vidpoint==0xC0000){
vidpoint=0xB8000;
}
}
void movecur7(uint8_t x, uint8_t y){
vidpoint=y*80+x;

}
void clear7(){
vid *start=0xB8000;
while(start<0xC0000){
start->charac=0;
start->attrib=0;
start++;
}

}
