/*
Filename: UyActivity1.c
Description: Salesperson Total Sales
Programmer: Neo Frank D. Uy
Date: Sept 9, 2020
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{

    double product_sold[4][5] = {{200,500,150,686,100},{800,568,230,250,100},{560,660,210,100,150},{200,500,210,230,200}};
    double product_total = 0;
    double product_all_total = 0;

    int i,j;

    system("cls");
    printf("SalePerson\tProduct 1\tProduct 2\tProduct 3\tProduct 4\tProduct 5\tTotal\t\n");
    for(i=0;i<4;i++)
    {
        product_total = 0;
        printf("SalePerson %d:\t",i+1);
        for(j=0;j<5;j++)
        {
            printf("$%.2lf\t\t",product_sold[i][j]); // Display The Gathered Information //
            product_total += product_sold[i][j]; // Getting Total of each Column //
        }
        product_all_total += product_total;  // Getting All Total //
        printf("$%.2lf\t",product_total);   // Display Total of each Column //
        printf("\n");
    }
    printf("Total: ");
    for(i=0;i<5;i++)
    {
        product_total = 0;
        for(j=0;j<4;j++)
        {
            product_total += product_sold[j][i]; // Getting Total of each Row //
        }
        printf(" \t");
        printf("$%.2lf",product_total);  // Display Total of each Row //
    }
        printf(" \t$%.2lf",product_all_total); // Display Total of All Total //

    return 0;
}
// Copyright Neo Frank D. Uy 2020 //
