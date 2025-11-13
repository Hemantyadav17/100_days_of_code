#include <stdio.h>
int main() {
    int arr[100], n, i;
    int largest, secondLargest;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (n < 2) {
        printf("Array must have at least two elements.\n");
        return 0;
    }

    largest = secondLargest = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    if (largest == secondLargest)
        printf("All elements are equal. No second largest element.\n");
    else
        printf("Second largest element = %d\n", secondLargest);

    return 0;
}
