// union and intersection of lists
#include <stdio.h>
#include <stdlib.h>
typedef struct node *Nodeptr;

//structure of each node
struct node
{
	int data;
	Nodeptr next;
};

// allocate memory to each node
Nodeptr getnode()
{
	Nodeptr temp;
	temp = (Nodeptr)malloc(sizeof(struct node));
	return temp;
}

//check if the list already has the element or not
int ismember(Nodeptr first, int item)
{
	//printf("inside ismember\n");
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
///////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////
//display the elements of the list
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
//create a linked list
Nodeptr create1()
{
	int item;
	Nodeptr first,temp,last;
	first = getnode();
	first->data = -99;
	first->next = NULL;
	last = first;
	printf("enter in ascending order \n");
	scanf(" %d", &item);

	while(item != -99)	//item = -99 will stop the input
	{
		first = insertlast(&first, item);
		printf("enter no. to be inserted \n");
		scanf( " %d", &item);
	}

	temp = first;
	first = (first)->next;
	free(temp);

	return first;
}

/*
Nodeptr create2()
{
	int item;
	Nodeptr first,temp,last;
	first = getnode();
	last = first;

	printf("enter in ascending order \n");
	scanf(" %d", &item);
	while(item != -99)	//item = -99 will stop the input
	{
		first = insertlast(&first, item);
		printf("enter no. to be inserted \n");
		scanf( " %d", &item);
	}

	temp = first;
	first = (first)->next;
	free(temp);

	return first;
}*/
////////////////////////////////////////////////
	//union of the two lists
Nodeptr Union(Nodeptr one, Nodeptr two)
{
	Nodeptr newfirst, last;
	newfirst = getnode();
	newfirst->data = -99;
	newfirst->next = NULL;
	last = newfirst;

	Nodeptr temp1 = one;
	Nodeptr temp2 = one;
	Nodeptr temp3 = two;
	Nodeptr temp;
	while(temp1)
	{
		//printf("%d ", temp1->data);
		newfirst = insertlast(&newfirst,temp1->data);
		temp1 = temp1->next;
	}
	//printf("\n");

	while(temp3)
	{
		if(ismember(one, temp3->data))
		{
			//printf("%d is a member \n", temp3->data);
		}
		else
		{
				//printf("%d ", temp3->data);
				newfirst = insertlast(&newfirst, temp3->data);
		}
		temp3 = temp3->next;
	}
	newfirst = newfirst->next;
	free(temp);
	printf("\n");
return newfirst;

}

Nodeptr Intersect(Nodeptr one, Nodeptr two)
{
	Nodeptr ifirst, last;
	ifirst = getnode();
	ifirst->data = -99;
	ifirst->next = NULL;
	last = ifirst;

	Nodeptr temp1 = one;
	Nodeptr temp3 = two;
	Nodeptr temp;
	while(temp1)
	{
		while(temp3)
		{
			if(temp1->data == temp3->data)
			{
				ifirst = insertlast(&ifirst, temp3->data);
			}
			temp3 = temp3->next;
		}
		temp3 = two;
		temp1 = temp1->next;
	}

	ifirst = ifirst->next;
	free(temp);
	printf("\n");
return ifirst;

}
//////////////////////////////////////////////////
///////////////////////////////////////////////////
int main()
{
	/*Nodeptr first = NULL;
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

	printf("search for element 550  %d \n", ismember(first, 550));
	*/

	Nodeptr one = NULL;
	one = create1();
	//display(one);
	Nodeptr two = NULL;
	two = create1();
	//display(two);
	
	Nodeptr finalunion = Union(one, two);
	display(finalunion);

	Nodeptr finalintersect = Intersect(one, two);
	display(finalintersect);
}