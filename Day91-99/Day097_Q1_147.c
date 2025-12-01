#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    struct Employee emp;

    printf("Enter employee ID: ");
    scanf("%d", &emp.id);

    printf("Enter employee name: ");
    getchar(); 
    fgets(emp.name, sizeof(emp.name), stdin);
    int len = 0;
    while (emp.name[len] != '\0') len++;
    if (len > 0 && emp.name[len - 1] == '\n') {
        emp.name[len - 1] = '\0';
    }

    printf("Enter employee salary: ");
    scanf("%f", &emp.salary);

    FILE *fp = fopen("employee.dat", "wb");
    if (fp == NULL) {
        perror("File opening failed");
        return 1;
    }
    fwrite(&emp, sizeof(struct Employee), 1, fp);
    fclose(fp);

    struct Employee emp_read;
    fp = fopen("employee.dat", "rb");
    if (fp == NULL) {
        perror("File opening failed");
        return 1;
    }
    fread(&emp_read, sizeof(struct Employee), 1, fp);
    fclose(fp);

    printf("\nEmployee data read from file:\n");
    printf("ID: %d\n", emp_read.id);
    printf("Name: %s\n", emp_read.name);
    printf("Salary: %.2f\n", emp_read.salary);

    return 0;
}
