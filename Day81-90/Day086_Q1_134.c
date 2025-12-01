#include <stdio.h>
#include <string.h>

enum Operation {
    ADD,
    SUBTRACT,
    MULTIPLY
};

int main() {
    char opStr[20];
    int a, b;
    enum Operation op;

    if (scanf("%s %d %d", opStr, &a, &b) != 3) {
        return 0;
    }

    if (strcmp(opStr, "ADD") == 0) {
        op = ADD;
    } else if (strcmp(opStr, "SUBTRACT") == 0) {
        op = SUBTRACT;
    } else if (strcmp(opStr, "MULTIPLY") == 0) {
        op = MULTIPLY;
    } else {
        return 0;
    }

    switch (op) {
        case ADD:
            printf("%d\n", a + b);
            break;
        case SUBTRACT:
            printf("%d\n", a - b);
            break;
        case MULTIPLY:
            printf("%d\n", a * b);
            break;
    }

    return 0;
}
