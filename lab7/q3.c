#include <stdio.h>
#include <string.h>
#define MAX 100

int len;
typedef struct 
{
	char queue[MAX];
	int front1;
	int rear1;
	int front2;
	int rear2;
}QUEUE;

void enqueue1(QUEUE *ptr,char item)
{
	if(ptr->rear1 == ptr->rear2)
	{
		printf("queue overflow \n");
	}
	else
	{
		ptr->queue[++(ptr->rear1)] = item;
	}
}

char dequeue1(QUEUE *ptr)
{
	if(ptr->front1 == ptr->rear1 && ptr->rear1 != 0) 
	{
		printf("queue underflow\n");
		return 99;
	}
	else
	{
		return ptr->queue[(ptr->front1)++];
	}
}

void enqueue2(QUEUE *ptr,char item)
{
	if(ptr->rear2 == ptr->rear1 && ptr->rear2 != len - 1)
	{
		printf("queue overflow \n");
	}
	else
	{
		ptr->queue[--(ptr->rear2)] = item;
	}
}

char dequeue2(QUEUE *ptr)
{
	if(ptr->front1 == ptr->rear1)
	{
		printf("queue underflow\n");
		return 99;
	}
	else
	{
		return ptr->queue[(ptr->front2)--];
	}
}



int main()
{
	char str[100];
	QUEUE q, *ptr;
	ptr = &q;

	printf("enter a string \n");
	gets(str);
	len = strlen(str);
	ptr->front1 = 0;
	ptr->rear1 = -1;
	ptr->front2 = MAX - 1 ;
	ptr->rear2 = MAX;

	if(len % 2 == 0)
	{
		for(int i = 0; i < len/2; i++)
		{
			//printf("%c \n", str[i]);
			enqueue1(ptr,str[i]);
		}
		for(int i = len - 1; i >= len/2; i--)
		{
			//printf("%c \n", str[i]);
			enqueue2(ptr, str[i]);
		}
	}

	
	else if(len % 2 == 1)
	{
		for(int i = 0; i  < len/2; i++)
		{
			enqueue1(ptr, str[i]);
		}
		//enqueue1(ptr, str[len/2]);
		for(int i = len - 1; i > len / 2; i--)
		{
			enqueue2(ptr,str[i]);
		}

	}
	int flag = 0;
	for(int i = 0; i < len/2 - 1; i++)
	{	
		if(dequeue1(ptr) != dequeue2(ptr))
		{
			flag = 0;//printf("not a palindrome \n");
			break;
		}
		else{flag = 1;}
	}

	if(flag == 0){printf("not a palindrome\n");}
	else if(flag == 1){printf("is a palindrome\n");}

	

}