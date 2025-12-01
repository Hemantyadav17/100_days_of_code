#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    int number;
    int sum = 0;
    int count = 0;
    double average = 0.0;
    
    file = fopen("numbers.txt", "r");
    
    if (file == NULL) {
        printf("Error: Could not open file 'numbers.txt'\n");
        return 1;
    }
    
    while (fscanf(file, "%d", &number) == 1) {
        sum += number;
        count++;
    }
    
    fclose(file);
    
    if (count == 0) {
        printf("Error: No integers found in the file\n");
        return 1;
    }
    
    average = (double)sum / count;

    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", average);
    
    return 0;
}