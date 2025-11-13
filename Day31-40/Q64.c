#include <stdio.h>
int main() {
    long num;
    int digit, count[10] = {0}, max = 0, mostFreq = 0;

    printf("Enter an integer: ");
    scanf("%ld", &num);

    if (num < 0)
        num = -num;

    while (num > 0) {
        digit = num % 10;
        count[digit]++;
        num /= 10;
    }

    for (int i = 0; i < 10; i++) {
        if (count[i] > max) {
            max = count[i];
            mostFreq = i;
        }
    }

    printf("The digit that occurs most frequently is: %d\n", mostFreq);
    printf("It occurs %d times.\n", max);

    return 0;
}
