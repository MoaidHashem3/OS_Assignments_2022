#include <stdio.h>
#include <unistd.h>
#include<time.h>

void main(int argc, char* argv[]){

    int n = atoi(argv[1]);

    for (int i =0; i<n; i++){
        fork();
        sleep(5);
    }

}