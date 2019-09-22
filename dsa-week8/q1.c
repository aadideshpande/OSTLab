//program to implement queue using linked lists
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

Nodeptr insert(Nodeptr *front, int x, Nodeptr *rear)
{
		Nodeptr temp;
		temp = getnode();
		temp->data = x;
		temp->next = NULL;
	if(*front == NULL)	//if queue is empty
	{
		*front = temp;
		*rear = temp;
	}
	else
	{	
		(*rear)->next = temp;	//insert element to the rear of queue
		(*rear) = temp;
	}
	return *rear;
}

int delete(Nodeptr *front, Nodeptr *rear)
{
	if(*front == NULL)
	{
		printf("list is empty \n");
		return -99;
	}
	Nodeptr temp = *front;
	*front = (*front)->next;
	int x  = temp->data;
	if(*front == NULL)
	{
		*rear = NULL;
	}
	free(temp);
	return x;
}

void display(Nodeptr *front, Nodeptr *rear)
{
	Nodeptr p = *front;
	while(p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	Nodeptr front = NULL;
	Nodeptr rear = NULL;
	rear = insert(&front, 11,&rear);
	rear = insert(&front, 12,&rear);
	rear = insert(&front, 13,&rear);
	rear = insert(&front, 14,&rear);
	rear = insert(&front, 15,&rear);
	display(&front, &rear);
	printf("the element that is removed is %d \n", delete(&front, &rear) );
	display(&front, &rear);
	printf("the element that is removed is %d \n", delete(&front, &rear) );
	printf("the element that is removed is %d \n", delete(&front, &rear) );
	printf("the element that is removed is %d \n", delete(&front, &rear) );
	printf("the element that is removed is %d \n", delete(&front, &rear) );
	printf("the element that is removed is %d \n", delete(&front, &rear) );
}
