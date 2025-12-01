#include <stdio.h>

enum Color {
    RED,
    YELLOW,
    GREEN,
    COLOR_COUNT
};

int main() {
    const char *colorNames[] = {"RED", "YELLOW", "GREEN"};

    for (int i = 0; i < COLOR_COUNT; i++) {
        printf("%s=%d\n", colorNames[i], i);
    }

    return 0;
}
