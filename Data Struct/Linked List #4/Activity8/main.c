/*
Filename: UyActivity8
Description: Menu Driven Linked List
Programmer: Neo Frank D. Uy
Date: October 7, 2020
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct node
{
    int id;
    int salary;
    char name[256];
    char address[256];
    struct node *next;
};

// ----------- Functions ---------------- //
struct node *start = NULL;
struct node *insert_employee(struct node *);
struct node *display(struct node *);
struct node *count_employee(struct node *);
struct node *avg_salary(struct node *);
struct node *search(struct node *);
struct node *del_employee(struct node*);

int main()
{
    int ch;

    printf("----MENU----\n");
    printf("1. Add Employee\n");
    printf("2. Search Employee(Based on Name)\n");
    printf("3. Display All Employees\n");
    printf("4. Get Total Numbers of Employees\n");
    printf("5. Get Total Average of Employees\n");
    printf("6. Delete an Employee(Based on Id)\n");
    printf("0. Exit\n");
    printf("Enter Choice: ");
    scanf("%d",&ch);
    do
    {
        switch(ch)
        {
        case 1:
            start = insert_employee(start); // Insert or Add //
            break;
        case 2:
           start = search(start); // Search //
            break;
        case 3:
           start = display(start); // Display //
            break;
        case 4:
            start = count_employee(start); // Number or Count //
            break;
        case 5:
            start = avg_salary(start); // Average //
            break;
        case 6:
            start = del_employee(start); // Delete //
            break;
        case 0:
            exit(0);
        default:
            printf("Not In Choices\n");
        }
        system("cls");
        main();
    }
    while (ch!=0);

    return 0;
}

struct node *insert_employee(struct node *start) // Insert or Add Employee // Insert in the Beginning of the Linked List //
{
    struct node *new_node;
    int id;
    int salary;
    char name[256];
    char address[256];

    system("cls");
    printf("Add Employees");
    new_node = (struct node *)malloc(sizeof(struct node)); // Memory Allocate //
    printf("\nEnter Id of Employee: ");
    scanf("%d",&id);
    new_node -> id = id; // ID Node //
    printf("\nName of Employee: ");
    fflush(stdin);gets(name);
    strcpy(new_node -> name, name); // Name Node //
    printf("\nAddress of Employee: ");
    gets(address);
    strcpy(new_node -> address, address); // Add Node //
    printf("\nEnter Salary of Employee: ");
    scanf("%d",&salary);
    new_node -> salary = salary; // Salary Node //

    new_node -> next = start;
    start = new_node;

    printf("\nEmployee Added!");
    getch();

    return start;
}

struct node *search(struct node *start) // Search Employee //
{
    struct node *ptr;
    int i,flag;
    flag = 0;
    i = 0;
    char name[256];
    char name_2[256];

    ptr = start;
    system("cls");
    printf("Enter Name of Employee: ");
    fflush(stdin);
    gets(name);

    while(ptr!=NULL)
    {
        while(i<strlen(name))
        {
            name_2[i] = ptr -> name[i];
            i++;
        }
        if (strcmp(name,name_2) == 0)
        {
            flag = 1;
            break;
        }
        ptr = ptr -> next;
    }

    if (flag == 1)
    {
        printf("\t----Employee Information----\n");
        printf("Name: %s\n",ptr->name);
        printf("ID: %d\n",ptr->id);
        printf("Address: %s\n",ptr->address);
        printf("Salary: %d\n",ptr->salary);
    }
    else
    {
        printf("Record Not Found\n");
    }

    printf("\nPress Anything to Exit!");
    getch();

    return start;
}

struct node *display(struct node *start) // Display Employee //
{
    struct node *ptr;

    ptr = start;
    printf("----Employee List----\n");
    printf("ID\tName\tAddress\tSalary\n");

    while (ptr!=NULL)
    {
        printf("%d\t%s\t%s\t%d\n",ptr->id,ptr->name,ptr->address,ptr->salary);
        ptr = ptr -> next;
    }

    printf("Press Any key to Exit");
    getch();


    return start;
}

struct node *count_employee(struct node *start) // Count Employee //
{
    struct node *ptr;
    int i;

    ptr = start;

    for (i=0;ptr!=NULL;i++)
    {
        ptr = ptr -> next;
    }

    printf("Number Of Employees: %d",i);
    getch();

    return start;
};

struct node *avg_salary(struct node *start) // Getting the Average Salary //
{
    struct node *ptr;
    int i;
    int total;
    int average;

    ptr = start;
    average = 0;
    total = 0;

    for (i=0;ptr!=NULL;i++)
    {
        total += ptr -> salary;
        ptr = ptr -> next;
    }

    average = total / i;

    printf("Average Salary: %.2f",(float)average); // Display the Salary //
    getch();


    return start;
}

struct node *del_employee(struct node *start) // Delete Employee //
{
    struct node *ptr, *preptr;
    int id;
    int flag;

    ptr = start;
    flag = 0;

    printf("Enter ID of Employee: ");
    scanf("%d",&id);

    if (ptr == NULL)
    {
        flag = 2;
        printf("Record is Not Founded :( ");
    }
    else if(id == ptr -> id)
    {
        flag = 1;
        start = start -> next;
        free(ptr);
    }
    else // Getting the Last Node //
    {
        while (ptr!=NULL)
        {
            if(id == ptr -> id)
            {
                flag = 1;
                break;
            }
            preptr = ptr;
            ptr = ptr -> next;
        }
    }
    if(flag == 1)
    {
            preptr -> next = ptr -> next;
            free(ptr);
            printf("\nEmployee Successfully Deleted!");
    }
    else if (flag == 0)
    {
        printf("\nID/Employee Not Found:(");
    }

    getch();

    return start;
}

// Copyright Neo Frank D. Uy 2020 //
