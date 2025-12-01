#include <stdio.h>

struct Student {
    char name[50];
    int roll_no;
    int marks;
};

void printStudent(struct Student s) {
    printf("Name: %s | Roll: %d | Marks: %d\n", s.name, s.roll_no, s.marks);
}

int main() {
    struct Student s;

    printf("Enter student details:\n");

    printf("Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    int len = 0;
    while (s.name[len] != '\0') len++;
    if (len > 0 && s.name[len - 1] == '\n') {
        s.name[len - 1] = '\0';
    }

    printf("Roll: ");
    scanf("%d", &s.roll_no);

    printf("Marks: ");
    scanf("%d", &s.marks);

    printStudent(s);

    return 0;
}
