#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 100
#define MAX_PAGES 100

int findPage(int pages[], int n, int page) {
	int i;
    for ( i = 0; i < n; i++) {
        if (pages[i] == page) {
            return i;
        }
    }
    return -1;
}

void lruPageReplacement(int pages[], int n, int frames) {
    int frameSet[MAX_FRAMES];
    int j,i,pageFaults = 0;
    int counter = 0; // Counter to track the usage of pages

    for (i = 0; i < frames; i++) {
        frameSet[i] = -1; // Initialize frame set to -1 (empty frame)
    }

    for ( i = 0; i < n; i++) {
        int page = pages[i];
        int pageIndex = findPage(frameSet, frames, page);

        if (pageIndex == -1) {
            // Page fault, replace the least recently used page
            int lruIndex = 0; // Index of least recently used page

            // Find the page in frame set that has the smallest counter value
            for ( j = 1; j < frames; j++) {
                if (frameSet[j] == -1 || frameSet[j] < frameSet[lruIndex]) {
                    lruIndex = j;
                }
            }

            // Replace the least recently used page with the current page
            frameSet[lruIndex] = page;
            pageFaults++;
        }

        // Update the counter value of each page in frame set
        for (j = 0; j < frames; j++) {
            if (frameSet[j] != -1) {
                frameSet[j]++;
            }
        }

        counter++;
        frameSet[pageIndex] = counter; // Update the counter value of the current page
    }

    // Print the page fault count
    printf("Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[MAX_PAGES];
    int i,n, frames;

    printf("Enter the number of pages:\n");
    scanf("%d", &n);

    printf("Enter the page references:\n");
    for ( i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames:\n");
    scanf("%d", &frames);

    lruPageReplacement(pages, n, frames);

    return 0;
}

