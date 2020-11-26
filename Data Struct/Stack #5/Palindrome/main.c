#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    char data;
    struct node *next;
};

struct node *top = NULL;
struct node *push(struct node *,char);
struct node *pop(struct node *);
char peek(struct node *);

struct node *push(struct node *top,char par) // Push Stack //
{
    struct node *new_node;

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = par;

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

struct node *pop(struct node *top) // Pop Stack //
{
    struct node *ptr;

    if (top == NULL)
    {
        printf("Walay Sulod oi");
    }
    else
    {
        ptr = top;
        top = top -> next;
        free(ptr);
    }
    return top;
};

char peek(struct node *top) // Peek Stack //
{
    if (top == NULL)
    {
        return 0;
    }
    else
    {
        return top -> data;
    }
};

int main()
{
    int i;
    char par[256];

    printf("Enter Expression: ");
    gets(par);

    for(i=0; i<strlen(par);i++)
    {
           if(top==NULL)
           {
               top = push(top,par[i]);
           }
           else if(par[i] == peek(top))
        {
                top = pop(top);
        }

    }
    if (top == NULL)
    {
        printf("\nValid Statement"); // True //
    }
    else
    {
        printf("\nInvalid Statement"); // False //
    }
    return 0;
}
