#include "stdio.h"
int main(){
uint8_t *ch;
ch=0xC00000;
*ch="hai";
print(ch,3);
}
