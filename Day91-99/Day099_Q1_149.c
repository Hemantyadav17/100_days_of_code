/* Q149: Use malloc() to allocate structure memory dynamically and print details. */

#include <stdio.h>
#include <stdlib.h>

struct Info {
    int id;
    float value;
};

int main() {
    struct Info *p = (struct Info*)malloc(sizeof(struct Info));

    scanf("%d %f", &p->id, &p->value);

    printf("%d %f", p->id, p->value);

    free(p);
    return 0;
}
