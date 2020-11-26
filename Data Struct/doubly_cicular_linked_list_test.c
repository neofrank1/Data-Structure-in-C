// doubly cicular linked list test
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *ins_beg(struct node*, int);
struct node *display1(struct node*);
struct node *sum_row(struct node*);
struct node *sum_all(struct node*);
struct node *sum_even(struct node*);
struct node *sum_odd(struct node*);
struct node *modulo(struct node*);
struct node *add(struct node*);
struct node *display2(struct node*);
struct node *reverse(struct node*);
int main ()
{
    srand(time(NULL));
    int i;
    for(i=0;i<20;i++)
    {
        start = ins_beg(start,rand()%100+1);
    }
    start = display1(start);
    printf("\n***********************************\n");
    start = sum_row(start);
    printf("\n***********************************\n");
    start = sum_all(start);
     printf("\n***********************************\n");
    start = sum_even(start);
   printf("\n***********************************\n");
    start =sum_odd(start);
    printf("\n***********************************\n");
    start =modulo(start);
   printf("\n***********************************\n");
    start =add(start);
    printf("\n***********************************\n");
    start =display2(start);
     printf("\n***********************************\n");
    start =reverse(start);
     printf("\n***********************************\n");
    return 0;

}
struct node *ins_beg(struct node *start,int num)
{
    struct node *new_node,*ptr;

    new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = num;

    ptr=start;

    if(start == NULL )
    {
        new_node->next = new_node;
        new_node->prev = new_node;
        start=new_node;
    }
    else{
            while(ptr->next!=start){
               ptr=ptr->next;
            }
        new_node->prev=ptr;
        ptr->next=new_node;
        new_node->next=start;
        start->prev=new_node;

        start=new_node;
    }
    return start;
}
struct node *display1(struct node* start)
{
    struct node *ptr;
    int count;
    ptr=start;
    printf("\nList of data\n");

    for(count=1;ptr->next!=start;count++)
    {
        
        printf("%d\t",ptr->data);
         if(count==5){
            printf("\n");
            count = 0;
         }

        ptr=ptr->next;
    }
     printf("%d\n",ptr->data);
    return start;
}
struct node *sum_row(struct node* start)
{
    struct node *ptr;
    int sum=0,count=0;
    ptr=start;

    while(ptr->next!=start)
    {
        count++;
        sum+=ptr->data;
        printf("%d\t",ptr->data);
        if(count==5)
        {
            printf("%d\n",sum);
            if(ptr->next->next!=start)
            sum=0;
            count =0;
        }
         ptr=ptr->next;
    }
    printf("%d %d",ptr->data,ptr->data+sum);
    return start;
}
struct node *sum_all(struct node* start)
{
     struct node *ptr;
    int sum=0;
    ptr=start;

    while(ptr->next!=start)
    {
        sum=sum+ptr->data;
        ptr=ptr->next;
    }
    printf("\nsum all nodes: %d",sum+ptr->data);
    return start;

}
struct node *sum_even(struct node* start)
{
     struct node *ptr;
    int sum=0;
    ptr=start;

    while(ptr->next!=start)
    {
        if(ptr->data%2==0)
        {
            sum=+ptr->data;
        }
         ptr=ptr->next;
    }
    if(ptr->data%2==0)
        {
            sum=+ptr->data;
        }
    printf("\nsum of all even node: %d",sum);
    return start;

}
struct node *sum_odd(struct node* start)
{
     struct node *ptr;
    int sum=0;
    ptr=start;

    while(ptr->next!=start)
    {
        if(ptr->data%2==1)
        {
            sum=+ptr->data;
        }
         ptr=ptr->next;
    }
    if(ptr->data%2==1)
        {
            sum=+ptr->data;
        }
    printf("\nsum of all odd node: %d",sum);
    return start;

}
struct node *modulo(struct node* start)
{
     struct node *ptr;
    int sum=0;
    ptr=start;

    while(ptr->next!=start)
    {
        if(ptr->data%2==0||ptr->data%5==0)
        {
            sum=+ptr->data;
        }
         ptr=ptr->next;
    }
    printf("\nsum of all node divisible by 2 and 5: %d",sum);
    return start;

}
struct node *add(struct node* start)
{
     struct node *ptr;

    ptr=start;

    while(ptr->next!=start)
    {
        ptr->data=ptr->data+2;
         ptr=ptr->next;
    }
    ptr->data=ptr->data+2;
    return start;

}
struct node *display2(struct node* start)
{
    struct node *ptr;
    ptr=start;
    printf("\nList of data\n");

    while(ptr->next!=start)
    {

        printf("%d-",ptr->data);
        ptr=ptr->next;
    }
     printf("%d\n",ptr->data);
    return start;
}
struct node *reverse(struct node* start)
{
    struct node *ptr;
    ptr=start;
    printf("\nList of data\n");

    while(ptr->next!=start)
    {
        ptr=ptr->next;
    }

    while(ptr->prev!=start)
    {
        printf("%d-",ptr->data);
        ptr=ptr->prev;
    }
     printf("%d %d",ptr->data,ptr->prev->data);
    return start;
}



