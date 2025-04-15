#include <stdio.h>

void displayFrames(int frames[], int capacity) {
    for (int i = 0; i < capacity; i++) {
        if (frames[i] == -1)
            printf("- ");
        else
            printf("%d ", frames[i]);
    }
    printf("\n");
}

int findLRU(int time[], int capacity) {
    int min = time[0], pos = 0;
    for (int i = 1; i < capacity; i++) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

void LRU(int pages[], int n, int capacity) {
    int frames[capacity], time[capacity], pageFaults = 0, counter = 0;
    for (int i = 0; i < capacity; i++) {
        frames[i] = -1;
        time[i] = 0;
    }
    printf("\nLRU Page Replacement Table:\n");
    printf("Page\tFrames\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", pages[i]);
        int found = 0;
        for (int j = 0; j < capacity; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                time[j] = ++counter;  // Update last used time
                break;
            }
        }
        if (!found) {
            int pos;
            if (i < capacity) {
                pos = i;  // Fill available space first
            } else {
                pos = findLRU(time, capacity);  // Find the least recently used page
            }
            frames[pos] = pages[i];
            time[pos] = ++counter;
            pageFaults++;
        }
        displayFrames(frames, capacity);
    }
    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    int n, capacity;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter the page sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &capacity);
    LRU(pages, n, capacity);
    return 0;
}

