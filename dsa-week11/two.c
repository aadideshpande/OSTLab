#include <stdio.h>
#include <stdlib.h>

typedef struct node *Nodeptr;

//struture of node
struct node
{
	int data;
	Nodeptr llink;
	Nodeptr rlink;
};

//memory allocation
Nodeptr getnode()
{
	Nodeptr temp = (Nodeptr)malloc(sizeof(struct node));
	return temp;
}

Nodeptr createBST(Nodeptr root, int item)
{
	//condition when tree is empty
	if(root == NULL)
	{
		root = getnode();
		root->data = item;
		root->llink = root->rlink = NULL;
		return root;
	}
	else	//use recursion 
	{
		if(item < root->data)
		{
			root->llink = createBST(root->llink, item);
		}
		else if(item > root->data)
		{
			root->rlink = createBST(root->rlink,item);
		}
		else
		{
			printf("duplicate not allowed \n");
		}
	}
	return root;
}

Nodeptr Min(Nodeptr root)
{
	if(root == NULL){return NULL;}
	else if(root->rlink == NULL)
	{
		return root;
	}
	else
	{
		return Min(root->rlink);
	}
}

Nodeptr recsearch(Nodeptr root, int key)
{
	if(root == NULL)
		{return NULL;}
	else if(root->data == key)
		{return root;}
	else if(key < root->data)
		{return recsearch(root->llink, key); }
	else if(key > root->data)
		{return recsearch(root->rlink, key);}
}

int main()
{
	int item;
	Nodeptr root = NULL;	//tree is initially empty
	//root = createBST(root, 15);
	//root = createBST(root, 10);
	//root = createBST(root, 20);
	
	
	printf("enter item \n");
	scanf("%d", &item);
	while(item != -1)
	{
		root = createBST(root,item);
		printf("enter next ele \n");
		scanf("%d", &item);
	}

	printf("enter number whose successor you want to find \n");
	int num;
	scanf(" %d", &num);
	Nodeptr newroot = recsearch(root, num);
	Nodeptr successor = Min(newroot);
	printf("successor is %d \n", successor->data);
}