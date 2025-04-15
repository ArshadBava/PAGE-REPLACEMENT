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

int findOptimal(int pages[], int frames[], int n, int capacity, int index) {
    int pos = -1, farthest = index;
    for (int i = 0; i < capacity; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }
        if (j == n)
            return i;
    }
    return (pos == -1) ? 0 : pos;
}

void Optimal(int pages[], int n, int capacity) {
    int frames[capacity], pageFaults = 0;
    for (int i = 0; i < capacity; i++)
        frames[i] = -1;

    printf("\nOptimal Page Replacement Table:\n");
    printf("Page\tFrames\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t", pages[i]);
        int found = 0;
        for (int j = 0; j < capacity; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            int pos = (i < capacity) ? i : findOptimal(pages, frames, n, capacity, i);
            frames[pos] = pages[i];
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

    Optimal(pages, n, capacity);
    
    return 0;
}

