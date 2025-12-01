#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *file;
    char ch;
    int characters = 0, words = 0, lines = 0;
    int in_word = 0; 

    file = fopen("sample.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file 'sample.txt'\n");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        characters++;

        if (ch == '\n') {
            lines++;
        }

        if (isspace(ch)) {
            if (in_word) {
                words++;
                in_word = 0;
            }
        } else {
            in_word = 1;
        }
    }

    if (in_word) {
        words++;
    }

    if (characters > 0 && ch != '\n') {
        lines++;
    }

    fclose(file);

    printf("Characters: %d\n", characters);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);
    
    return 0;
}