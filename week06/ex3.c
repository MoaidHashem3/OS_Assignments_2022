#include <stdio.h>

int main() {

    int cnt, num_of_process, time, r, flag = 0, quantm;
    printf("Enter Number of process: ");
    scanf("%d", &num_of_process);
    int wt = 0, tat = 0, a[num_of_process], b[num_of_process], temp[num_of_process];
    r = num_of_process;
    for (int i = 0; i < num_of_process; i++) {
        printf("Enter Arrival time for process %d: ", i+1);
        scanf("%d", &a[i]);
        printf("Enter Burst time for process %d: ",i+1);
        scanf("%d", &b[i]);
        temp[i] = b[i];
    }
    printf("Enter Time Quantum: ");
    scanf("%d", &quantm);
    for (time = 0, cnt = 0; r != 0;) {
        if (temp[cnt] <= quantm && temp[cnt] > 0) {
            time += temp[cnt];
            temp[cnt] = 0;
            flag = 1;
        } else if (temp[cnt] > 0) {
            temp[cnt] -= quantm;
            time += quantm;
        }
        if (temp[cnt] == 0 && flag == 1) {
            r--;
            printf("Process Num [%d]:\n", cnt+1);
            printf("TWaiting time: %d\n", time - a[cnt] - b[cnt]);
            printf("Turn around time: %d\n", time - a[cnt]);
            wt += time - a[cnt] - b[cnt];
            tat += time - a[cnt];
            flag = 0;
        }
        if (cnt == num_of_process - 1) cnt = 0;
        else if (a[cnt + 1] <= time) cnt++;
        else cnt = 0;
    }

    printf("Average Waiting Time: %f\n", (double)(wt) / num_of_process);
    printf("Average Turnaround Time: %f\n", (double)(tat) / num_of_process);
}