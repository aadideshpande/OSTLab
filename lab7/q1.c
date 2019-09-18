//program to implement an ascending priority queue
#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct 
{
	int queue[MAX];
	int front;
	int rear;
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
 int dequeue(QUEUE *ptr)
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
 		char k = ptr->queue[ptr->front];
 		ptr->front += 1;
 		return k;
 	}
 }

 void compare(QUEUE *ptr, int newnum)
 {
 	int j;
 	ptr->rear += 1;
 	int m = ptr->front;
 	for(int i = ptr->front; i <= ptr->rear - 1; i++)
 	{
 		if(newnum < ptr->queue[m])
 		{
 			for( j = ptr->rear; j > m; j--)
 			{
 				ptr->queue[j] = ptr->queue[j - 1];
 			}
 			ptr->queue[j] = newnum;
 		}
 		else
 		{
 			m += 1;
 		}
 	}
 }

 void display(QUEUE *ptr)
 {
 	for(int i = ptr->front; i <= ptr->rear; i++)
 	{
 		printf("%d \t", ptr->queue[i] );
 	}
 	printf("\n");
 }


 int main()
 {
 	QUEUE q, *ptr;
 	ptr = &q;
 	initialize(ptr);
 	int num, n;

 	printf("1. insert 2. delete, 3. display  5. exit \n");
	scanf("%d", &n);

	while(n != 5)
	{
		if(n == 1)
		{
			
			printf("enter the number\n");
			//gets(str);
			scanf(" %d",&num );
			enqueue(ptr, num);
		}
		else if(n == 2)
		{
			dequeue(ptr);
		}
		else if(n == 3)
		{
			display(ptr);
		}
		else if(n == 4)
		{
			int k;
			printf("enter pq number\n");
			scanf(" %d", &k);
			compare(ptr,k);
		}


		printf("enter another option \n");
		scanf("%d", &n);

	}
 }