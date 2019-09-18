//check if palindrome or not using queue
#include <stdio.h>
#include<string.h>
#define MAX 100
 
 typedef struct 
 {
 	char queue[MAX];
 	int front;
 	int rear;
 	int rear2;
 }QUEUE;

//initialize the front and rear to -1
 void initialize(QUEUE *ptr)
 {
 	ptr->front = -1;
 	ptr->rear = -1;
 }
//check if queue is empty or not
 int isempty(QUEUE *ptr)
 {
 	if(ptr->front == -1 && ptr->rear == -1)
 	{
 		return 1;
 	}
 	return 0;
 }
//check if queue is full or not
 int isfull(QUEUE *ptr)
 {
 	if(ptr->rear == MAX - 1)
 	{
 		return 1;
 	}
 	return 0;
 }
//function to add elements to the queue
 void enqueue(QUEUE *ptr, int item)
 {
 	if(isfull(ptr))
 	{
 		printf("queue is full \n");
 	}
 	else if(isempty(ptr))
 	{
 		ptr->front = 0;
 		ptr->rear = 0;
 		ptr->queue[ptr->rear] = item;
 	}
 	else
 	{
 		ptr->rear += 1;
 		ptr->queue[ptr->rear] = item;
 	}
 }
// function to delete elements from the queue
 char dequeue(QUEUE *ptr)
 {
 	if(isempty(ptr))
 	{
 		printf("queue is empty \n"); 
 	}
 	else if(ptr->front == ptr->rear)
 	{
 		char k = ptr->queue[ptr->front];
 		ptr->front = -1;
 		ptr->rear = -1;
 		return k;
 	}
 	else
 	{
 		//printf("inside dequeue %c \n",ptr->queue[ptr->front] );
 		char k = ptr->queue[ptr->front];
 		ptr->front += 1;
 		return k;
 	}
 }

//compare the first and last element of the queue and proceed
int compare(QUEUE *ptr, int len)
{	
	ptr->rear2= ptr->rear;
	for(int i = 0; i < len/2; i++)
	{
		if(dequeue(ptr) == ptr->queue[ptr->rear2])
		{
			ptr->rear2 -= 1;
			continue;
		}
		else
		{
		 	return 0;
		}
	}
	return 1;
}

int main()
{
	QUEUE q, *ptr;
	ptr = &q;
	initialize(ptr);
	char str[100];

	printf("enter a string \n");
	gets(str);
	int len = strlen(str);
	//add the elements of the string to the queue
	for(int i = 0; i < len; i++)
	{
		enqueue(ptr, str[i]);
	}
	
	int flag = compare(ptr, len);

	if(flag == 0)
	{
		printf("not a palindrome\n");
	}
	else if(flag == 1)
	{
		printf("is a palindrome\n");
	}
}