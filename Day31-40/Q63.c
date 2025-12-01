#include <stdio.h>
int main() {
    int arr1[100], arr2[100], arr3[200];
    int n1, n2, n3, i, j;

    printf("Enter number of elements in first array: ");
    scanf("%d", &n1);
    printf("Enter %d elements:\n", n1);
    for (i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter number of elements in second array: ");
    scanf("%d", &n2);
    printf("Enter %d elements:\n", n2);
    for (i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    n3 = n1 + n2;

    for (i = 0; i < n1; i++) {
        arr3[i] = arr1[i];
    }
    for (j = 0; j < n2; j++) {
        arr3[i + j] = arr2[j];
    }

    printf("Merged array:\n");
    for (i = 0; i < n3; i++) {
        printf("%d ", arr3[i]);
    }

    printf("\n");
    return 0;
}
