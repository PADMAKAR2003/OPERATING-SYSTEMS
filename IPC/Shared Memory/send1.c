#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int fd, *memory;
    fd = shm_open("/mem", O_CREAT|O_RDWR,0777);
    ftruncate(fd,1024);
    memory = (int *)mmap(NULL,1024, PROT_WRITE|PROT_READ, MAP_SHARED,fd,0);
    (*memory) = 0;
    while(1)
    {
        
        printf("Sender data: %d\n",++(*memory));
        sleep(1);
    }
}
