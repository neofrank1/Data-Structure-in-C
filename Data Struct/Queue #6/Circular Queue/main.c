/*
Filename: Assignment Queue
Description: Circular Queue
Programmer: Neo Frank D. Uy
Date: November 18, 2020
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct queue
{
    struct node *front;
    struct node *rear;
};

struct queue *q;
struct queue *create_queue(struct queue *);
struct queue *enqueue(struct queue *,int);
struct queue *dequeue(struct queue *);
struct queue *display(struct queue *);
int peek (struct queue *);

int main()
{
    int choice,value;
    srand(time(NULL));
    q = create_queue(q);
    do
    {
        system("cls");
        printf("\tCircular Queue\n");
        printf("1: Initialize Circular Queue\n");
        printf("2: Enqueue Circular Queue\n");
        printf("3: Dequeue Circular Queue\n");
        printf("4: Display Circular Queue\n");
        printf("5: Peek Circular Queue\n");
        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            for (int i=0;i<10;i++)
            {
                 q = enqueue(q,rand()%100+1);
            }
            printf("\nSuccessfully Initialize the Circular Queue");
            getch();
            break;
        case 2:
            printf("Enter Value: ");
            scanf("%d",&value);
            q = enqueue(q,value);
            printf("\nSuccessfully Added in Circular Queue");
            getch();
            break;
        case 3:
            q = dequeue(q);
            printf("\tSuccessfully Deleted in Circular Queue");
            getch();
            break;
        case 4:
            q = display(q);
            getch();
            break;
        case 5:
            q = peek(q);
            value = q;
            printf("%d",value);
            getch();
            break;
            }
    }while(choice != 6);

    return 0;
}

struct queue *create_queue(struct queue *q)
{
    q = (struct queue *)malloc(sizeof(struct queue));
    q -> front = NULL;
    q -> rear = NULL;
    return q;
};

struct queue *enqueue(struct queue *q,int value)
{
    struct node *new_queue;
    new_queue = (struct node *)malloc(sizeof(struct node));
    new_queue -> data = value;
    new_queue -> next = NULL;
    if ((q -> front == NULL) && (q -> rear == NULL))
    {
      q -> front = q -> rear = new_queue; // Front and Rear Connected and added the value of new_queue //
      q -> rear -> next = q -> front; // Connect the Rear to Front //
    }
    else
    {
        q -> rear -> next = new_queue; // Rear Next becomes New_Queue //
        q -> rear = new_queue; // Rear  added Value of New_Queue //
        q -> rear -> next = q -> front; // Connect the Rear to the Front //
     }
    return q;
};

struct queue *dequeue(struct queue *q)
{
    struct node *ptr;
    ptr = q -> front;
    if ((q -> front == NULL) && (q -> rear == NULL))
    {
        printf("\nEmpty Ang Queue OI!");
    }
    else if (q -> front == q -> rear) // if the Front and Rear has a value or connected //
    {
        q -> front = q -> rear = NULL;
        free(ptr); // Delete //
    }
    else
    {
        q -> front = q -> front -> next; // Next Value becomes the Front //
        q -> rear -> next = q -> front; // Next value of Rear becomes Front or Connect Rear and Front //
        free(ptr); // Delete //
    }
    return q;
};

struct queue *display(struct queue *q) // Display Operator //
{
    struct node *ptr;

    ptr = q -> front;
    if ((q -> front == NULL) && (q -> rear == NULL))
    {
        printf("Empty Ang Queue OI!\n");
    }
    else
        {
            do
            {
                printf("%d\t",ptr->data);
                ptr = ptr -> next;
            }while (ptr != q -> front);
        }
    return q;
};

int peek(struct queue *q) // Peek Operator //
{
    if ((q -> front == NULL) && (q -> rear == NULL))
    {
        return 0;
    }
    else
    {
        return q -> front -> data;
    }
}
