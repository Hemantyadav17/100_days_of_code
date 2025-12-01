#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int maxSum = arr[0];
    int currentSum = arr[0];
    
    for (int i = 1; i < n; i++) {
        currentSum = (arr[i] > currentSum + arr[i]) ? arr[i] : currentSum + arr[i];
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }
    printf("%d\n", maxSum);
    
    return 0;
}