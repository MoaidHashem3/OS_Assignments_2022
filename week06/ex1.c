#include <stdio.h>

int main()
{
    int num_of_process; 

    printf("Enter Number of process: ");
    scanf("%d", &num_of_process);

    int a[num_of_process], b[num_of_process], w[num_of_process], t[num_of_process];
    float aw = 0.0, at = 0.0;

    for(int i=0;i<num_of_process;i++){
        printf("Enter Arrival time for process %d: ", i+1);
        scanf("%d", &a[i]);
        printf("Enter Burst time for process %d: ",i+1);
        scanf("%d", &b[i]);
    }
    w[0] = 0;
    for(int i=0;i<num_of_process;i++){
        if(i){
            w[i] = 0;
            for(int j=0;j<i;j++)
                w[i] += b[j];
            w[i] -= a[i];
        }
        t[i] = b[i] + w[i];
        aw += w[i];
        at += t[i];
        printf("Process Num [%d]:\n", i+1);
        printf("Completion time: %d\n", a[i] + t[i]);
        printf("Turn around time: %d\n", t[i]);
        printf("Waiting time: %d\n", w[i]);
    }
         aw /= num_of_process;
         at /= num_of_process;
         printf("Average turn around time: %f\n", at);
         printf("Average waiting time: %f\n", aw);
}