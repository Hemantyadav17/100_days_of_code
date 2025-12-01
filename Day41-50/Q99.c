#include <stdio.h>
#include <string.h>

int main() {
    char date[15], month[3];
    int day, year, m;

    printf("Enter date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &m, &year);

    switch (m) {
        case 1:  strcpy(month, "Jan"); break;
        case 2:  strcpy(month, "Feb"); break;
        case 3:  strcpy(month, "Mar"); break;
        case 4:  strcpy(month, "Apr"); break;
        case 5:  strcpy(month, "May"); break;
        case 6:  strcpy(month, "Jun"); break;
        case 7:  strcpy(month, "Jul"); break;
        case 8:  strcpy(month, "Aug"); break;
        case 9:  strcpy(month, "Sep"); break;
        case 10: strcpy(month, "Oct"); break;
        case 11: strcpy(month, "Nov"); break;
        case 12: strcpy(month, "Dec"); break;
        default: strcpy(month, "Invalid"); break;
    }

    if (strcmp(month, "Invalid") == 0)
        printf("Invalid month entered.\n");
    else
        printf("Formatted date: %02d-%s-%04d\n", day, month, year);

    return 0;
}
