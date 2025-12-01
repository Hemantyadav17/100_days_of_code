#include <stdio.h>
#include <string.h>

int main() {
    char str[200], word[50];
    int i = 0, j = 0, k;

    printf("Enter a sentence: ");
    gets(str);

    printf("Sentence after reversing each word:\n");

    while (1) {
        if (str[i] != ' ' && str[i] != '\0') {
            word[j++] = str[i];
        } else {
            word[j] = '\0';
            for (k = j - 1; k >= 0; k--)
                printf("%c", word[k]);
            if (str[i] == ' ')
                printf(" ");
            j = 0;
        }

        if (str[i] == '\0')
            break;

        i++;
    }

    printf("\n");
    return 0;
}
