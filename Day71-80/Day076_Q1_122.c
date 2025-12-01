#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    char filename[100];
    char text[500];

    printf("Enter filename to append to: ");
    scanf("%99s", filename);
    
    getchar();

    printf("Enter text to append: ");
    fgets(text, sizeof(text), stdin);

    file = fopen(filename, "a");

    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return 1;
    }

    fprintf(file, "%s", text);

    fclose(file);
    
    printf("File updated successfully with appended text.\n");
    
    return 0;
}