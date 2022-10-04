#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>
#include<fcntl.h>

int main(int argc, char* argv[]){
    
    char r_massege[256];
    printf("Here is subscriber.....\n");

    for(int i=0; i>=0; i++){
        int fd = open("/tmp/ex1", O_RDONLY);
        read(fd, &r_massege, sizeof(r_massege));
        printf("Massage from Publisher: %s", r_massege);
        close(fd);

    }
    return 0;
}