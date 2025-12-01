#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char line[256]; 
    
    file = fopen("info.txt", "r");
    
    if (file == NULL) {
        printf("Error: Could not open file 'info.txt'\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    
    fclose(file);
    
    return 0;
}