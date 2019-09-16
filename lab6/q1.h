#include <string.h>
#define MAXSIZE 100
typedef struct{
	char queue[MAXSIZE][10];
	// MAXSIZE is the number of strings,
	// 10 is size of each string
	int front;
	int rear;
}QUEUE;



void insertcq(QUEUE *ptr, char item[])
{
	int temp = (ptr->rear + 1) %  MAXSIZE;
	if(temp == ptr->front)
	{
		printf("stack overflow \n");
	}
	else
	{
		ptr->rear = temp;
		//copy the new string to the queue
		strcpy(ptr->queue[ptr->rear], item);
	}
}

void deletecq(QUEUE *ptr)
{
	int temp  = (ptr->front + 1) % MAXSIZE;
	if(temp == ptr->rear)
	{
		printf("queue underflow \n");
		//return;
	}
	else
	{
		ptr->front = temp;
	}

}

void display(QUEUE *ptr)
{
	for(int i = (ptr->front + 1) % MAXSIZE; i != ptr->rear + 1; i = (i + 1) % MAXSIZE)
	{
		puts(ptr->queue[i]);
	}
	printf("\n");
}