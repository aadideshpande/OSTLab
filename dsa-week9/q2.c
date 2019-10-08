// add two long positive integers using 
// circular doubly linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node *Nodeptr;

typedef struct node{
	int data;
	Nodeptr rlink;
	Nodeptr llink;
};

int isempty(Nodeptr first){return (first==NULL)?1:0 ;}

Nodeptr getnode()
{
	Nodeptr temp;
	temp = (Nodeptr)malloc(sizeof(struct node));
	return temp;
}

Nodeptr insertfront(int item, Nodeptr *head)
{
	Nodeptr temp, next;
	temp = getnode();
	temp->data = item;
	next = (*head)->rlink;
	temp->llink = *head;
	(*head)->rlink = temp;
	temp->rlink = next;
}

Nodeptr readlonginteger()
{
	Nodeptr head;
	char str[100];
	int i, n;
	printf("enter the long integer\n");
	scanf("%s", str);

	for(n = 0; str[n]; n++)
	{
		head = getnode();
		head->llink = head;
		head->rlink = head;
		for(i = n - 1; i >= 0; i--)
		{
			insertfront(str[i] - '0', &head);
		}
	} 
	return head;
}

void display(Nodeptr head)
{
	Nodeptr temp;
	for(temp = head->rlink; temp != head; temp = temp->rlink)
	{
		printf("%d ",temp->data);
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	Nodeptr a;
	a = readlonginteger();
	display(a);
	return 0;
}