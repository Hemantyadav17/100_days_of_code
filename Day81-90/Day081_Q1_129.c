#include <stdio.h>

enum Days {
    SUNDAY = 0,
    MONDAY = 1,
    TUESDAY = 2,
    WEDNESDAY = 3,
    THURSDAY = 4,
    FRIDAY = 5,
    SATURDAY = 6
};

int main() {
    char *day_names[] = {
        "SUNDAY",
        "MONDAY",
        "TUESDAY",
        "WEDNESDAY",
        "THURSDAY",
        "FRIDAY",
        "SATURDAY"
    };
    
    printf("Days of the Week:\n");
    printf("================\n");
    
    for (int i = SUNDAY; i <= SATURDAY; i++) {
        printf("%s = %d\n", day_names[i], i);
    }
    
    return 0;
}