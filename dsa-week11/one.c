#include <stdio.h>
#include <stdlib.h>

typedef struct node *Nodeptr;
struct node
{
	int data;
	Nodeptr llink;
	Nodeptr rlink;
};

Nodeptr getnode()
{
	Nodeptr temp = (Nodeptr)malloc(sizeof(struct node));
	return temp;
}

Nodeptr createBST(Nodeptr root, int item)
{
	if(root == NULL)
	{
		root = getnode();
		root->data = item;
		root->llink = root->rlink = NULL;
		return root;
	}
	else
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

void itersearch(Nodeptr root, int key)
{
	while(root)
	{
		if(key == root->data)
		{
			
		}
	}
}

int main()
{
	int item;
	Nodeptr root = NULL;
	printf("enter item \n");
	scanf("%d", &item);
	while(item != -1)
	{
		root = createBST(root,item);
		printf("enter next ele \n");
		scanf("%d", &item);
	}

	return 0;
}