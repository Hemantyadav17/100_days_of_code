#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum Months {
    JAN = 1,
    FEB = 2,
    MAR = 3,
    APR = 4,
    MAY = 5,
    JUN = 6,
    JUL = 7,
    AUG = 8,
    SEP = 9,
    OCT = 10,
    NOV = 11,
    DEC = 12
};

int main() {
    char month_input[20];
    enum Months month;
    int days;
    
    printf("Enter month name (JAN, FEB, MAR, etc.): ");
    scanf("%s", month_input);

    for (int i = 0; month_input[i]; i++) {
        month_input[i] = toupper(month_input[i]);
    }
    
    if (strcmp(month_input, "JAN") == 0) {
        month = JAN;
    } else if (strcmp(month_input, "FEB") == 0) {
        month = FEB;
    } else if (strcmp(month_input, "MAR") == 0) {
        month = MAR;
    } else if (strcmp(month_input, "APR") == 0) {
        month = APR;
    } else if (strcmp(month_input, "MAY") == 0) {
        month = MAY;
    } else if (strcmp(month_input, "JUN") == 0) {
        month = JUN;
    } else if (strcmp(month_input, "JUL") == 0) {
        month = JUL;
    } else if (strcmp(month_input, "AUG") == 0) {
        month = AUG;
    } else if (strcmp(month_input, "SEP") == 0) {
        month = SEP;
    } else if (strcmp(month_input, "OCT") == 0) {
        month = OCT;
    } else if (strcmp(month_input, "NOV") == 0) {
        month = NOV;
    } else if (strcmp(month_input, "DEC") == 0) {
        month = DEC;
    } else {
        printf("Invalid month!\n");
        return 1;
    }

    switch (month) {
        case JAN:
        case MAR:
        case MAY:
        case JUL:
        case AUG:
        case OCT:
        case DEC:
            days = 31;
            printf("%d days\n", days);
            break;
        case APR:
        case JUN:
        case SEP:
        case NOV:
            days = 30;
            printf("%d days\n", days);
            break;
        case FEB:
            printf("28 or 29 days\n");
            break;
        default:
            printf("Invalid month!\n");
    }
    
    return 0;
}