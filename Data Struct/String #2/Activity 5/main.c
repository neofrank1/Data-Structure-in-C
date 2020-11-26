/*
Filename: UyActivity5.c
Description: Count and Display number of times the word "the"
Programmer: Uy, Neo Frank D.
Date:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[20];
    int i;
    int count;

    count = 0; // Store the count word "THE" //

    printf("Enter The String: "); // Input //
    gets(string);

    for(i=0;string[i] != '\0';i++) // to access the value of string //
    {
        if ((string[i] == 'T' && string[i+1] == 'H' && string[i+2] == 'E') || (string[i] == 't' && string[i+1] == 'h' && string[i+2] == 'e')) //Conditional Statement for getting the word "THE" //
        {
            count++; // Increment if the condition is true //
        }
    }

    printf("\nNumber Times Use: %d",count); // Display the count //


    return 0;
}
// Copyright Neo Frank D. Uy 2020 //
