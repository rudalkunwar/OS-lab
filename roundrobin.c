#include <stdio.h>

void calculateTimes(int n, int bt[], int quantum) {
    int wt[n], tat[n], rem_bt[n];
    int i, time = 0, total_wt = 0, total_tat = 0;

    // Initialize remaining burst times
    for (i = 0; i < n; i++)
        rem_bt[i] = bt[i];

    // Run the Round Robin algorithm
    while (1) {
        int done = 1;

        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0;

                if (rem_bt[i] > quantum) {
                    time += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    time += rem_bt[i];
                    wt[i] = time - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }

        if (done)
            break;
    }

    // Calculate turnaround time and total waiting time
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Display the results
    printf("\nPID \t Burst Time \t Waiting Time \t Turnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t %d\t\t %d\t\t %d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    // Calculate average waiting time and average turnaround time
    float avgWT = (float)total_wt / n;
    float avgTAT = (float)total_tat / n;

    printf("\nAverage Waiting Time: %.2f\n", avgWT);
    printf("Average Turnaround Time: %.2f\n", avgTAT);
}

int main() {
    int n, quantum;
    printf("Enter the number of processes:\n");
    scanf("%d", &n);

    int bt[n];
    printf("Enter burst times:\n");
    for (int i = 0; i < n; i++) {
        printf("p[%d]: ", i + 1);
        scanf("%d", &bt[i]);
    }

    printf("Enter the time quantum:\n");
    scanf("%d", &quantum);

    calculateTimes(n, bt, quantum);

    return 0;
}
