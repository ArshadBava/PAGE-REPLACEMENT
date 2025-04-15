#include <stdio.h>

int isPresent(int frames[], int capacity, int page) {
    for (int i = 0; i < capacity; i++) {
        if (frames[i] == page) {
            return 1;  // Page is present in the frames
        }
    }
    return 0;  // Page is not present in the frames
}

void displayFrames(int frames[], int capacity) {
    for (int i = 0; i < capacity; i++) {
        if (frames[i] == -1)
            printf("-\t");
        else
            printf("%d\t", frames[i]);
    }
    printf("\n");
}

void FIFO(int pages[], int n, int capacity) {
    int frames[capacity];
    int pageFaults = 0, index = 0;

    // Initialize frames with -1 (empty frames)
    for (int i = 0; i < capacity; i++) {
        frames[i] = -1;
    }

    printf("\nFIFO Page Replacement Table:\n");
    printf("Page\tFrames\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t", pages[i]);

        // Check if the page is not in the frames
        if (!isPresent(frames, capacity, pages[i])) {
            frames[index] = pages[i];  // Replace the page in the frame
            index = (index + 1) % capacity;  // Circular increment for FIFO
            pageFaults++;  // Increment page faults
        }
        
        // Display the current state of frames
        displayFrames(frames, capacity);
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    int n, capacity;
    
    // Input number of pages and page sequence
    printf("Enter number of pages: ");
    scanf("%d", &n);
    int pages[n];
    
    printf("Enter the page sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Input number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &capacity);

    // Run the FIFO algorithm
    FIFO(pages, n, capacity);
    
    return 0;
}

