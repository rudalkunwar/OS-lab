#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, requests[100];
    int i, totalDistance = 0;

    printf("Enter the current position of the disk head: ");
    scanf("%d", &head);

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk requests:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    totalDistance = abs(requests[0] - head);

    for (i = 1; i < n; i++) {
        totalDistance += abs(requests[i] - requests[i-1]);
    }

    printf("Total Head Movement: %d\n", totalDistance);

    return 0;
}

