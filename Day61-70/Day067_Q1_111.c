/* Q117: Write a program to take two sorted arrays of size m and n as input. 
Merge both arrays such that the merged array is also sorted. Print the merged array. */

#include <stdio.h>

int main() {
    int m, n, i = 0, j = 0, k = 0;
    int a[500], b[500], c[1000];

    scanf("%d", &m);
    for (i = 0; i < m; i++) scanf("%d", &a[i]);

    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &b[i]);

    i = j = 0;

    while (i < m && j < n) c[k++] = a[i] < b[j] ? a[i++] : b[j++];

    while (i < m) c[k++] = a[i++];
    while (j < n) c[k++] = b[j++];

    for (i = 0; i < k; i++) printf("%d ", c[i]);

    return 0;
}
