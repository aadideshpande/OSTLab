//reverse a doubly linked list containing words
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node *Nodeptr;

typedef struct node{
	char data[10];
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

void insertfront(Nodeptr *first, char item[])
{
	Nodeptr temp = getnode();
	strcpy(temp->data, item);
	temp->rlink = NULL;
	temp->llink = NULL;
	Nodeptr rear = *first;

	if(isempty(*first))
	{
		*first = temp;
		//return first;
	}
	else
	{
		temp->rlink = *first;
		(*first)->llink = temp;
		temp->llink = NULL;
	}
	*first = temp;
	//return first;
}

void insertrear(Nodeptr *first, char item[])
{
	Nodeptr temp,last;
	temp = getnode();
	temp->rlink = NULL;
	temp->llink = NULL;
	strcpy(temp->data, item);
	last = *first;

	if(isempty(*first))
	{
		*first = temp;
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

char* deletefront(Nodeptr *first)
{
	// x is a local variable that will be returned,
	// hence it is declared as static
	static char x[10];
	if(isempty(*first))
	{
		printf("list is empty \n");
	}
	else if((*first)->rlink == NULL)
	{
		strcpy(x,(*first)->data);
		*first = NULL;
		return x;
	}
	else
	{
		Nodeptr temp = *first;
		strcpy(x, temp->data);
		*first = (*first)->rlink;
		(*first)->llink = NULL;
		free(temp);
		return x;
	}
}

char* deleterear(Nodeptr *first)
{
	Nodeptr temp, rear, prev;
	static char x[10];
	rear = *first;
	if(isempty(*first))
	{
		printf("list is empty \n");
		
	}
	else if((*first)->rlink == NULL && (*first)->llink == NULL)
	{
		strcpy(x, (*first)->data);
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
		strcpy(x, rear->data);
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
		printf("%s ", temp->data);
		temp = temp->rlink;
	}
	printf("\n");
}

void reverse(Nodeptr *first)
{
	// first we set a pointer to the last node of the list
	Nodeptr rear = *first;
	while(rear->rlink)
		{
			rear = rear->rlink;
		}

	// reverse the rlinks
	Nodeptr p,q,r;
	p = *first;
	q = NULL;
	while(p)
	{
		r = q;
		q = p;
		p = p->rlink;
		q->rlink = r;

	}

	*first = q;

	//reverse the llinks
	p = rear;
	q = NULL;
	while(p)
	{
		r = q;
		q = p;
		p = p->llink;
		q->llink = r;
	}
}


int main()
{
	Nodeptr first = NULL;
	insertrear(&first, "aaa");
	insertrear(&first, "bbb");
	insertrear(&first, "ccc");
	insertrear(&first, "ddd");

	//insertfront(&first, "aaa");
	//insertfront(&first, "bbb");
	//insertfront(&first, "ccc");
	//insertfront(&first, "ddd");
	display(first);

	reverse(&first);
	display(first);

	return 0;
}
