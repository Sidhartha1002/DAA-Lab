#include <stdio.h>

void duplicate_elements(int arr[], int n, int *total_duplicates, int *most_repeating_element) {
    int freq[100] = {0}; // Assuming values are between 0 and 99

    *total_duplicates = 0;
    *most_repeating_element = 0;

    for (int i = 0; i < n; i++) {
        freq[arr[i]]++; // Update frequency of each element

        if (freq[arr[i]] == 2) {
            (*total_duplicates)++;
        }

        if (freq[arr[i]] > freq[*most_repeating_element]) {
            *most_repeating_element = arr[i];
        }
    }
}

int main() {
    int n;
    printf("Enter how many numbers you want to read from the file: ");
    scanf("%d", &n);

    int arr[n];

    // Read numbers from the file and store them in the array
    FILE *file;
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    printf("The content of the array: ");
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
        printf("%d ", arr[i]);
    }
    printf("\n");

    fclose(file);

    // Find the total number of duplicate elements and the most repeating element in the array
    int total_duplicates, most_repeating_element;
    duplicate_elements(arr, n, &total_duplicates, &most_repeating_element);

    printf("Total number of duplicate values = %d\n", total_duplicates);
    printf("The most repeating element in the array = %d\n", most_repeating_element);

    return 0;
}
