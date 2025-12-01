#include <stdio.h>
#include <string.h>

enum Role {
    ADMIN,
    USER,
    GUEST
};

int main() {
    char roleStr[20];
    enum Role role;

    if (scanf("%s", roleStr) != 1) {
        return 0;
    }

    if (strcmp(roleStr, "ADMIN") == 0) {
        role = ADMIN;
    } else if (strcmp(roleStr, "USER") == 0) {
        role = USER;
    } else if (strcmp(roleStr, "GUEST") == 0) {
        role = GUEST;
    } else {
        return 0;   
    }

    switch (role) {
        case ADMIN:
            printf("Welcome Admin!\n");
            break;
        case USER:
            printf("Welcome User!\n");
            break;
        case GUEST:
            printf("Welcome Guest!\n");
            break;
    }

    return 0;
}
