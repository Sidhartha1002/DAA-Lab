#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform the merge operation in merge sort
void merge(int arr[], int left, int mid, int right, int *comparisons) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        (*comparisons)++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to perform merge sort
void mergeSort(int arr[], int left, int right, int *comparisons) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, comparisons);
        mergeSort(arr, mid + 1, right, comparisons);

        merge(arr, left, mid, right, comparisons);
    }
}

int main() {
    int choice;
    FILE *inputFile, *outputFile;
    clock_t start, end;
    double cpu_time_used;

    printf("MAIN MENU (MERGE SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. EXIT\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            inputFile = fopen("inAsce.dat", "r");
            outputFile = fopen("outMergeAsce.dat", "w");
            break;
        case 2:
            inputFile = fopen("inDesc.dat", "r");
            outputFile = fopen("outMergeDesc.dat", "w");
            break;
        case 3:
            inputFile = fopen("inRand.dat", "r");
            outputFile = fopen("outMergeRand.dat", "w");
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
    mergeSort(arr, 0, size - 1, &comparisons);
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
