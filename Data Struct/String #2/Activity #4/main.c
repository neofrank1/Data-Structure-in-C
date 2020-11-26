/*
Filename: UyActivity4.c
Description: Write a Program to read a line until a newline is entered.
Programmer: Uy, Neo Frank D.
Date: Sept 19, 2020
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char string[20];
    int i;
    i = 0;
    printf("Enter A String: ");
    while(i<50)
    {
        scanf("%c",&string[i]); // getting the string //
        if(string[i] == 110 && string[i-1] == 92) // Getting the Backslash and letter n //
        {
        string[i-1] = '\0'; // to make the String last into null //
        break;
        }
        else
        {
        i++;
        }
    }
    for(i=0;string[i] != '\0';i++)
    {
        printf("%c",string[i]); // Display //
    }


    return 0;
}
// Copyright Neo Frank D. Uy 2020 //
