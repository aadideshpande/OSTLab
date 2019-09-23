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
	else if(isempty(ptr))
	{
		ptr->front = 0;
		ptr->rear = 0;
		ptr->queue[(ptr->rear)] = item;
	}
	else
	{
		ptr->queue[++(ptr->rear)] = item;
	}
}

int dequeue(QUEUE *ptr)
{
	if(isempty(ptr))
	{
		printf("underflow \n");
	}
	else if(ptr->front == ptr->rear)
	{
		int k = ptr->queue[ptr->rear];
		ptr->front = -1;
		ptr->rear = -1;
		return k;
	}
	else
	{
		return ptr->queue[(ptr->front)++];
	}
}

void display(QUEUE *ptr)
{
	for(int i = ptr->front; i != ptr->rear + 1; i++)
	{
		printf("%d ", ptr->queue[i]);
	}
	printf("\n");
}

int isempty(QUEUE *ptr)
{
	if(ptr->front == -1 && ptr->rear == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void reverse(QUEUE *ptr)
{
	if(isempty(ptr))
	{
		return;
	}
	else
	{
		int x = dequeue(ptr);
		//return reverse(ptr);
		reverse(ptr);
		enqueue(ptr,x);

	}
}

int main()
{
	QUEUE q, *ptr;
	ptr = &q;
	ptr->front = -1;
	ptr->rear = -1;
	int n,num;

	/*enqueue(ptr, 5);
	enqueue(ptr, 10);
	enqueue(ptr, 15);
	enqueue(ptr, 20);
	enqueue(ptr, 25);
	display(ptr);
	reverse(ptr);
	display(ptr);
	*/
	printf("1. insert 2. delete, 3. display 4. exit 5.  \n");
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
		else if(n == 5)
		{
			reverse(ptr);
		}
		printf("enter another option \n");
		scanf("%d", &n);

	}
	

}