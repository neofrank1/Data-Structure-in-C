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
    struct queue *front;
    struct queue *rear;
};

struct queue *q;
struct queue *create_queue(struct queue *q);
struct queue *enqueue_rear(struct queue *q,int);
struct queue *enqueue_front(struct queue *q,int);
struct queue *dequeue_rear(struct queue *q);
struct queue *dequeue_rear(struct queue *q);


int main()
{
    printf("Hello world!\n");
    return 0;
}

struct queue *create_queue(struct queue *q)
{
    q = (struct queue *)malloc(sizeof(struct queue));
    q -> front = NULL;
    q -> rear = NULL;

    return q;
};

