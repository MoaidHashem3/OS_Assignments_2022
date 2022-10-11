#include <stdio.h>

int main()
{
    int num_of_process, mn, cnt = 0, time;
    double wt = 0, tat = 0, end, final = 0;
    
    printf("Enter Number of process: ");
    scanf("%d", &num_of_process);

    int a[num_of_process], b[num_of_process], temp[num_of_process];
    for(int i = 0; i < num_of_process; i++)
    {
        printf("Enter Arrival time for process %d: ", i+1);
        scanf("%d", &a[i]);
        printf("Enter Burst time for process %d: ",i+1);
        scanf("%d", &b[i]);
        temp[i] = b[i];
    }
    b[num_of_process] = 9999;
    for(time = 0; cnt != num_of_process; time++)
    {
        mn = num_of_process;
        for(int i = 0; i < num_of_process; i++)
        {
            if(a[i] <= time && b[i] < b[mn] && b[i] > 0)
                mn = i;
        }
        b[mn]--;
        if(b[mn] == 0)
        {
            cnt++;
            end = time + 1;
            wt += end - a[mn] - temp[mn];
            tat += end - a[mn];
            printf("Process Num [%d]:\n", cnt);
            printf("Waiting time: %f\n", wt);
            printf("Turn around time: %f\n", tat - final);
            final = tat;
        }
    }
             printf("Completion Time: %f\n", end);
             printf("Average Waiting Time: %f\n", wt / num_of_process);
             printf("Average Turnaround Time: %f\n", tat / num_of_process);
}
