#include <stdio.h>
#include <string.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Employee {
    char name[50];
    int id;
    struct Date joiningDate;
};

int main() {
    struct Employee emp;
    
    printf("Enter Employee Name: ");
    scanf("%s", emp.name);
    
    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);
    
    printf("Enter Joining Date (day month year): ");
    scanf("%d %d %d", &emp.joiningDate.day, &emp.joiningDate.month, &emp.joiningDate.year);
    
    printf("\nName: %s | ID: %d | Joining Date: %02d/%02d/%d\n", 
           emp.name, 
           emp.id, 
           emp.joiningDate.day, 
           emp.joiningDate.month, 
           emp.joiningDate.year);
    
    return 0;
}