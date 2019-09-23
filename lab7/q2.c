/*Implement a queue of strings using an output restricted dequeue (no deleteRight).
Note: An output-restricted deque is one where insertion can be made at both ends,
but deletion can be made from one end only, where as An input-restricted deque is
one where deletion can be made from both ends, but insertion can be made at one
end only.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct 
{
	char str[MAX][10];
	int front;
	int rear;
}QUEUE;

void insertrear(QUEUE *ptr, char item[])
{
	if(ptr->rear == MAX - 1)
	{
		printf("queue is full\n");
	}
	else
	{
		(ptr->rear)++;
		strcpy(ptr->str[ptr->rear],item);
	}
}

void insertfront(QUEUE *ptr, char item[])
{
	if(ptr->front == 0)
	{
		printf("more cannot be added from this end\n");
	}
	else
	{
		(ptr->front)--;
		strcpy(ptr->str[ptr->front], item);
	}
}

char* deletefront(QUEUE *ptr, char arr[])
{
	if(ptr->front == -1)
	{
		printf("cannot be deleted, queue is empty \n");
	}
	else
	{
		strcpy(arr,ptr->str[(ptr->front)++]);
		return arr;

	}
}

void display(QUEUE *ptr)
{
	for(int i = ptr->front; i != ptr->rear + 1; i++)
	{
		printf(" %s ", ptr->str[i]);
	}
	printf("\n");
}

int main()
{
	QUEUE q, *ptr;
	ptr = &q;
	ptr->front = 50;
	ptr->rear = 50;
	insertrear(ptr, "Computer");
	insertrear(ptr, "Science");
	insertrear(ptr, "rules");
	insertfront(ptr, "Data");
	insertfront(ptr, "Structures");
	display(ptr);
	char arr[10];
	printf("deleted string is %s \n", deletefront(ptr,arr));
	display(ptr);
	//printf("\n front pointer is at %d \n", ptr->front);
	//printf("rear pointer is at %d \n", ptr->rear);
}