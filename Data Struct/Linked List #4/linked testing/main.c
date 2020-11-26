#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *insert(struct node *);
struct node *delete_dup(struct node *);
void display(struct node *);

int main()
{
    start = insert(start);
    delete_dup(start);
    display(start);
    return 0;
}

struct node *insert(struct node *start)
{
    struct node *new_node;
    int num;

    printf("Enter Data or 0 to exit: ");
    scanf("%d",&num);

    while (num != 0)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node -> data = num;
        if (start == NULL)
        {
            printf("First Data is NULL");
            new_node -> next = NULL;
            start = new_node;
        }
        else
        {
            new_node -> next = start;
            start = new_node;
        }
        printf("\nEnter Data or 0 to exit: ");
        scanf("%d",&num);
    }
    return start;
};
struct node *delete_dup(struct node *start)
{
    struct node *ptr1, *ptr2, *dup;
    ptr1 = start;

    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;

        /* Compare the picked element with rest
           of the elements */
        while (ptr2->next != NULL)
        {
            /* If duplicate then delete it */
            if (ptr1->data == ptr2->next->data)
            {
                /* sequence of steps is important here */
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            }
            else /* This is tricky */
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return start;
};

void display(struct node *start)
{
    struct node *ptr;

    ptr = start;

    while(ptr != NULL)
    {
        printf("%d\t",ptr->data);
        ptr = ptr -> next;
    }
    printf("\n");
}
