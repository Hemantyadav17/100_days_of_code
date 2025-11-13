#include <stdio.h>
int main() {
    int n;
    float sum = 0.0;
    int numerator = 2, denominator = 3;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        sum += (float)numerator / denominator;
        numerator += 2;
        denominator += 4;
    }

    printf("Sum of the series up to %d terms = %.4f\n", n, sum);

    return 0;
}
