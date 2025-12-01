#include <stdio.h>
#include <stdlib.h>

#define MAX 100001

int main() {
    int n;
    scanf("%d", &n);
    int *seen = (int *)calloc(MAX, sizeof(int));
    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        if(seen[num]) {
            printf("%d\n", num);
            free(seen);
            return 0;
        }
        seen[num] = 1;
    }
    printf("No duplicate found\n");
    free(seen);
    return 0;
}