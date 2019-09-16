#include <string.h>
#define MAXSIZE 100
typedef struct{
	int queue[MAXSIZE];
	int front1;
	int rear1;
	int front2;
	int rear2;
}QUEUE;



void insertcq1(QUEUE *ptr, int item)
{
	int temp = (ptr->rear1 + 1) %  MAXSIZE ;
	if(temp == ptr->front1)
	{
		printf("stack overflow \n");
	}
	else
	{
		ptr->rear1 = temp;
		ptr->queue[ptr->rear1] = item;
	}
}

void insertcq2(QUEUE *ptr, int item)
{
	int temp = (ptr->rear2 + 1) %  MAXSIZE ;
	if(temp == ptr->front2)
	{
		printf("stack overflow \n");
	}
	else
	{
		ptr->rear2 = temp;
		ptr->queue[ptr->rear2] = item;
	}
}

int deletecq1(QUEUE *ptr)
{
	int temp  = (ptr->front1 + 1) % MAXSIZE ;
	if(temp == ptr->rear1)
	{
		printf("queue underflow \n");
		return;
	}
	else
	{
		ptr->front1 = temp;
		return ptr->queue[ptr->front1];
	}

}

int deletecq2(QUEUE *ptr)
{
	int temp  = (ptr->front2 + 1) % MAXSIZE ;
	if(temp == ptr->rear2)
	{
		printf("queue underflow \n");
		return;
	}
	else
	{
		ptr->front2 = temp;
		return ptr->queue[ptr->front2];
	}

}
void display1(QUEUE *ptr)
{
	for(int i = (ptr->front1 + 1) % MAXSIZE; i != ptr->rear1 + 1; i = (i + 1) % MAXSIZE)
	{
		printf("%d \n", ptr->queue[i]);
	}
	printf("\n");
}

void display2(QUEUE *ptr)
{
	for(int i = (ptr->front2 + 1) % MAXSIZE; i != ptr->rear2 + 1; i = (i + 1) % MAXSIZE)
	{
		printf("%d \n", ptr->queue[i]);
	}
	printf("\n");
}