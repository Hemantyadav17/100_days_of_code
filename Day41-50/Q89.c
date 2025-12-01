#include <stdio.h>
int main() {
    char str[200], ch;
    int i = 0, count = 0;

    printf("Enter a string: ");
    gets(str);

    printf("Enter the character to count: ");
    scanf("%c", &ch);

    while (str[i] != '\0') {
        if (str[i] == ch)
            count++;
        i++;
    }

    printf("The character '%c' occurs %d times in the string.\n", ch, count);

    return 0;
}
