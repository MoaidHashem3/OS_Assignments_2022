#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d", &N);
    int* array = (int*) malloc(N * sizeof(int));
    for(int i=0; i<N; i++)
    {
        array[i]=i;
    }
    for(int i=0; i<N; i++)
    {
        printf("Array[%d]=%d\n", i, array[i]);
    }
    free(array);
}
