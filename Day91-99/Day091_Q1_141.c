#include <stdio.h>

struct Student {
    char name[50];
    int roll_no;
    int marks;
};

int main() {
    struct Student s;

    printf("Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    size_t len = 0;
    while (s.name[len] != '\0') len++;
    if (len > 0 && s.name[len-1] == '\n') {
        s.name[len-1] = '\0';
    }

    printf("Roll: ");
    scanf("%d", &s.roll_no);

    printf("Marks: ");
    scanf("%d", &s.marks);

    printf("Name: %s | Roll: %d | Marks: %d\n", s.name, s.roll_no, s.marks);

    return 0;
}
