/*
Q1. Write a C program to create a structure containing book information like 
accession number, name of author, book title and flag to know whether book is 
issued or not.
Create a menu in which the following can be done.
1 - Display book information
2 - Add a new book
3 - Display all the books in the library of a particular author
4 - Display the number of books of a particular title
5 - Display the total number of books in the library
6 - Issue a book
(If we issue a book, then its number gets decreased by 1 and if we add a book, its 
number gets increased by 1)
*/
#include <stdio.h>
#include <string.h>
struct Book 
{
int accessionNumber;
char author[50];
char title[100];
int issued;
};
struct Library 
{
struct Book books[100];
int count;
};



void displayBookInfo(struct Book );
void displayAllBooks(struct Library );
void addNewBook(struct Library *);
void displayBooksByAuthor(struct Library );
void displayBookCountByTitle(struct Library );
void displayTotalBookCount(struct Library );
void issueBook(struct Library *);


int main() 
{
struct Library library;
library.count = 0;
int choice;
do {
printf("----- Library Management  -----\n");
printf("1. Display book information\n");
printf("2. Add a new book\n");
printf("3. Display all the books in the library of a particular author\n");
printf("4. Display the number of books of a particular title\n");
printf("5. Display the total number of books in the library\n");
printf("6. Issue a book\n");
printf("0. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) 
{
case 1:
displayAllBooks(library);
break;
case 2:
addNewBook(&library);
break;
case 3:
displayBooksByAuthor(library);
break;
case 4:
displayBookCountByTitle(library);
break;
case 5:
displayTotalBookCount(library);
break;
case 6:
issueBook(&library);
break;
case 0:
printf("Exiting the program. Goodbye!\n");
break;
default:
printf("Invalid choice. Please try again.\n\n");
}
} while (choice != 0);
return 0;
}
void displayBookInfo(struct Book book) 
{
printf("Accession Number: %d\n", book.accessionNumber);
printf("Author: %s\n", book.author);
printf("Title: %s\n", book.title);
printf("Issued: %s\n", book.issued ? "Yes" : "No");
printf("\n\n\n");
}
void displayAllBooks(struct Library library) 
{
if (library.count!=0)
{
int i;
for (i = 0; i < library.count; i++) 
{
displayBookInfo(library.books[i]);
}
}
else 
{
printf("Sorry! there is no book in library right now.Try adding new books.\n\n\n");
}
}

void addNewBook(struct Library *library) 
{
struct Book newBook;
printf("Enter Accession Number: ");
scanf("%d", &newBook.accessionNumber);
printf("Enter Author Name: ");
getchar(); 
fgets(newBook.author, sizeof(newBook.author), stdin);
newBook.author[strcspn(newBook.author, "\n")] = '\0'; 
printf("Enter Book Title: ");
fgets(newBook.title, sizeof(newBook.title), stdin);
newBook.title[strcspn(newBook.title, "\n")] = '\0'; 
newBook.issued = 0;
library->books[library->count] = newBook;
library->count++;
printf("Book added successfully!\n\n\n");
}

void displayBooksByAuthor(struct Library library) 
{
char authorName[50];
int i;
printf("Enter Author Name: ");
getchar(); // 
fgets(authorName, sizeof(authorName), stdin);
authorName[strcspn(authorName, "\n")] = '\0'; 
printf("\nBooks by Author '%s':\n", authorName);
for (i = 0; i < library.count; i++) 
{
if (strcmp(library.books[i].author, authorName) == 0) 
{
displayBookInfo(library.books[i]);
}
}
}

void displayBookCountByTitle(struct Library library) 
{
char bookTitle[100];
int i, count = 0;
printf("Enter Book Title: ");
getchar(); 
fgets(bookTitle, sizeof(bookTitle), stdin);
bookTitle[strcspn(bookTitle, "\n")] = '\0'; 
for (i = 0; i < library.count; i++) 
{
if (strcmp(library.books[i].title, bookTitle) == 0) 
{
count++;
}
}
printf("\nNumber of Books with Title '%s': %d\n\n\n", bookTitle, count);
}

void displayTotalBookCount(struct Library library) 
{
printf("Total Number of Books in the Library: %d\n\n\n", library.count);
}

void issueBook(struct Library *library)
{
int accessionNumber, i;
printf("Enter Accession Number of the Book to Issue: ");
scanf("%d", &accessionNumber);
for (i = 0; i < library->count; i++) 
{
if (library->books[i].accessionNumber == accessionNumber) 
{
if (library->books[i].issued == 0) 
{
library->books[i].issued = 1;
printf("Book with Accession Number %d has been issued.\n\n\n", accessionNumber);
} else 
{
printf("Book with Accession Number %d is already issued.\n\n\n", accessionNumber);
}
return;
}
}
printf("Book with Accession Number %d not found.\n\n\n", accessionNumber);
}
