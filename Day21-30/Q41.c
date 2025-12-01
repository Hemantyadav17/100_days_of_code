#include <stdio.h>
#include <math.h>

int main() {
    int num, firstDigit, lastDigit, digits, swappedNum;

    printf("Enter a number: ");
    scanf("%d", &num);

    lastDigit = num % 10;
    digits = (int)log10(num);
    firstDigit = num / pow(10, digits);

    swappedNum = lastDigit * pow(10, digits) + (num % (int)pow(10, digits)) / 10 * 10 + firstDigit;

    printf("Number after swapping first and last digits: %d\n", swappedNum);

    return 0;
}

