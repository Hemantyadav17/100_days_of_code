#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int roll_no;
    int marks;
};

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    clearInputBuffer();

    struct Student* students = malloc(n * sizeof(struct Student));

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d\n", i + 1);

        printf("Name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);

        int len = 0;
        while (students[i].name[len] != '\0') len++;
        if (len > 0 && students[i].name[len - 1] == '\n')
            students[i].name[len - 1] = '\0';

        printf("Roll: ");
        scanf("%d", &students[i].roll_no);

        printf("Marks: ");
        scanf("%d", &students[i].marks);

        clearInputBuffer();
    }

    int topperIndex = 0;
    for (int i = 1; i < n; i++) {
        if (students[i].marks > students[topperIndex].marks)
            students[topperIndex] = students[i]; // (or store index)
    }

    printf("\nTopper: %s (Marks: %d)\n",
           students[topperIndex].name,
           students[topperIndex].marks);

    free(students);
    return 0;
}
