#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//Step 1: Declare a linked list node1
struct node1
{
	int data;	
	struct node1 *next;
}*start1 = NULL;
//Step 2: Declare a linked list node2
struct node2
{
	int data;	
	struct node2 *next;
};
//Step 3: Declare a linked list node3
struct node3
{
	int data;	
	struct node3 *next;
};
//Step 4: Declare a linked list node4
struct node4
{
	int data;	
	struct node4 *next;
};

//functions
struct node

struct node *ins_end(struct node *, int);
struct node *del_beg(struct node *);
struct node *display(struct node *);

int main()
{
	srand(time(NULL));
	int i;
	
	//Step 5: Insert 30 nodes to node1
	printf("30 Nodes Inserted in Node1\n");
	for(i = 0; i < 30; i++)
	{
		start1 = ins_beg(start1, 1 + rand() % 100);
	}
	//Step 6
	printf("Nodes in Node1 That is Divisible by 2 is Inserted to Node2\n");
	start2 = assign(start2);
	//Step 7
	printf("Nodes in Node1 That is Divisible by 5 is Inserted to Node3\n");
	start3 = assign(start3);
	//Step 8
	printf("Nodes in Node1 That isn't Divisible by 2 and 5 is Inserted to Node2\n");
	start4 = assign(start4);
	//Step 9
	printf("Display Node1 by 6x5 Matrix\n");
	start1 = matrix(start1);
	//Step 10
	printf("Integer 10 is Inserted to Node1 at the Beginning of the List\n");
	start1 = ins_beg(start1, 10);
	//Step 11
	printf("Integer 11 is Inserted to Node1 at the Beginning of the List\n");
	start1 = ins_end(start1, 11);
	//Step 12
	printf("First Node of Node2 Deleted\n");
	start2 = del_beg(start2);
	//Step 13
	printf("Length of the following: \n");
	length(start1, start2, start3, start4);
	//Step 14
	printf("All Nodes of Node1 Deleted\n");
	start1 = del_nodes(start1);
	
	return 0;
}
struct node1 *ins_beg(struct node1 *start1, int num)
{
	struct node *new_node;
	
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	new_node -> next = start1;
	start1 = new_node;
	
	return start1;
}
struct node2 *assign(struct node2 *start2) //Step 6
{
	struct node *ptr, *new_node;
	
	new_node = (struct node *)malloc(sizeof(struct node));
	
	ptr = start1;
	
	while(ptr != NULL)
	{
		if(ptr -> data % 2 == 0)
		{
			new_node -> data = ptr -> data;
			new_node -> next = start2;
			start2 = new_node;
		}
		
		ptr = ptr -> next;
	}
	
	return start2;
}
struct node3 *assign(struct node3 *start3) //Step 7
{
	struct node *ptr, *new_node;
	
	new_node = (struct node *)malloc(sizeof(struct node));
	
	ptr = start1;
	
	while(ptr != NULL)
	{
		if(ptr -> data % 5 == 0)
		{
			new_node -> data = ptr -> data;
			new_node -> next = start3;
			start3 = new_node;
		}
		
		ptr = ptr -> next;
	}
	
	return start3;
}
struct node4 *assign(struct node4 *start4) //Step 8
{
	struct node *ptr, *new_node;
	
	new_node = (struct node *)malloc(sizeof(struct node));
	
	ptr = start1;
	
	while(ptr != NULL)
	{
		if(ptr -> data % 2 != 0 && ptr -> data % 5 != 5)
		{
			new_node -> data = ptr -> data;
			new_node -> next = start4;
			start4 = new_node;
		}
		
		ptr = ptr -> next;
	}
	
	return start4;
}
struct node1 *matrix(struct node1 *start1) //Step 9
{
	struct node1 *ptr;
	int count = 0;
	
	ptr = start1;
	
	printf("Node1: \n");
	
	while(ptr != NULL)
	{
		printf("%d\t", ptr -> data);
		
		if(count == 6)
		{
			printf("\n");
			count = 0;
		}
		
		count += 1;
		ptr = ptr -> next;
	}
	
	return start 1;
}
struct node1 *ins_beg(struct node *start1, int num) //Step 10
{
	struct node *new_node;
	
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	new_node -> next = start1;
	start1 = new_node;
	
	return start1;
}
struct node1 *ins_end(struct node *start1, int num) //Step 11
{
	struct node *new_node, *ptr;
	
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	new_node -> next = start1;
	
	while(ptr -> next != start1)
	{
		ptr = ptr -> next;
	}
	
	ptr -> next = new_node;
	
	return start1;
}
struct 
