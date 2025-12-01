/* Q116: Write a program to take an integer array nums (only positive integers) and an integer target as input. 
Find two distinct indices i and j such that nums[i] + nums[j] equals the target. 
Assume exactly one solution exists. Print the indices in any order. If no solution exists, print "-1 -1". */

#include <stdio.h>

int main() {
    int n, target, i, j;
    int arr[500];

    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d", &target);

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                printf("%d %d", i, j);
                return 0;
            }
        }
    }

    printf("-1 -1");
    return 0;
}
