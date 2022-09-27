#include <stdio.h>
#include <unistd.h>
#include <time.h>
  
int main()
{
    
    clock_t start = clock();
    for(int i=0;i<2;i++)
    {
        if(fork() == 0)
        {
            clock_t start = clock();
             printf("\nChild %d--> ID: %d. Parant ID: %d.\n", i+1, getpid(), getppid());
             clock_t end = clock();
             double Excutiontime = (double)(end - start)/CLOCKS_PER_SEC;
             printf("Time: %f ms\n", Excutiontime*1000);
             exit(0);

        }
    }

    for(int i=0;i<2;i++){
        wait(NULL);
    }

    printf("\nParent--> ID: %d. Parant ID: %d.\n", getpid(), getppid());
    clock_t end = clock();
    double Excutiontime = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Time: %f ms\n", Excutiontime*1000);


}