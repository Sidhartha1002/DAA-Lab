#include <stdio.h>
#include <string.h> // Include the string.h header for strcpy function

void insertionSort(int arr[], int n, int *comparisons) {
    // ... (rest of the insertionSort function remains unchanged)
}

void displayArray(int arr[], int n) {
    // ... (rest of the displayArray function remains unchanged)
}

int main() {
    int choice;
    printf("MAIN MENU (INSERTION SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. EXIT\n");
    
    printf("Enter option: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 3) {
        char inputFileName[20];
        char outputFileName[20];
        
        switch (choice) {
            case 1:
                strcpy(inputFileName, "inAsce.dat");
                strcpy(outputFileName, "outInsAsce.dat");
                break;
            case 2:
                strcpy(inputFileName, "inDesc.dat");
                strcpy(outputFileName, "outInsDesc.dat");
                break;
            case 3:
                strcpy(inputFileName, "inRand.dat");
                strcpy(outputFileName, "outInsRand.dat");
                break;
        }

        // ... (rest of the main function remains unchanged)
    } else if (choice == 4) {
        printf("Exiting program.\n");
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
