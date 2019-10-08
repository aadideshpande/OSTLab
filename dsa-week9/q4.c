#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node *Nodeptr;

struct node
{
	int coeff;
	int exp;
	Nodeptr next;
};

int isempty(Nodeptr head){return (head==NULL?1:0);}

Nodeptr getnode()
{
	Nodeptr temp = (Nodeptr)malloc(sizeof(struct node));
	return temp;
}

void attach(int c, int e, Nodeptr *rear)
{
	Nodeptr temp;
	temp = getnode();
	temp->coeff = c;
	temp->exp = e;
	temp->next = NULL;

	(*rear)->next = temp;
	(*rear) = temp;
}

Nodeptr createpoly()
{
	int c, e;
	Nodeptr front, rear, temp;
	rear = getnode();
	front = rear;

	printf("enter coefficient between -99 to end\n");
	scanf("%d", &c);

	while(c != -99)
	{
		printf("enter exponent \n");
		scanf(" %d", &e);
		attach(c,e, &rear);
		printf("enter another coefficient\n");
		scanf("%d", &c);
	}

	temp = front;
	front = front->next;
	free(temp);

	return front;
}

void display(Nodeptr first)
{
	if(first==NULL)
	{
		return;
	}
	printf("%d", first->coeff);

	if(first->exp > 1)
	{
		printf("X%d", first->exp);
	}
	else
	{
		if(first->exp == 1)
		{
			printf("X%d", first->exp);
		}
	}
	if(first->next){printf(" + ");}
	display(first->next);
}

int main()
{
	Nodeptr a;
	a = createpoly();
	display(a);
}