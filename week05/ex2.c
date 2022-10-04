#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<string.h>
struct Thread
{
    pthread_t id;
    int i;
    char message[256];

};

void* threadf(void* arg)
{
	printf("Hello from thread %d\n", *(int*)arg);
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
   int n;
    scanf("%d", &n);
    
    pthread_t th[n];

    for(int i =0; i<n; i++){

        struct Thread thread;
		pthread_create(th + i, NULL, &threadf, &i);
		printf("Created thread %lu\n", th[i]);
        thread.i = i;
        thread.id = th[i];
        printf("thread %d", thread.i);

    }

     for(int i =0; i<n; i++){
        pthread_join(th[i], NULL);
        printf("Created thread %lu exited\n", th[i]);

    }

    return 0;
}