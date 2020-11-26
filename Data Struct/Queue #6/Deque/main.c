#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *next;
	struct node *prev;
};

struct queue
{
    struct node *front;
    struct node *rear;
};

struct queue *q;
struct queue *create_queue(struct queue*);
struct queue *insert_rear(int,struct queue*);
struct queue *insert_front(int,struct queue*);
struct queue *delete_rear(struct queue*);
struct queue *delete_front(struct queue*);
struct queue *display(struct queue*);


int main()
{
    int choice,data;
while(1)
{

    system("cls");
    printf("\n\t\t\t\t****************** IMPLEMENTING DEQUE *************************\n\n");
    printf("\t\t\t\t\t\t1. Create_Queue\n");
    printf("\t\t\t\t\t\t2. Enqueue value at Front\n");
    printf("\t\t\t\t\t\t3. Enqueue value at Rear\n");
    printf("\t\t\t\t\t\t4. Dequeue the element at Rear\n");
    printf("\t\t\t\t\t\t5. Dequeue the element at Front\n");
    printf("\t\t\t\t\t\t6. Display Queue\n");
    printf("\t\t\t\t\t\t7. Exit\n");
    printf("\t\t\t\t\t\tChoice --------> ");
    scanf("%d", &choice);

    switch(choice)
    {
    case 1:
        q=create_queue(q);
        printf("\n\t\t\t\t\t\tFront and Rear Initialized!\n\n");
        printf("\t\t\t\t\t\tPress any key to continue....");
        getch();
        break;
    case 2:
        printf("\n\t\t\t\t\t\tPlease enter data to insert: ");
        scanf("%d", &data);
        q=insert_front(data,q);
        printf("\n\t\t\t\t\t\t%d has been inserted to the queue.\n",data);
        printf("\t\t\t\t\t\tPress any key to continue....");
        getch();
        break;
    case 3:
        printf("\n\t\t\t\t\t\tPlease enter data to insert: ");
        scanf("%d", &data);
        q=insert_rear(data,q);
        printf("\n\t\t\t\t\t\t%d has been inserted to the queue.\n",data);
        printf("\t\t\t\t\t\tPress any key to continue....");
        getch();
        break;
    case 4:
        q=delete_rear(q);
        printf("\n\t\t\t\t\t\tThe last element has been deleted from the queue.\n");
        printf("\t\t\t\t\t\tPress any key to continue....");
        getch();
        break;
    case 5:
        q=delete_front(q);
        printf("\n\t\t\t\t\t\tThe first element has been deleted from the queue.\n");
        printf("\t\t\t\t\t\tPress any key to continue....");
        getch();
        break;
    case 6:
        q=display(q);
        printf("\n\n\t\t\t\t\t\tPress any key to continue....");
        getch();
        break;
    default:
        exit(0);
        break;
    }

}

return 0;

}
struct queue *create_queue(struct queue* q)
{
    q=(struct queue*)malloc(sizeof(struct queue));
    q->front=q->rear=NULL;

    return q;
};
struct queue *insert_front(int data,struct queue* q)
{
    struct node *new_queue;

    new_queue=(struct node*)malloc(sizeof(struct queue));
    new_queue->data=data;

    if(q->front == NULL)//if front is empty we must make our enqueue to the front and make it rear
    {
        q->front = q->rear = new_queue;
        q->front->next = q->front->prev = NULL;
        q->rear->next = q->rear->prev = NULL;
    }
    else
    {
        q->front->prev = new_queue;
		new_queue->next = q->front;
        q->front = new_queue;
        q->front->prev = NULL;
    }

    return q;
};
struct queue *insert_rear(int data,struct queue* q)
{

    struct node* new_queue;


    new_queue=(struct node*)malloc(sizeof(struct node));
    new_queue->data=data;


    if(q->front == NULL)
    {
        q->front = q->rear = new_queue;
        q->front->next = q->front->prev = NULL;
        q->rear->next = q->rear->prev = NULL;
    }
    else
    {
        q->rear->next = new_queue;
		new_queue->prev = q->rear;
        q->rear = new_queue;
        q->rear->next = NULL;

    }

    return q;
};
struct queue *delete_rear(struct queue* q)
{
    struct node *ptr;

    ptr=q->front;

    if(q->front==NULL)
    {
        printf("\n\t\t\t\t\t\tQueue is empty!");
    }
    else if(q->front->next == NULL)//if there is only front left in the list we must make front and rear null after the deletion
    {
        free(ptr);
        q->front=q->rear=NULL;
    }
    else
    {
        while(ptr->next!= q->rear)
        {
            ptr=ptr->next;
        }
        free(ptr->next);
        q->rear=ptr;
        q->rear->next=NULL;

    }

return q;

};
struct queue *delete_front(struct queue* q)
{
    struct node *ptr;

    ptr=q->front;

    if(q->front == NULL)
    {
        printf("\n\t\t\t\t\t\tQueue is Empty!\n");
    }
    else
    {
        q->front=q->front->next;
        free(ptr);

        if(q->front==NULL)
        {
            q->rear=NULL;
        }
    }



    return q;

};
struct queue *display(struct queue* q)
{

    printf("\t\t\t");
    struct node *ptr;

    ptr=q->front;

    if(q->front == NULL)
    {
        printf("\n\t\t\t\t\t\tQueue is empty!\n\n");

    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d\t", ptr->data);

            ptr=ptr->next;
        }

        printf("\n\n");
    }



    return q;

};
