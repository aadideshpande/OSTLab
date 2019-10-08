//create copy of BT
#include <stdio.h>
#include <stdlib.h>

// create node with data, and two pointers
typedef struct node *Nodeptr;
struct node 
{
	char data;
	Nodeptr lchild;
	Nodeptr rchild;
};

// allocate memory for new node
Nodeptr getnode()
{
	Nodeptr temp;
	temp = (Nodeptr)malloc(sizeof(struct node));
	return temp;
}

Nodeptr createbintree(char item)
{
	char x;
	if(item != '0')
	{
		Nodeptr temp = getnode();
		//assign the new item to the node data
		temp->data = item;	
		printf("enter lchild of %c \n", item );
		scanf(" %c", &x);
		temp->lchild = createbintree(x);	//recursive function
		printf("enter rchild of %c \n", item );
		scanf(" %c", &x);
		temp->rchild = createbintree(x);	//recursive function
		return temp;
	}
}

Nodeptr copy(Nodeptr root)
{
	Nodeptr temp;
	//empty condition
	if(root == NULL)
	{
		return NULL;
	}
	temp = getnode();
	temp->data = root->data;
	temp->lchild = copy(root->lchild);
	temp->rchild = copy(root->rchild);
	return temp;
}

int main()
{
	Nodeptr root = NULL;
	char item;
	printf("creating a tree\n");
	printf("enter root \n");
	scanf(" %c",&item);
	root = createbintree(item);

	return 0;
}

