//REVERSE A QUEUE
#include <stdio.h>
#define MAX 20
typedef struct {
	int queue[MAX];
	int front;
	int rear;
}QUEUE;

void enqueue(QUEUE *ptr, int item)
{
	if(ptr-> rear == MAX -1)
	{
		printf("overflow \n");
	}
	else
	{
		ptr->queue[++(ptr->rear)] = item;
	}
}

int dequeue(QUEUE *ptr)
{
	if(isempty())
	{
		printf("underflow \n");
	}
	else
	{
		return ptr->queue[(ptr->front)++];
	}
}

void display(QUEUE *ptr)
{
	if(ptr->front < ptr->rear)
	{
		for(int i = ptr->front + 1; i != ptr->rear + 1; i++)
		{
			printf("%d ", ptr->queue[i]);
		}
	}
	else if(ptr->front > ptr->rear)
	{
		for(int i = ptr->front ; i != ptr->rear ; i--)
		{
			printf("%d ", ptr->queue[i]);
		}
	}
}

int isempty(QUEUE *ptr)
{
	if(ptr->front == ptr->rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	QUEUE q, *ptr;
	ptr = &q;
	ptr->front = -1;
	ptr->rear = -1;
	int n,num;

	printf("1. insert 2. delete, 3. display 4. exit \n");
	scanf("%d", &n);

	while(n != 4)
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
			printf("rear is %d \n", ptr->rear );
			printf("front is %d \n",ptr->front );
			dequeue(ptr);
		}
		else if(n == 3)
		{
			display(ptr);
		}
		printf("enter another option \n");
		scanf("%d", &n);

	}

	int temp = ptr->front;
	ptr->front = ptr->rear;
	ptr->rear = temp;

	display(ptr);
	
}