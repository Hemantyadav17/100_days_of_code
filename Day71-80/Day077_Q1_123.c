#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *input_file, *output_file;
    char ch;

    input_file = fopen("input.txt", "r");

    if (input_file == NULL) {
        printf("Error: Could not open file 'input.txt'\n");
        return 1;
    }

    output_file = fopen("output.txt", "w");

    if (output_file == NULL) {
        printf("Error: Could not open file 'output.txt'\n");
        fclose(input_file);
        return 1;
    }

    while ((ch = fgetc(input_file)) != EOF) {
        ch = toupper(ch);
        
        fputc(ch, output_file);
    }

    fclose(input_file);
    fclose(output_file);
    
    printf("Text converted to uppercase successfully.\n");
    printf("Output written to output.txt\n");
    
    return 0;
}