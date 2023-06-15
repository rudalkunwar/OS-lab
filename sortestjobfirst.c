#include <stdio.h>

void sort(int n, int bt[], int pid[]) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                // Sort burst times in ascending order
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Update process IDs accordingly
                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, pid[20], bt[20];
    int i;
    printf("Enter the number of processes [Max: 20]:\n");
    scanf("%d", &n);
    printf("Enter process IDs:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &pid[i]);
    }
    printf("Enter burst times:\n");
    for (i = 0; i < n; i++) {
        printf("p[%d]: ", pid[i]);
        scanf("%d", &bt[i]);
    }

    sort(n, bt, pid);

    int wt[n];
    int tat[n];
    float twt = 0.0;
    float ttat = 0.0;
    wt[0] = 0;

    // Waiting times
    for (i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
        twt += wt[i];
    }

    // Turnaround times
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        ttat += tat[i];
    }
    printf("\n \t SORTEST JOB FIRST\n");
    printf("\nPID \t Burst Time \t Waiting Time \t Turnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t %d\t\t %d\t\t %d\n", pid[i], bt[i], wt[i], tat[i]);
    }
    // Calculate average turnaround time and average waiting time
    printf("\nAverage Waiting Time: %.2f\n", twt / n);
    printf("Average Turnaround Time: %.2f\n", ttat / n);
}

