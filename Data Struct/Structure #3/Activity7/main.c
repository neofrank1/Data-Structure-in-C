/*
Filename: UyActivity7.c
Description: Write a program to create a structure with the information given below.
Programmer: Neo Frank D. Uy
Date: Sept 26, 2020
*/
#include <stdio.h>
#include <stdlib.h>

struct room
{
  int roomNo;
  float family;
  float doubles;
};

struct booking
{
    char dateFrom[15];
    char dateTo[15];
    int hotel_no;
    int type;
};

struct guest
{
  int guestNo;
  char guestName[25];
  char guestAddress[25];
  struct booking book;
};

struct hotel
{
    int hotelNo;
    char hotelName[25];
    char city[25];
    struct room rooms;
};

struct hotel hot[10] = {{1,"Sogo Hotel","Tipolo Mandaue",30,1400.00,2500.00},
                        {2,"QueensLand","Subangdaku Mandaue",20,1500,2500.00},
                        {3,"Hotel Mania","Opao Mandaue",40,1600.00,1300.00},
                        {4,"Haden Hotel","Centro Mandaue",25,1300.00,1500.00},
                        {5,"Bombo Hotel","Looc Mandaue",25,1300.00,1500.00},
                        {6,"Hotel 626","Ibabao Mandaue",15,1399.00,1000.00},
                        {7,"Hotel Transylvania","Basak Mandaue",25,1500.00,1400.00},
                        {8,"Radison Blu","Tabok Mandaue",30,1500.00,1990.00},
                        {9,"Moon Inn Hotel","Banilad Mandaue",20,1450.00,1100.00},
                        {10,"Big Hotel","Bakilid Mandaue",45,2000.00,1500.00}
                        };

struct guest gue[10] = {{1,"Johnny Sins","Tipolo Mandaue","09/11/2020",'0',8,2},
                        {2,"Mia Khalifa","Looc Mandaue","11/1/2020","11/03/2020",7,2},
                        {3,"Lana Rhoades","Subangdaku Mandaue","09/11/2020","11/02/2020",6,2},
                        {4,"Lexi Lore","Banilad Mandaue","09/11/2020","11/02/2020",9,2},
                        {5,"Ellie Eilish","Bakilid Mandaue","08/11/2020","11/30/2020",5,1},
                        {6,"Peter North","Opao Mandaue","09/11/2020",'0',4,1},
                        {7,"Peter North","Ibabao Mandaue","09/08/2020","09/08/2020",3,1},
                        {8,"Maria Ozawa","Centro Mandaue","09/09/2020","12/25/2020",1,1},
                        {9,"Kacey Kox","Opao Mandaue","09/10/2020","11/01/2020",2,1},
                        {10,"Hazel Moore","Tipolo Mandaue","09/07/2020",'0',10,1}
                        };

void all_hotels();
void address_hotel();
void list_name();
void list_rooms();
void list_bookings();

int i;
int ch;

int main()
{

    printf("\tHotel Information\n");
    printf("\n1. All Hotels");
    printf("\n2. Address of All Hotels in Mandaue");
    printf("\n3. Name & Address of all Guest in Mandaue");
    printf("\n4. Rooms");
    printf("\n5. Bookings");
    printf("\nEnter Choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        system("cls");
        all_hotels();
        break;
    case 2:
        system("cls");
        address_hotel();
        break;
    case 3:
        system("cls");
        list_name();
        break;
    case 4:
        system("cls");
        list_rooms();
        break;
    case 5:
        system("cls");
        list_bookings();
        break;
    default:
        printf("\nInvalid Not in Choices");
    }

    return 0;
}

void all_hotels() // View all Hotels Details //
{
    for(i=0;i<10;i++)
    {
        printf("Hotel No: %d\n",hot[i].hotelNo);
        printf("Hotel Name: %s\n",hot[i].hotelName);
        printf("Hotel Address: %s\n",hot[i].city);
        printf("Rooms: %d\n",hot[i].rooms.roomNo);
        printf("Family Room Price: %.2f\n",hot[i].rooms.family);
        printf("Double Room Price: %.2f",hot[i].rooms.doubles);
        printf("\n\n");
    }
    getch();
    system("cls");
    main();
}

void address_hotel() // View the Address of Hotel //
{
    for(i=0;i<10;i++)
    {
        printf("Hotel No: %d\n",hot[i].hotelNo);
        printf("Hotel Name: %s\n",hot[i].hotelName);
        printf("Hotel Address: %s\n",hot[i].city);
        printf("Rooms: %d",hot[i].rooms.roomNo);
        printf("\n\n");
    }
    getch();
    system("cls");
    main();
}

void list_name()
{
 for(i=0;i<10;i++)
    {
        printf("Hotel No: %d\n",hot[i].hotelNo);
        printf("Guest Name: %s\n",gue[i].guestName);
        printf("Guest Address: %s\n",gue[i].guestAddress);
        printf("Check In: %s\n",gue[i].book.dateFrom);
        printf("Check Out: %s\n",gue[i].book.dateTo);
        printf("Hotel No: %d\n",gue[i].book.hotel_no);
        if (gue[i].book.type == 1)
        {
            printf("Family Room\n");
        }
        else
        {
            printf("Double Room");
        }
        printf("\n\n");
    }
    getch();
    system("cls");
    main();
}

void list_rooms() // View of all list of Rooms //
{
    printf("1. Family Rooms\n");
    printf("2. Double Rooms\n");
    printf("Enter Choice: ");
    scanf("%d",&ch);

    if (ch == 1)
    {
        for(i=0;i<10;i++)
        {
        printf("Hotel No: %d\n",hot[i].hotelNo);
        printf("Hotel Name: %s\n",hot[i].hotelName);
        printf("Hotel Address: %s\n",hot[i].city);
        printf("Rooms: %d\n",hot[i].rooms.roomNo);
        printf("Family Room Price: %.2f",hot[i].rooms.family);
        printf("\n\n");
        }
    }
    else
    {
        printf("Hotel No: %d\n",hot[i].hotelNo);
        printf("Hotel Name: %s\n",hot[i].hotelName);
        printf("Hotel Address: %s\n",hot[i].city);
        printf("Rooms: %d\n",hot[i].rooms.roomNo);
        printf("Double Room Price: %.2f",hot[i].rooms.doubles);
        printf("\n\n");
    }
}

void list_bookings() // List of Bookings //
{
    for (i=0;i<10;i++)
    {
        if (gue[i].book.dateTo == '0')
        {
        printf("Hotel No: %d\n",hot[i].hotelNo);
        printf("Guest Name: %s\n",gue[i].guestName);
        printf("Guest Address: %s\n",gue[i].guestAddress);
        printf("Check In: %s\n",gue[i].book.dateFrom);
        printf("Check Out: %s\n",gue[i].book.dateTo);
        printf("Hotel No: %d\n",gue[i].book.hotel_no);
            if (gue[i].book.type == 1)
            {
            printf("Family Room\n");
            }
            else
            {
            printf("Double Room");
            }
        }
        printf("\n\n");
    }
}
// Copyright Neo Frank D. Uy 2020 //
