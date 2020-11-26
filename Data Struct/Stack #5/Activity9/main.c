#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;
struct node *push(struct node *,int);
struct node *pop(struct node *);
int peek(struct node *);
struct node *reverse(struct node *);
struct node *display(struct node *);

int main()
{
    srand(time(NULL));
    for(int i=0;i<10;i++)
    {
        top = push(top,rand()%100+1);
    }
    printf("Stack In Original Order\n");
    top = display(top);
    printf("\n");
    printf("Stack in Reverse Order\n");
    top = reverse(top);
    display(top);
    return 0;
}

struct node *push(struct node *top,int value)
{
    struct node *new_node;

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = value;

    if (top == NULL)
    {
        new_node -> next = NULL;
    }
    else
    {
        new_node -> next = top;
    }
    top = new_node;
    return top;
};

struct node *pop (struct node *top)
{
    struct node *ptr;

    if (top == NULL)
    {
        printf("Walay Sulod Oi!");
    }
    else
    {
        ptr = top;
        top = top -> next;
        free(ptr);
    }
    return top;
};

int peek(struct node *top)
{
    if (top == NULL)
    {
        return 0;
    }
    else
        return top -> data;
};

struct node *reverse(struct node *top)
{
    struct node *ptr;
    ptr = NULL;
    if (top == NULL)
    {
        printf("Walay Sulod Oi!");
    }
    else
    {
        while (top != NULL)
        {
            if(ptr == NULL)
            {
                ptr = push(ptr,peek(top));
                ptr -> next = NULL;
                top = pop(top);
            }
            else
            {
                ptr = push(ptr,peek(top));
                top = pop(top);
            }
        }
        top = ptr;
    }
    return top;
};

struct node *display(struct node *top)
{
    struct node *ptr;

    ptr = top;

    if (ptr != NULL)
    {
        do
        {
            printf("%d\t", ptr -> data);
            ptr = ptr -> next;
        }while (ptr != NULL);
    }
    else
    {
        printf("Walay Sulod Oi!");
    }
    return top;
};
