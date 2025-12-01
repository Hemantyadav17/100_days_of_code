/* Q148: Take two structs as input and check if they are identical. */

#include <stdio.h>

struct Data {
    int a;
    int b;
    float c;
};

int main() {
    struct Data x, y;

    scanf("%d %d %f", &x.a, &x.b, &x.c);
    scanf("%d %d %f", &y.a, &y.b, &y.c);

    if (x.a == y.a && x.b == y.b && x.c == y.c)
        printf("Identical");
    else
        printf("Not Identical");

    return 0;
}
