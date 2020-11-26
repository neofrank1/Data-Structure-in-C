/*
Filename: UyActivity3.c
Description: Count the Digits ,Upper and Lower Case Letter and Special Char.
Programmer: Neo Frank D. Uy
Date: Sept 16, 2020
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[100];
    int digit;
    int upper;
    int lower;
    int spe_char;
    int i;

    printf("\tString Meter\n");
    printf("Enter A Sting: ");
    gets(string); // Getting the String //

    digit = 0;
    upper = 0;
    lower = 0;
    spe_char = 0;

    for(i=0;string[i] != '\0';i++)
    {
        if (string[i] >= '0' && string[i] <= '9') // Conditional Statement for Digits //
        {
            digit++; // Count the digits //
        }
        else if (string[i] >= 'a' && string[i] <= 'z') // For Lower Case Letters //
        {
            lower++; // Count the letters //
        }
        else if (string[i] >= 'A' && string[i] <= 'Z') // For Upper Case Letters //
        {
            upper++; // Count the letters //
        }
        else
        {
            spe_char++; // Count the Special Characters //
        }
    }

    printf("\nDigit Count : %d",digit); // Display The Count / Increment //
    printf("\nUpper Count : %d",upper); // Display The Count / Increment //
    printf("\nLower Case Count : %d",lower); // Display The Count / Increment //
    printf("\nSpecial Character Count : %d",spe_char); // Display The Count / Increment //
    puts(string);





    return 0;
}
// Copyright Neo Frank D. Uy 2020 //
