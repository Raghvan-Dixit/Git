/*Q4. Write a C program to read a text file named as “Data.txt”, Create an another file 
named as “Del.txt” deleting the words “a”, “the”, “an” from the file “Data.txt” and 
replacing each one of them with a blank space in “Del.txt”.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
FILE *inputFile, *outputFile;
char word[100];
inputFile = fopen("Data.txt", "r");
if (inputFile == NULL) 
{
printf("Failed to open the input file.\n");
return 1;
}
outputFile = fopen("Del.txt", "w");
if (outputFile == NULL) 
{
printf("Failed to create the output file.\n");
fclose(inputFile);
return 1;
}
while (fscanf(inputFile, "%s", word) != EOF) 
{
if (strcmp(word, "a") == 0 || strcmp(word, "the") == 0 || strcmp(word, "an") == 0) 
{
fprintf(outputFile, " ");
}
else 
{
fprintf(outputFile, "%s ", word);
}
}
fclose(inputFile);
fclose(outputFile);
printf("The operation completed successfully.\n");
return 0;
}
