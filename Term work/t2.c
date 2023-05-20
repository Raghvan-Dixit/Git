/*
Q2. Create a structure to specify data on students given below: Roll number, Name, 
Department, Course, Year of joining Assume that there are not more than 450 
students in the college.
(a) Write a function to print names of all students who joined in a particular year.
(b) Write a function to print the data of a student whose roll number is given
*/
#include <stdio.h>
#include <string.h>
struct Student 
{
int rollNumber;
char name[50];
char department[50];
char course[50];
int yearOfJoining;
};
void printStudentsByYear(struct Student [], int , int );
void printStudentDataByRollNumber(struct Student [], int , int );
int main() 
{
struct Student students[450];
int count = 0;
int choice;
do {
printf("----- Student Management System -----\n");
printf("1. Add a new student\n");
printf("2. Print names of students joined in a particular year\n");
printf("3. Print student data by roll number\n");
printf("0. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) 
{
case 1: 
{
struct Student newStudent;
printf("Enter Roll Number: ");
scanf("%d", &newStudent.rollNumber);
printf("Enter Name: ");
getchar();
fgets(newStudent.name, sizeof(newStudent.name), stdin);
newStudent.name[strcspn(newStudent.name, "\n")] = '\0';
printf("Enter Department: ");
fgets(newStudent.department, sizeof(newStudent.department), stdin);
newStudent.department[strcspn(newStudent.department, "\n")] = '\0';
printf("Enter Course: ");
fgets(newStudent.course, sizeof(newStudent.course), stdin);
newStudent.course[strcspn(newStudent.course, "\n")] = '\0';
printf("Enter Year of Joining: ");
scanf("%d", &newStudent.yearOfJoining);
students[count] = newStudent;
count++;
printf("Student added successfully!\n\n\n");
break;
}
case 2: 
{
int year;
printf("Enter Year: ");
scanf("%d", &year);
printStudentsByYear(students, count, year);
break;
}
case 3: 
{
int rollNumber;
printf("Enter Roll Number: ");
scanf("%d", &rollNumber);
printStudentDataByRollNumber(students, count, rollNumber);
break;
}
case 0:
printf("Exiting the program. Goodbye!\n\n\n");
break;
default:
printf("Invalid choice. Please try again.\n\n\n2");
}
} while (choice != 0);
return 0;
}

void printStudentsByYear(struct Student students[], int count, int year) 
{
if(count!=0)
{
int i;
printf("Students who joined in year %d:", year);
for (i = 0; i < count; i++) 
{
if (students[i].yearOfJoining == year)
{
printf("Name: %s\n", students[i].name);
}
}
printf("\n\n");
}
else
{
printf("There are no students in records.Try adding new students.\n\n\n");
}
}

void printStudentDataByRollNumber(struct Student students[], int count, int rollNumber) 
{
if (count!=0)
{
int i;
for (i = 0; i < count; i++) 
{
if (students[i].rollNumber == rollNumber) 
{
printf("Student Data for Roll Number %d:\n", rollNumber);
printf("Name: %s\n", students[i].name);
printf("Department: %s\n", students[i].department);
printf("Course: %s\n", students[i].course);
printf("Year of Joining: %d\n\n\n", students[i].yearOfJoining);
return;
}
}
printf("Student with Roll Number %d not found.\n\n\n", rollNumber);
}
else
{
printf("There are no students in records.Try adding new students.\n\n\n");
}
}