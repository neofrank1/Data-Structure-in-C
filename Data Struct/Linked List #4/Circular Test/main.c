#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node // Step 1 //
{
    int data;
    struct node *next;

}node2,node3,node4; // Step 2 and 3 and 4 //

struct node *start = NULL;
struct node *insert_beg(struct node *, int number);
struct node *del_all(struct node *);
struct node *display_nodes(struct node *);
struct node *sep_nodes(struct node *);
struct node *del_beg(struct node *);

int node_1;
int node_2;
int node_3;
int node_4;

int main()
{
    srand(time(NULL));
    int number;
	int i;
    for (i=0;i<30;i++) // Step 5 // Insert Node 30 //
    {
        number = (rand() % 30 + 1);
        insert_beg(start,number);
    }

    display_nodes(start);

    return 0;
}
struct node *insert_beg(struct node *start, int number) // Insert Node 1 //
{
    struct node *ptr ,*new_node;

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = number;

    if (start == NULL)
    {
        new_node -> next = new_node;
        start = new_node;
    }
    else
    {
        ptr = start;
        while (ptr -> next != start)
        {
            ptr = ptr -> next;
        }
        ptr -> next = new_node;
        new_node -> next = start;
        start = new_node;
    }
    return start;
}

struct node *sep_nodes(struct node *start)
{
    struct node *ptr;

    if (ptr == NULL)
    {
        printf("Empty");
    }
    else
    {
        while (ptr -> next != start)
        {
            if (ptr -> data % 2) // Step 6 //
        {
            ptr -> data = node2.data;
            ptr = ptr -> next;
            node_2++;

        }
        else if (ptr -> data % 5) // Step 7 //
        {
            ptr -> data = node3.data;
            ptr = ptr -> next;
            node_3++;
        }
        else // Step 8 //
        {
            ptr -> data = node4.data;
            ptr = ptr -> next;
            node_4++;
        }
        node_1++;
        }
    }

};
struct node *display_nodes(struct node *start)
{
    struct node *ptr;


    if (start == NULL)
    {
        printf("Empty");
    }
    else
    {
    while(ptr -> next != start)
    {
        printf("Node 1: %d\t",ptr -> data);
        printf("Node 2: %d\t",ptr -> node2.data);
        printf("Node 3: %d\t",ptr -> node3.data);
        printf("Node 4: %d\t",ptr -> node4.data);
        ptr = ptr -> next;
    }
    }
    printf("\n");
}

struct node *del_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;
     while(ptr ->next != start)
    {
        ptr = ptr -> next;
        ptr -> next = start -> next;
        free(start);
    }
    start = ptr -> next ;
};


struct node *del_all(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while(ptr -> next != start)
    {
        start = del_beg(start);
        free(start);
    }
    return start;
}
