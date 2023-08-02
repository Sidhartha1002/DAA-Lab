#include <stdio.h>

// Function to swap two elements
void EXCHANGE(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

// Function to rotate the array right for p2 elements by 1 position
void ROTATE_RIGHT(int *arr, int p2) {
    int i;
    for (i = 0; i < p2; i++) {
        EXCHANGE(&arr[i], &arr[i + 1]);
    }
}

int main() {
    int N, i;
    printf("Enter the size of the array: ");
    scanf("%d", &N);

    int A[N];
    printf("Enter the array elements: ");
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int p2;
    printf("Enter the number of elements to rotate: ");
    scanf("%d", &p2);

    printf("Before ROTATE: ");
    for (i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    ROTATE_RIGHT(A, p2);

    printf("After ROTATE: ");
    for (i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
