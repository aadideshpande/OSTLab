//data structures lab 10 (intro to trees) Q4
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
	//create new node and copy data recursively
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

int equality(Nodeptr root1, Nodeptr root2)
{
	if(root1->data != root2->data)
	{
		printf("the trees are not equal\n");
		return 0;
	}
	else
	{   //below return will be 1 if all three contitions are true
        return ( (root1->data == root2->data) && equality(root1->lchild,root2->lchild) && equality(root1->rchild,root2->lchild) );
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

	int flag = equality(root, nnroot);
	if(flag){printf("trees are equal ");}


	return 0;
}
