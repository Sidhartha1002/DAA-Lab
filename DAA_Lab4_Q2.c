#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the partitioning index
int partition(int arr[], int low, int high, int *comparisons) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        (*comparisons)++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to perform Quick Sort
void quickSort(int arr[], int low, int high, int *comparisons) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons);

        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
    }
}

int main() {
    int choice;
    FILE *inputFile, *outputFile;
    clock_t start, end;
    double cpu_time_used;

    printf("MAIN MENU (QUICK SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. EXIT\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            inputFile = fopen("inAsce.dat", "r");
            outputFile = fopen("outQuickAsce.dat", "w");
            break;
        case 2:
            inputFile = fopen("inDesc.dat", "r");
            outputFile = fopen("outQuickDesc.dat", "w");
            break;
        case 3:
            inputFile = fopen("inRand.dat", "r");
            outputFile = fopen("outQuickRand.dat", "w");
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    int size;
    fscanf(inputFile, "%d", &size);

    int arr[size];
    for (int i = 0; i < size; i++) {
        fscanf(inputFile, "%d", &arr[i]);
    }

    int comparisons = 0;
    start = clock();
    quickSort(arr, 0, size - 1, &comparisons);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    for (int i = 0; i < size; i++) {
        fprintf(outputFile, "%d ", arr[i]);
    }

    fprintf(outputFile, "\nNumber of comparisons: %d\n", comparisons);
    fprintf(outputFile, "Execution time: %lf seconds\n", cpu_time_used);

    printf("Sorting complete. Results written to output file.\n");

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
