#include <stdio.h>
int main() {
    int n, i;
    int arr[100];
    int posCount = 0, negCount = 0, zeroCount = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        if (arr[i] > 0)
            posCount++;
        else if (arr[i] < 0)
            negCount++;
        else
            zeroCount++;
    }

    printf("Positive numbers = %d\n", posCount);
    printf("Negative numbers = %d\n", negCount);
    printf("Zeros = %d\n", zeroCount);

    return 0;
}

