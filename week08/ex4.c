#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

int main()
{
    struct rusage use;

    for(int i=0; i<10; i++)
    {
        void* x = malloc(1e7);
        memset(x, 0, sizeof(x));
        getrusage(RUSAGE_SELF, &use);
        printf("The usage of memory: %ld\n", use.ru_ixrss + use.ru_idrss + use.ru_isrss);
        sleep(1);
    }
}