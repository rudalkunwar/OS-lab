#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 100
#define MAX_PAGES 100

int findPage(int pages[], int n, int page) {
    for (int i = 0; i < n; i++) {
        if (pages[i] == page) {
            return i;
        }
    }
    return -1;
}

void fifoPageReplacement(int pages[], int n, int frames) {
    int frameSet[MAX_FRAMES];
    int pageFaults = 0;

    for (int i = 0; i < frames; i++) {
        frameSet[i] = -1; // Initialize frame set to -1 (empty frame)
    }

    int currentIndex = 0; // Current index in frame set

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int pageIndex = findPage(frameSet, frames, page);

        if (pageIndex == -1) {
            // Page fault, replace the page at currentIndex
            frameSet[currentIndex] = page;
            currentIndex = (currentIndex + 1) % frames; // Update currentIndex

            pageFaults++;
        }
    }

    // Print the page fault count
    printf("Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[MAX_PAGES];
    int n, frames;

    printf("Enter the number of pages:\n");
    scanf("%d", &n);

    printf("Enter the page references:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames:\n");
    scanf("%d", &frames);

    fifoPageReplacement(pages, n, frames);

    return 0;
}

