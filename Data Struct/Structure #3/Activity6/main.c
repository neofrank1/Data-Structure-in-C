/*
Filename: UyActivity6.c
Description: Write a program to create a structure with the information given below. Then, read and print the data.
Programmer: Neo Frank D. Uy
Date: Sept 25, 2020
*/
#include <stdio.h>
#include <stdlib.h>

struct name // Structure for name //
{
    char first_name[15];
    char middle_name[15];
    char last_name[15];
};

struct address // Structure for Address //
{
    char area[15];
    char city[15];
    char state[15];
};

struct employee // For Employees information //Nested Struct //
{
    int emp_id;
    struct name emp_name;
    struct address add;
    int age;
    int salary;
    char designation[15];
};

// Initialized Information for Employee // 10 Employees only //

struct employee emp[10] = {{1, "Neo Frank", "Defensor","Uy", "Tipolo", "Mandaue", "Cebu", 19, 10000, "Factory"},{2,"Abdul","Jawkul","Salsalani","Subangdaku","Mandaue","Cebu",20,20000,"Driver"},{3,"James","Bu-aya","Lebron","Maguikay","Mandaue","Cebu",21,30000,"Foreman"},
                          {4,"Ray","Banal","Malibog","Mabolo","Cebu","Cebu",22,40000,"Janitor"},{5,"Boom","Sabog","Bautista","Pardo","Cebu","Cebu",19,10000,"Factory"},{6,"Gina","Granger","Gemima","Looc","Mandaue","Cebu",23,30000,"Manager"},{7,"Brenda","Bober","Banga","Opao","Mandaue","Cebu",30,40000,"Factory"},
                          {8,"Frank","Yusuf","Dazai","Tipolo","Mandaue","Cebu",18,50000,"CEO"},{9,"Ching","Chong","Dato","Colon","Cebu","Cebu",30,60000,"Chef"},{10,"Leila","Ambot","Delima","Bagay","Bantayan","Cebu",21,30000,"Secretary"}};

int main()
{
    int i;
    for (i=0;i<10;i++) // Display all the Records of employees//
    {
        printf("Employee Id: %d\n",emp[i].emp_id);
        printf("Name: %s, %s, %s\n",emp[i].emp_name.first_name,emp[i].emp_name.middle_name,emp[i].emp_name.last_name);
        printf("Address: %s,%s,%s\n",emp[i].add.area,emp[i].add.city,emp[i].add.state);
        printf("Age: %d\n",emp[i].age);
        printf("Salary: %d\n",emp[i].salary);
        printf("Designation: %s\n\n",emp[i].designation);
    }
/* //if in Case want to find or display only one employee // i is minus 1 because the index start with 0//
    printf("Employee ID: ");
    scanf("%d",&i);

        printf("Employee Id: %d\n",emp[i-1].emp_id);
        printf("Name: %s, %s, %s\n",emp[i-1].emp_name.first_name,emp[i].emp_name.middle_name,emp[i].emp_name.last_name);
        printf("Address: %s,%s,%s\n",emp[i-1].add.area,emp[i].add.city,emp[i].add.state);
        printf("Age: %d\n",emp[i-1].age);
        printf("Salary: %d\n",emp[i-1].salary);
        printf("Designation: %s\n\n",emp[i-1].designation);


*/
    return 0;
}
// Copyright Neo Frank D. Uy 2020 //
