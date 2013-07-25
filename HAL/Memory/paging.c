#include <sysops.h>
#include <paging.h>
#include <unistd.h>
P_Dir *dir;
P_Entry *entries;
void init_paging_identity(/*uint32_t start,*/ uint32_t end){
dir=0x00008000;
entries=0x00009000;
for(uint32_t i=0;i<end;i++){
dir[i].addr=(((uint32_t)entries)+(i*4096))>>(12);
dir[i].g=0;
dir[i].s=0;
dir[i].zer=0;
dir[i].a=0;
dir[i].d=0;
dir[i].w=1;
dir[i].u=0;
dir[i].r=1;
dir[i].p=1;


for(uint32_t j=0;j<1024;j++){
entries[i*j].addr=((j+1)*(i+1));
entries[i*j].g=0;
entries[i*j].s=0;
entries[i*j].zer=0;
entries[i*j].a=0;
entries[i*j].d=0;
entries[i*j].w=1;
entries[i*j].u=0;
entries[i*j].r=1;
entries[i*j].p=1;
}

}

}
