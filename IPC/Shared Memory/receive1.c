#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<unistd.h>
#include<fcntl.h>



int main()
{
    int fd, *memory;
    fd = shm_open("/mem", O_CREAT | O_RDWR,0777);
    // ftruncate(fd, sizeof(int));
    memory = (int *)mmap(NULL, 1024, PROT_READ|PROT_WRITE, MAP_PRIVATE,fd,0);

    while(1)
    {
        printf("Read data: %d\n",*memory);
        sleep(1);
    }
}
