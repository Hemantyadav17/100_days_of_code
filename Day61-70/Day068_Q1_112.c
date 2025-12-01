#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *nums = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    int xor_all = 0;
    for(int i = 0; i <= n; i++) {
        xor_all ^= i;
    }
    for(int i = 0; i < n; i++) {
        xor_all ^= nums[i];
    }
    printf("%d\n", xor_all);
    free(nums);
    return 0;
}
