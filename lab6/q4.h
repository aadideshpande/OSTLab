#include <string.h>
#define MAXSIZE 100

typedef struct{
	int stack1[MAXSIZE];
	int stack2[MAXSIZE];
	int top1;
	int top2;
}QUEUE;



//insert the elements in the queue 
void inserts(QUEUE *ptr, int item)
{
	
	if(ptr->top1 == MAXSIZE - 1)
	{
		printf("stack overflow \n");
	}
	else
	{
		ptr->stack1[++(ptr->top1)] = item;
	}
}


int deletes(QUEUE *ptr)
{
	if(ptr->top2 != -1)
	{
		int x = ptr->stack2[(ptr->top2)] ;
		ptr->stack2[(ptr->top2)--] = -99;
		return x;
	}
	else if(ptr->top1 != -1 && ptr->top2 == -1)
	{
		for(int i = ptr->top1 ; i >= 0; i--)
		{
			ptr->stack2[++(ptr->top2)] = ptr->stack1[(ptr->top1)--]; 
		}

		int x = ptr->stack2[(ptr->top2)] ;
		ptr->stack2[(ptr->top2)--] = -99;
		return x;
		//deletes(ptr);
	}
	else 
	{
		printf("no more elements \n");
		return 0;
	}
}

