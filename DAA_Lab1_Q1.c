#include <stdio.h>
#include <stdlib.h>

void find_second_smallest_largest(int arr[], int n, int *second_smallest, int *second_largest) {
    if (n < 2) {
        *second_smallest = *second_largest = -1; // Not enough elements in the array
        return;
    }

    // Initialize the variables to store the second smallest and second largest
    *second_smallest = *second_largest = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < *second_smallest) {
            *second_largest = *second_smallest;
            *second_smallest = arr[i];
        } else if (arr[i] > *second_largest) {
            *second_largest = arr[i];
        }
    }
}

int main() {
    int n, i;
    int *arr, second_smallest, second_largest;
    char choice;

    printf("Select Input Method:\n");
    printf("1. Generate random array\n");
    printf("2. Read array from file\n");
    scanf(" %c", &choice);

    if (choice == '1') {
        printf("Enter the size of the array: ");
        scanf("%d", &n);

        // Dynamically allocate memory for the array
        arr = (int *)malloc(n * sizeof(int));

        // Generate random numbers for the array
        for (i = 0; i < n; i++) {
            arr[i] = rand() % 100; // Generating random numbers between 0 and 99
        }
    } else if (choice == '2') {
        FILE *file;
        char filename[100];

        printf("Enter the filename to read the array from: ");
        scanf("%s", filename);

        file = fopen(filename, "r");
        if (file == NULL) {
            printf("Error: File not found.\n");
            return 1;
        }

        fscanf(file, "%d", &n);

        // Dynamically allocate memory for the array
        arr = (int *)malloc(n * sizeof(int));

        // Read array elements from the file
        for (i = 0; i < n; i++) {
            fscanf(file, "%d", &arr[i]);
        }

        fclose(file);
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    printf("Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Find the second smallest and second largest elements
    find_second_smallest_largest(arr, n, &second_smallest, &second_largest);

    if (second_smallest == -1 || second_largest == -1) {
        printf("Not enough elements in the array.\n");
    } else {
        printf("Second Smallest Element: %d\n", second_smallest);
        printf("Second Largest Element: %d\n", second_largest);
    }

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
