#include <stdio.h>

int main() {
    int n, k;
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);
    for (int i = 0; i <= n - k; i++) {
        int firstNegative = 0;
        for (int j = i; j < i + k; j++) {
            if (arr[j] < 0) {
                firstNegative = arr[j];
                break;
            }
        }
        if (i == 0) {
            printf("%d", firstNegative);
        } else {
            printf(" %d", firstNegative);
        }
    }
    
    printf("\n");
    
    return 0;
}