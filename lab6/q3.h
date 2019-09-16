#include <string.h>
#define MAXSIZE 100
typedef struct{
	int queue1[MAXSIZE];
	int queue2[MAXSIZE];
	int front1;
	int rear1;
	int front2;
	int rear2;
}QUEUE;

//insert the elements in the first queue 
void insertcq1(QUEUE *ptr, int item)
{
	
	if(ptr->rear1 == MAXSIZE - 1)
	{
		printf("stack overflow \n");
	}
	else
	{
		ptr->queue1[++(ptr->rear1)] = item;
	}
}


//delete the elements from the first queue 
//and transfer it to the second queue
void deletecq1(QUEUE *ptr)
{
	if(ptr->front1 > ptr->rear1)
	{
		printf("queue underflow \n");
		//return -999;	//return an error value
	}
	else
	{
		ptr->queue2[++(ptr->rear2)] = ptr->queue1[++(ptr->front1)];
		//return ptr->queue[ptr->front1];
	}

}

void display1(QUEUE *ptr)
{
	for(int i = (ptr->front1 + 1) ; i != ptr->rear1 + 1; i = (i + 1) )
	{
		printf("%d \n", ptr->queue1[i]);
	}
	printf("\n");
}
