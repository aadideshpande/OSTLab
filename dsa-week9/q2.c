// add two long positive integers using 
// circular doubly linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node *Nodeptr;

typedef struct node{
	int data;
	Nodeptr rlink;
	Nodeptr llink;
}NODE;

void insertrear(Nodeptr *first, int item)
{
	Nodeptr temp,last;
	temp = getnode();
	temp->rlink = temp;
	temp->llink = temp;
	temp->data = item;
	last = *first;
	if(isempty(*first))
	{
		*first = temp;
		//return *first;
	}
	else
	{
		while(last->rlink)
		{
			last = last->rlink;
		}
		last->rlink = temp;
		temp->llink = last;
	}
}


Nodeptr readlongint()
{
	int num[10]={0};
	printf("enter the number \n");
	gets(num);
	Nodeptr head = getnode();
	Nodeptr first = NULL;
	for(int i = 0; i < len(num); i++)
	{
		insertrear(&head, num[i]);
	}
}

