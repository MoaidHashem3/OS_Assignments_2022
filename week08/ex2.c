//when running vmstat 1 si and so entries remains 0
//, when running top i notice it using more memory 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    for(int i=0;i<10;i++){
        void* x = malloc(1e7);
        memset(x, 0, sizeof(x));
        sleep(1);
    }
   
}