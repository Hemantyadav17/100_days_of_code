#include <stdio.h>
int main() {
    int arr[100], n, k, i;
    int temp[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter number of positions to rotate (k): ");
    scanf("%d", &k);

    k = k % n; // handle cases where k > n

    for (i = 0; i < n; i++) {
        temp[(i + k) % n] = arr[i];
    }

    for (i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    printf("Array after right rotation by %d positions:\n", k);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}

