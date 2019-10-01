//doubly linked list without header node 
#include <stdio.h>
#include <stdlib.h>

typedef struct node *Nodeptr;

typedef struct node{
	int data;
	Nodeptr rlink;
	Nodeptr llink;
}NODE;

int isempty(Nodeptr first){return (first==NULL)?1:0 ;}

Nodeptr getnode()
{
	Nodeptr temp;
	temp = (Nodeptr)malloc(sizeof(struct node));
	return temp;
}

void insertfront(Nodeptr *first, int item)
{
	Nodeptr temp = getnode();
	temp->data = item;
	temp->rlink = NULL;
	temp->llink = NULL;
	if(isempty(*first))
	{
		*first = temp;
		//return first;
	}
	else
	{
		temp->rlink = *first;
		temp->llink = NULL;
	}
	*first = temp;
	//return first;
}

void insertrear(Nodeptr *first, int item)
{
	Nodeptr temp,last;
	temp = getnode();
	temp->rlink = NULL;
	temp->llink = NULL;
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

int deletefront(Nodeptr *first)
{
	int x;
	if(isempty(*first))
	{
		printf("list is empty \n");
		return -99;
	}
	else if((*first)->rlink == NULL)
	{
		x = (*first)->data;
		*first = NULL;
		return x;
	}
	else
	{
		Nodeptr temp = *first;
		x = temp->data;
		*first = (*first)->rlink;
		(*first)->llink = NULL;
		free(temp);
		return x;
	}
}

int deleterear(Nodeptr *first)
{
	Nodeptr temp, rear, prev;
	int x;
	rear = *first;
	if(isempty(*first))
	{
		printf("list is empty \n");
		return -99;
	}
	else if((*first)->rlink == NULL && (*first)->llink == NULL)
	{
		x = (*first)->data;
		*first = NULL;
		return x;
	}
	else
	{
		while(rear->rlink)
		{
			rear = rear->rlink;
		}
		temp = rear;
		prev = rear->llink;
		prev->rlink = NULL;
		x = rear->data;
		free(rear);
		return x;
	}
}

void display(Nodeptr first)
{
	Nodeptr temp;
	temp = first;
	while(temp)
	{
		printf("%d ", temp->data);
		temp = temp->rlink;
	}
	printf("\n");
}

int main()
{
	Nodeptr first = NULL;
	/*insertfront(&first, 10);
	insertfront(&first, 20);
	insertfront(&first, 30);
	insertfront(&first, 40);
	insertfront(&first, 50);
	
	deletefront(&first);
	deletefront(&first);
	deletefront(&first);
	deletefront(&first);
	deletefront(&first);
	deletefront(&first);
	display(first);

	*/

	insertrear(&first, 60);
	insertrear(&first, 70);
	insertrear(&first, 80);
	insertrear(&first, 90);
	display(first);
	deleterear(&first);

	//deletefront(&first);
	//deletefront(&first);
	//deletefront(&first);
	//deletefront(&first);
	//deletefront(&first);
		deleterear(&first);
		deleterear(&first);
		deleterear(&first);
		deleterear(&first);
	display(first);
	return 0;
}