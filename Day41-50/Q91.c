#include <stdio.h>
int main() {
    char str[200], result[200];
    int i = 0, j = 0;

    printf("Enter a string: ");
    gets(str);

    while (str[i] != '\0') {
        char ch = str[i];
        if (!(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
              ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
            result[j] = str[i];
            j++;
        }
        i++;
    }
    result[j] = '\0';

    printf("String after removing vowels: %s\n", result);

    return 0;
}
