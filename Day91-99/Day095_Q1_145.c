#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int roll;
    int marks;
};

struct Student findTopStudent(struct Student students[], int n) {
    struct Student topStudent = students[0];
    
    for (int i = 1; i < n; i++) {
        if (students[i].marks > topStudent.marks) {
            topStudent = students[i];
        }
    }
    
    return topStudent;
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student* students = malloc(n * sizeof(struct Student));

    printf("Enter student details (name roll marks):\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%49s %d %d", students[i].name, &students[i].roll, &students[i].marks);
    }

    struct Student top = findTopStudent(students, n);

    printf("\nTop Student: %s | Roll: %d | Marks: %d\n",
           top.name, top.roll, top.marks);

    free(students);
    return 0;
}
