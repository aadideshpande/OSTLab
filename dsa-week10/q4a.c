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

//LVR
void preorder(Nodeptr root)
{
	if(root)
	{
		preorder(root->lchild);
		printf("%c ", root->data);
		preorder(root->rchild);
	}
}

void equality(Nodeptr root1, Nodeptr root2)
{
	if(root1->data != root2->data)
	{
		printf("the trees are not equal\n");
	}
	else
	{
		equality(root1->lchild,root2->lchild);
		equality(root1->rchild,root2->lchild);
	}
}

int main()
{
	Nodeptr root = NULL;
	Nodeptr newroot = NULL;
	char item;
	printf("creating a tree\n");
	printf("enter root \n");
	scanf(" %c",&item);
	root = createbintree(item);
	Nodeptr ptr1 = root;
	preorder(ptr1);
	newroot = copy(root);
	printf("\n");
	preorder(newroot);
	printf("\n");

	Nodeptr nnroot = NULL;
	printf("creating a tree\n");
	printf("enter root \n");
	scanf(" %c",&item);
	nnroot = createbintree(item);
	Nodeptr ptr2 = nnroot;
	preorder(ptr2);
	printf("\n");

	equality(root, nnroot);


	return 0;
}

