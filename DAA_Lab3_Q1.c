#include <stdio.h>

int binary_search_leftmost(int arr[], int size, int key, int *comparisons) {
    int left = 0, right = size - 1;
    int index = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        (*comparisons)++;

        if (arr[mid] == key) {
            index = mid;
            right = mid - 1;  // Move left to find leftmost appearance
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return index;
}

int main() {
    int size, key;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    int comparisons = 0;
    int index = binary_search_leftmost(arr, size, key, &comparisons);

    if (index != -1) {
        printf("%d found at index position %d\n", key, index);
        printf("Number of comparisons: %d\n", comparisons);
    } else {
        printf("%d not found in the array\n", key);
    }

    return 0;
}
