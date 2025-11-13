#include <stdio.h>
int main() {
    int i;

    // First single star
    printf("*\n\n");

    // Two stars
    for (i = 1; i <= 2; i++)
        printf("*\n");
    printf("\n");

    // Five stars
    for (i = 1; i <= 5; i++)
        printf("*\n");
    printf("\n");

    // Three stars
    for (i = 1; i <= 3; i++)
        printf("*\n");
    printf("\n");

    // Last single star
    printf("*\n");

    return 0;
}

