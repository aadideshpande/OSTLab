//evaluate postfix expression 
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

void postorder(Nodeptr root)
{
	if(root)
	{
		//postorder means first traverse left subtree
		// then traverse right subtree
		// finally process the node
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%c ", root->data);
	}
}



int main()
{
	Nodeptr root = NULL;
	char item;
	printf("creating a tree\n");
	printf("enter root \n");
	scanf(" %c",&item);
	root = createbintree(item);
	postorder(root);
	return 0;
}

