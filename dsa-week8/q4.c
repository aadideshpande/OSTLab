// a linked list with unique values
#include <stdio.h>
#include <stdlib.h>

typedef struct node *Nodeptr;
struct node{
	int data;
	Nodeptr next;
};

Nodeptr getnode()
{
	Nodeptr temp;
	temp = (Nodeptr)malloc(sizeof(struct node));
	return temp;
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

Nodeptr create()
{
	int item;
	Nodeptr first,temp,last,head;
	first = getnode();
	first->data = -99;	// this is the head pointer, we will later assign 'head' to this node
	first->next = NULL;
	last = first;
	printf("enter in ascending order \n");
	scanf(" %d", &item);

	while(item != -99)	//item = -99 will stop the input
	{
		first = insertlast(&first, item);
		last = first->next;					
		printf("enter no. to be inserted \n");
		scanf( " %d", &item);
	}

	head = first;	//assign head pointer to this node
	first = (first)->next;

	return head;
}

Nodeptr unique(Nodeptr *head)
{
	Nodeptr first, last, temp1,temp2;
	temp1 = (*head)->next;

	while(temp1->next)
	{	
		Nodeptr nextnode = temp1->next;
		if(temp1->data == nextnode->data)
		{
			temp1->next = nextnode->next;
			free(nextnode);
		}
		else
		{	
			temp1 = temp1->next;
		}
	}
	return *head;
}

void display(Nodeptr head)
{
	Nodeptr temp = head->next;
	while(temp)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	Nodeptr one;
	one = create();
	one = unique(&one);
	display(one);

}