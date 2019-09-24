// union and intersection of lists
#include <stdio.h>
#include <stdlib.h>
typedef struct node *Nodeptr;
struct node
{
	int data;
	Nodeptr next;
};

Nodeptr getnode()
{
	Nodeptr temp;
	temp = (Nodeptr)malloc(sizeof(struct node));
	return temp;
}

int ismember(Nodeptr first, int item)
{
	Nodeptr temp = first;
	while(temp)
	{
		if(temp->data == item)
		{
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}

void insertfirst(Nodeptr *first, int item)
{
	Nodeptr temp;
	temp = getnode();
	temp->data = item;
	temp->next = NULL;
	
	if(*first == NULL)
	{
		*first = temp;
	}
	else
	{
		temp->next = *first;
		*first = temp;
	}
}

int deletefirst(Nodeptr *first)
{
	Nodeptr temp;
	if(*first == NULL)
	{
		printf("list is empty\n");
		return -99;
	}
	else if((*first)->next == NULL)
	{
		int x = (*first)->data;
		temp = *first;
		free(temp);
		*first = NULL;
		return x;
	}
	else
	{
		temp = *first;
		int x = temp->data;
		*first = (*first)->next;
		free(temp);
		return x;
	}
}

Nodeptr insertlast(Nodeptr *first, int item)
{
	Nodeptr temp = getnode();
	temp->data = item;
	temp->next = NULL;

	Nodeptr rear = *first;
	while(rear->next)
	{
		rear = rear->next;
	}
	rear->next = temp;
	return *first;
}

void display(Nodeptr first)
{
	Nodeptr temp = first;
	while(temp)
	{
		printf("%d " , temp->data);
		temp = temp->next;
	}
	printf("\n");
}
///////////////////////////////////////////////
Nodeptr create()
{
	int item;
	Nodeptr first,temp,last;
	first = getnode();
	last = first;
	printf("enter in ascending order \n");
	scanf(" %d", &item);

	while(item != -99)
	{
		last = insertlast(&last, item);
		printf("enter no. to be inserted \n");
		scanf( " %d", &item);
	}

	temp = first;
	first = first->next;
	free(temp);

	return first;
}
////////////////////////////////////////////////
Nodeptr Union(Nodeptr one, Nodeptr two)
{
	Nodeptr first, last;
	first = NULL;
	last = first;

	Nodeptr temp1 = one;
	while(temp)
	{
		first = insertlast(first,temp->data);
	}

}
//////////////////////////////////////////////////
int search(Nodeptr first, int x)
{
	Nodeptr temp;
	temp = first;
	while(temp)
	{
		if(temp->data == x)
		{
			return 1;
		}
		temp = temp->next;
	}
}
///////////////////////////////////////////////////
int main()
{
	Nodeptr first = NULL;
	insertfirst(&first, 10);
	insertfirst(&first, 20);
	insertfirst(&first, 30);
	insertfirst(&first, 40);
	deletefirst(&first);
	insertfirst(&first, 50);
	display(first);
	printf("is 50 a number %d \n", ismember(first,50));
	printf("is 60 a number %d \n", ismember(first,60));
	first = insertlast(&first, 90);
	display(first);

	printf("search for element 550  %d \n", search(first, 550));
	//Nodeptr one = create();
	//display(one);
	//Nodeptr two = create();
	//display(two);
}