#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary using recursion
void decimalToBinary(FILE *input, FILE *output, int n) {
    if (n <= 0) {
        return;
    }

    int decimal;
    fscanf(input, "%d", &decimal);

    // Recursively call the function with n-1 and process the next decimal
    decimalToBinary(input, output, n - 1);

    // Convert decimal to binary
    int binary[16] = {0}; // Assuming 16-bit binary representation
    int index = 15;

    while (decimal > 0) {
        binary[index] = decimal % 2;
        decimal /= 2;
        index--;
    }

    // Write the binary representation to the output file
    fprintf(output, "The binary equivalent of %d is ", decimal);
    for (int i = 0; i < 16; i++) {
        fprintf(output, "%d", binary[i]);
    }
    fprintf(output, "\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <n> <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    FILE *input_file = fopen(argv[2], "r");
    FILE *output_file = fopen(argv[3], "w");

    if (!input_file) {
        printf("Error opening the source file: %s\n", argv[2]);
        return 1;
    }

    if (!output_file) {
        printf("Error opening the destination file: %s\n", argv[3]);
        return 1;
    }

    decimalToBinary(input_file, output_file, n);

    // Close the files
    fclose(input_file);
    fclose(output_file);

    // Display the contents of the output file
    FILE *output_file_read = fopen(argv[3], "r");
    char line[100];

    printf("Content of the first '%d' decimal and their equivalent binary numbers:\n", n);
    while (fgets(line, sizeof(line), output_file_read)) {
        printf("%s", line);
    }

    fclose(output_file_read);

    return 0;
}
