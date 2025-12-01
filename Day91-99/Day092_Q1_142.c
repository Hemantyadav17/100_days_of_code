#include <stdio.h>

struct Student {
    char name[50];
    int roll_no;
    int marks;
};

int main() {
    struct Student students[5];

    for (int i = 0; i < 5; i++) {
        printf("Enter details for student %d\n", i + 1);

        printf("Name: ");
        getchar();
        fgets(students[i].name, sizeof(students[i].name), stdin);
        int len = 0;
        while (students[i].name[len] != '\0') len++;
        if (len > 0 && students[i].name[len - 1] == '\n') {
            students[i].name[len - 1] = '\0';
        }

        printf("Roll: ");
        scanf("%d", &students[i].roll_no);

        printf("Marks: ");
        scanf("%d", &students[i].marks);
    }

    printf("\nList of Students:\n");
    printf("Name\t\tRoll\tMarks\n");
    printf("---------------------------------\n");
    for (int i = 0; i < 5; i++) {
        printf("%-15s\t%d\t%d\n", students[i].name, students[i].roll_no, students[i].marks);
    }

    return 0;
}

