// circular singly linked list merging

#include <stdio.h>
#include <stdlib.h>

typedef struct node *Nodeptr;
struct node{
	char data;
	Nodeptr next;
};

Nodeptr getnode()
{
	Nodeptr temp;
	temp = (Nodeptr)malloc(sizeof(struct node));
	return temp;
}

int isempty(Nodeptr last)
{
	return (last == NULL)?1:0;
}

/*void insertfront(Nodeptr *last, char item, Nodeptr *first)
{
	Nodeptr temp;
	temp = getnode();
	temp->data = item;
	
	if(isempty(*last))
	{
		temp->next = temp;
		*last = temp;
	}
	else
	{
		temp->next = (*last)->next;
		(*last)->next = temp;
		*first = temp;
	}
}
*/

void insertlast(Nodeptr *last, char item, Nodeptr *first)
{
	Nodeptr temp = getnode();
	temp->data = item;
	temp->next = NULL;
	if(isempty(*first))
	{
		temp->next = temp;
		*first = temp;
		*last = temp;
	}
	else
	{
		(*last)->next = temp;
		*last = temp;
		temp->next = *first;
		
	}
}


void display(Nodeptr last, Nodeptr first)
{
	Nodeptr temp1 = first;
	Nodeptr temp2 = last;

	do
	{
		printf("%c ", temp1->data);
		temp1 = temp1->next;
	}while( temp1 != last->next);
	//printf("temp1 data is %c \n" ,temp1->data);
	printf("\n");

}

int length(Nodeptr last)
{
	int n = 0;
	Nodeptr temp = last;
	if(isempty(last)){return 0;}
	do
	{
		n++;
		temp = temp->next;
	}while(temp != last);
	return n;
}

void merge(Nodeptr lastA, Nodeptr firstA, Nodeptr lastB, Nodeptr firstB)
{
	Nodeptr lastC = NULL;
	Nodeptr firstC = NULL;
	if(isempty(lastA)){display(lastB, firstB);}
	if(isempty(lastB)){display(lastA,firstA);}

	int m = length(lastA);
	int n = length(lastB);
	Nodeptr f1 = firstA;
	Nodeptr f2 = firstB;
	int i = 0, j = 0;

	while(i < m && j < n)
	{
		if((int)f1->data < (int)f2->data)
		{
			printf("the element1 is : %c \n", f1->data );
			insertlast(&lastC,f1->data, &firstC);
			f1 = f1->next;
			i++;
		}
		else
		{
			printf("the element2 is : %c \n", f2->data );
			insertlast(&lastC, f2->data, &firstC);
			f2 = f2->next;
			j++;
		}
	}

	while(i < m)
	{
		printf("the element1 is : %c \n", f1->data );
		insertlast(&lastC,f1->data, &firstC);
		f1 = f1->next;
		i++;
	}

	while(j < n)
	{
		printf("the element2 now is : %c \n", f2->data );
		insertlast(&lastC, f2->data, &firstC);
		f2 = f2->next;
		j++;
	}

	Nodeptr fs = firstC;
	while(fs != lastC)
	{
		printf("%c ", fs->data );
		fs = fs->next;
	}
	

}





int main()
{
	Nodeptr lastA = NULL;
	Nodeptr firstA = NULL;
	insertlast(&lastA, 'a', &firstA);
	insertlast(&lastA, 'c', &firstA);
	insertlast(&lastA, 'e', &firstA);
	insertlast(&lastA, 'g', &firstA);
	insertlast(&lastA, 'i', &firstA);
	display(lastA, firstA);

	Nodeptr lastB = NULL;
	Nodeptr firstB = NULL;
	insertlast(&lastB,'b', &firstB);
	insertlast(&lastB,'d', &firstB);
	insertlast(&lastB,'f', &firstB);
	insertlast(&lastB,'j', &firstB);
	display(lastB, firstB);

	//Nodeptr lastC;
	merge(lastA,firstA,lastB,firstB);
	//display(lastC,firstC);


}
