#include <stdio.h>
int main() {
    int n, i, j;
    int matrix[10][10];

    printf("Enter the order of the square matrix: ");
    scanf("%d", &n);

    printf("Enter elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Diagonal traversal of the matrix:\n");

    for (int col = 0; col < n; col++) {
        i = 0;
        j = col;
        while (j >= 0 && i < n) {
            printf("%d ", matrix[i][j]);
            i++;
            j--;
        }
        printf("\n");
    }

    for (int row = 1; row < n; row++) {
        i = row;
        j = n - 1;
        while (i < n && j >= 0) {
            printf("%d ", matrix[i][j]);
            i++;
            j--;
        }
        printf("\n");
    }

    return 0;
}
