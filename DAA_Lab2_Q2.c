#include <stdio.h>

// Function to calculate GCD using recursion
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    FILE *output_file = fopen(argv[2], "w");

    if (!input_file) {
        printf("Error opening the source file: %s\n", argv[1]);
        return 1;
    }

    if (!output_file) {
        printf("Error opening the destination file: %s\n", argv[2]);
        return 1;
    }

    int num1, num2;

    // Read pairs of numbers from the input file and calculate GCD
    while (fscanf(input_file, "%d %d", &num1, &num2) != EOF) {
        int result = gcd(num1, num2);
        fprintf(output_file, "The GCD of %d and %d is %d\n", num1, num2, result);
    }

    // Close the files
    fclose(input_file);
    fclose(output_file);

    // Display the contents of the output file
    FILE *output_file_read = fopen(argv[2], "r");
    char line[100];

    printf("Contents of the output file %s:\n", argv[2]);
    while (fgets(line, sizeof(line), output_file_read)) {
        printf("%s", line);
    }

    fclose(output_file_read);

    return 0;
}
