#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], concat[200];

    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);

    if (strlen(str1) != strlen(str2)) {
        printf("Strings are not rotations of each other.\n");
        return 0;
    }

    strcpy(concat, str1);
    strcat(concat, str1);

    if (strstr(concat, str2) != NULL)
        printf("Strings are rotations of each other.\n");
    else
        printf("Strings are not rotations of each other.\n");

    return 0;
}
