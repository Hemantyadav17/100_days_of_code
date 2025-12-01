#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int roll;
    int marks;
} Student;

void write_records() {
    FILE *file;
    Student student;
    int n, i;
    
    file = fopen("students.txt", "w");
    
    if (file == NULL) {
        printf("Error: Could not open file 'students.txt'\n");
        return;
    }

    printf("Enter number of students: ");
    scanf("%d", &n);
    getchar(); 
    
    for (i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        
        printf("Enter name: ");
        fgets(student.name, MAX_NAME_LENGTH, stdin);
        student.name[strcspn(student.name, "\n")] = 0;
        
        printf("Enter roll number: ");
        scanf("%d", &student.roll);
        
        printf("Enter marks: ");
        scanf("%d", &student.marks);
        getchar();  

        fprintf(file, "%s %d %d\n", student.name, student.roll, student.marks);
    }
    
    fclose(file);
    printf("\n%d student records written to file successfully.\n", n);
}

void read_records() {
    FILE *file;
    Student student;
    
    file = fopen("students.txt", "r");
    
    if (file == NULL) {
        printf("Error: Could not open file 'students.txt'\n");
        return;
    }
    
    printf("\n--- Student Records ---\n");
    
    while (fscanf(file, "%s %d %d", student.name, &student.roll, &student.marks) == 3) {
        printf("Name: %s | Roll: %d | Marks: %d\n", 
               student.name, student.roll, student.marks);
    }
    
    fclose(file);
}

int main() {
    int choice;
    
    while (1) {
        printf("\n--- Student Record Management ---\n");
        printf("1. Write student records\n");
        printf("2. Read student records\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                write_records();
                break;
            case 2:
                read_records();
                break;
            case 3:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}