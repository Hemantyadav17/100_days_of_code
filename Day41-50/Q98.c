#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    int len, i, lastSpace = -1;

    printf("Enter a full name: ");
    gets(name);

    len = strlen(name);

    for (i = len - 1; i >= 0; i--) {
        if (name[i] == ' ') {
            lastSpace = i;
            break;
        }
    }

    for (i = 0; i < lastSpace; i++) {
        if (i == 0 && name[i] != ' ')
            printf("%c. ", name[i]);
        else if (name[i] == ' ' && name[i + 1] != ' ')
            printf("%c. ", name[i + 1]);
    }

    for (i = lastSpace + 1; i < len; i++) {
        printf("%c", name[i]);
    }

    printf("\n");
    return 0;
}
