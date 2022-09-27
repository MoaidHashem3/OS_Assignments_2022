#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
int main(void){

    int v[120];
    int u[120];
    int n= 6;
    int result = 0;
    int lastIndex = 0;
    
    printf("Enter Number of Processes: ");
    scanf("%d", &n);
    for(int i=0; i<120; i++){
        v[i] = rand()%100;
        u[i] = rand()%100;
    }
    pid_t id;
    for(int i=0; i < n; i++){
        id = fork();
    }
      if(id == 0){

                for(int i=lastIndex; i<120/n; i++){
                lastIndex = i;
                result = result + (u[i]*v[i]);
             }
        }
       for(int i=0;i<n;i++){
        wait(NULL);
    }

    printf("%d" , result);
}