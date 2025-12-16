#include <stdio.h>
#include <string.h>

#define SUBJECTS 5
#define FILENAME "students.txt"

struct Student {
    int roll;
    char name[50];
    int age;
    float marks[SUBJECTS];
    float total;
    float average;
    char grade;
};

// Function declarations
float calculateTotal(float marks[], int n);
char calculateGrade(float avg);
void removeNewline(char str[]);
int readStudent(FILE *fp, struct Student *s);
void writeStudent(FILE *fp, struct Student s);
void addStudent();
void viewStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

int main() {
    int choice;

    while (1) {
        printf("\n============================================\n");
        printf("        STUDENT RECORD MANAGEMENT SYSTEM\n");
        printf("============================================\n");
        printf("1. Add Student Record\n");
        printf("2. View All Students\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Update Student Record\n");
        printf("5. Delete Student Record\n");
        printf("0. Exit\n");
        printf("--------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 0:
                printf("\nThank you for using the system!\n");
                return 0;
            default:
                printf("\nInvalid choice! Try again.\n");
        }

        printf("\nPress Enter to continue...");
        getchar();
    }
    return 0;
}

// Helper functions
float calculateTotal(float marks[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum += marks[i];
    return sum;
}

char calculateGrade(float avg) {
    if (avg >= 90) return 'A';
    else if (avg >= 75) return 'B';
    else if (avg >= 60) return 'C';
    else if (avg >= 40) return 'D';
    else return 'F';
}

void removeNewline(char str[]) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}

// Unified read/write functions
int readStudent(FILE *fp, struct Student *s) {
    return fscanf(fp, "%d|%49[^|]|%d|%f|%f|%f|%f|%f|%f|%f|%c\n",
                  &s->roll, s->name, &s->age,
                  &s->marks[0], &s->marks[1], &s->marks[2],
                  &s->marks[3], &s->marks[4],
                  &s->total, &s->average, &s->grade) == 11;
}

void writeStudent(FILE *fp, struct Student s) {
    fprintf(fp, "%d|%s|%d|%.2f|%.2f|%.2f|%.2f|%.2f|%.2f|%.2f|%c\n",
            s.roll, s.name, s.age,
            s.marks[0], s.marks[1], s.marks[2], s.marks[3], s.marks[4],
            s.total, s.average, s.grade);
}

// CRUD operations
void addStudent() {
    struct Student s;
    FILE *fp = fopen(FILENAME, "a");
    if (!fp) { printf("\nError opening file.\n"); return; }

    printf("\nEnter Roll Number: ");
    scanf("%d", &s.roll);
    getchar();

    // Check duplicate
    FILE *check = fopen(FILENAME, "r");
    int exists = 0;
    struct Student temp;
    if (check) {
        while (readStudent(check, &temp)) {
            if (temp.roll == s.roll) { exists = 1; break; }
        }
        fclose(check);
    }
    if (exists) { printf("\nRoll number already exists!\n"); fclose(fp); return; }

    printf("Enter Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    removeNewline(s.name);

    printf("Enter Age: ");
    scanf("%d", &s.age);

    for (int i = 0; i < SUBJECTS; i++) {
        do {
            printf("Enter Marks for Subject %d (0-100): ", i + 1);
            scanf("%f", &s.marks[i]);
            if (s.marks[i] < 0 || s.marks[i] > 100)
                printf("Invalid marks! Enter between 0 and 100.\n");
        } while (s.marks[i] < 0 || s.marks[i] > 100);
    }

    s.total = calculateTotal(s.marks, SUBJECTS);
    s.average = s.total / SUBJECTS;
    s.grade = calculateGrade(s.average);

    writeStudent(fp, s);
    fclose(fp);
    printf("\nStudent record added successfully!\n");
}

void viewStudents() {
    FILE *fp = fopen(FILENAME, "r");
    if (!fp) { printf("\nNo records found.\n"); return; }

    struct Student s;
    int count = 0;

    printf("\n===================================================================================\n");
    printf("ROLL  | NAME                 | AGE | MARK1  MARK2  MARK3  MARK4  MARK5 | TOTAL | AVG  | GRADE\n");
    printf("-----------------------------------------------------------------------------------\n");

    while (readStudent(fp, &s)) {
        printf("%-5d | %-20s | %-3d | %6.1f %6.1f %6.1f %6.1f %6.1f | %5.1f | %4.1f | %c\n",
               s.roll, s.name, s.age,
               s.marks[0], s.marks[1], s.marks[2], s.marks[3], s.marks[4],
               s.total, s.average, s.grade);
        count++;
    }

    if (count == 0) printf("No student records available.\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("Total Students: %d\n", count);
    printf("===================================================================================\n");
    fclose(fp);
}

void searchStudent() {
    FILE *fp = fopen(FILENAME, "r");
    if (!fp) { printf("\nNo records found.\n"); return; }

    int roll, found = 0;
    struct Student s;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    while (readStudent(fp, &s)) {
        if (s.roll == roll) {
            printf("\nRecord Found:\n");
            printf("-------------------------------------------------\n");
            printf("Roll Number : %d\nName        : %s\nAge         : %d\n", s.roll, s.name, s.age);
            printf("Marks       : %.1f %.1f %.1f %.1f %.1f\n",
                   s.marks[0], s.marks[1], s.marks[2], s.marks[3], s.marks[4]);
            printf("Total       : %.1f\nAverage     : %.1f\nGrade       : %c\n", s.total, s.average, s.grade);
            printf("-------------------------------------------------\n");
            found = 1;
            break;
        }
    }

    if (!found) printf("\nRecord not found!\n");
    fclose(fp);
}

void updateStudent() {
    FILE *fp = fopen(FILENAME, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp) { printf("\nError opening files.\n"); return; }

    int roll, found = 0;
    struct Student s;
    printf("\nEnter Roll Number to update: ");
    scanf("%d", &roll);
    getchar();

    while (readStudent(fp, &s)) {
        if (s.roll == roll) {
            printf("\nEnter New Name: ");
            fgets(s.name, sizeof(s.name), stdin);
            removeNewline(s.name);

            printf("Enter New Age: ");
            scanf("%d", &s.age);

            for (int i = 0; i < SUBJECTS; i++) {
                do {
                    printf("Enter Marks for Subject %d (0-100): ", i + 1);
                    scanf("%f", &s.marks[i]);
                    if (s.marks[i] < 0 || s.marks[i] > 100)
                        printf("Invalid marks! Enter between 0 and 100.\n");
                } while (s.marks[i] < 0 || s.marks[i] > 100);
            }

            s.total = calculateTotal(s.marks, SUBJECTS);
            s.average = s.total / SUBJECTS;
            s.grade = calculateGrade(s.average);
            found = 1;
        }
        writeStudent(temp, s);
    }

    fclose(fp);
    fclose(temp);

    if (found) {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("\nRecord updated successfully!\n");
    } else {
        printf("\nRecord not found.\n");
        remove("temp.txt");
    }
}

void deleteStudent() {
    FILE *fp = fopen(FILENAME, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp) { printf("\nError opening files.\n"); return; }

    int roll, found = 0;
    struct Student s;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    while (readStudent(fp, &s)) {
        if (s.roll != roll)
            writeStudent(temp, s);
        else
            found = 1;
    }

    fclose(fp);
    fclose(temp);

    if (found) {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("\nRecord deleted successfully!\n");
    } else {
        printf("\nRecord not found.\n");
        remove("temp.txt");
    }
}