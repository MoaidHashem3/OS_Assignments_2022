#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>
#include<fcntl.h>

int main(int argc, char* argv[]){

    char message[256];

    printf("Here is publisher.....\n");

    if(mkfifo("/tmp/ex1", 0666)==-1){
        if(errno != EEXIST){
            printf("Couldn't make fifo file");
            return 1;
        }
    }
    
    for(int i=0; i>=0; i++){
    int fd = open("/tmp/ex1", O_WRONLY, O_SYNC);

    fgets(message, 256, stdin);
    for (int i =0; i<4; i++){
    write(fd, &message, sizeof(message));
    close(fd);}

    }


   
    return 0;
}