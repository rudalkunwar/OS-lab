#include <stdio.h>
#include <stdbool.h>

#define MAX_BLOCKS 100
#define MAX_PROCESS 100

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[MAX_PROCESS];
int i,j;
    // Initialize allocation array to -1
    for ( i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Iterate through all processes
    for (i = 0; i < n; i++) {
        int bestIdx = -1;

        // Find the best fit block for the current process
        for (j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx]) {
                    bestIdx = j;
                }
            }
        }

        // Allocate the block to the process
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    // Print the allocation result
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int blockSize[MAX_BLOCKS], processSize[MAX_PROCESS];
    int i,m, n;

    printf("Enter the number of memory blocks:\n");
    scanf("%d", &m);

    printf("Enter the sizes of memory blocks:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
    }

    printf("Enter the number of processes:\n");
    scanf("%d", &n);

    printf("Enter the sizes of processes:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }

    bestFit(blockSize, m, processSize, n);

    return 0;
}
