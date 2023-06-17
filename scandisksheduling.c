#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, head, requests[MAX_REQUESTS];
    int i, totalDistance = 0;

    printf("Enter the current position of the disk head: ");
    scanf("%d", &head);

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk requests:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    // Sort the disk requests
    qsort(requests, n, sizeof(int), compare);

    int start = 0, end = n - 1;
    int leftDistance = 0, rightDistance = 0;

    // Find the index where the head is positioned
    for (i = 0; i < n; i++) {
        if (requests[i] > head) {
            start = i - 1;
            end = i;
            break;
        }
    }

    // Calculate the total distance for the left side
    for (i = start; i >= 0; i--) {
        leftDistance += abs(head - requests[i]);
        head = requests[i];
    }

    // Calculate the total distance for the right side
    for (i = end; i < n; i++) {
        rightDistance += abs(head - requests[i]);
        head = requests[i];
    }

    totalDistance = leftDistance + rightDistance;

    printf("Total Head Movement: %d\n", totalDistance);

    return 0;
}

