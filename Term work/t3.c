/*
Q3. Write a C program to create a student structure having fields emp_name, 
emp_ID and address. Accept the details of 'n' employees, rearrange the data in 
alphabetical order of employee name and display it. Print the rearrange records
*/
#include <stdio.h>
#include <string.h>
struct Employee 
{
char emp_name[50];
int emp_ID;
char address[100];
};

void swap(struct Employee *, struct Employee *) ;
void sortEmployees(struct Employee [], int ); 
void displayEmployees(struct Employee [], int ) ;


int main() 
{
int n, i;
printf("Enter the number of employees: ");
scanf("%d", &n);
struct Employee employees[n];
for (i = 0; i < n; i++) 
{
printf("\nEnter details for Employee %d:\n", i + 1);
printf("Employee Name: ");
getchar();
fgets(employees[i].emp_name, sizeof(employees[i].emp_name), stdin);
employees[i].emp_name[strcspn(employees[i].emp_name, "\n")] = '\0';
printf("Employee ID: ");
scanf("%d", &employees[i].emp_ID);
printf("Address: ");
getchar();
fgets(employees[i].address, sizeof(employees[i].address), stdin);
employees[i].address[strcspn(employees[i].address, "\n")] = '\0';
}
sortEmployees(employees, n);
displayEmployees(employees, n);
return 0;
}
void swap(struct Employee *a, struct Employee *b) 
{
struct Employee temp = *a;
*a = *b;
*b = temp;
}
void sortEmployees(struct Employee employees[], int n) 
{
int i, j;
for (i = 0; i < n - 1; i++) {
for (j = 0; j < n - i - 1; j++) {
if (strcmp(employees[j].emp_name, employees[j + 1].emp_name) > 0) 
{
swap(&employees[j], &employees[j + 1]);
}
}
}
}

void displayEmployees(struct Employee employees[], int n) 
{
int i;
printf("Rearranged Employee Records:\n");
for (i = 0; i < n; i++) 
{
printf("Employee Name: %s\n", employees[i].emp_name);
printf("Employee ID: %d\n", employees[i].emp_ID);
printf("Address: %s\n", employees[i].address);
printf("\n");
}
}