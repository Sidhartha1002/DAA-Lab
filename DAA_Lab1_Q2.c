#include <stdio.h>

void calculate_prefix_sum(int arr[], int prefixSum[], int n) {
    prefixSum[0] = arr[0];

    // Calculate the prefix sum for the rest of the elements
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    int prefixSum[n];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate the prefix sum
    calculate_prefix_sum(arr, prefixSum, n);

    printf("Output Array (Prefix Sum): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", prefixSum[i]);
    }
    printf("\n");

    return 0;
}
