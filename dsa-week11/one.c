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

int recsearch(Nodeptr root, int key)
{
	if(root == NULL)
		{return 0;}
	else if(root->data == key)
		{return 1;}
	else if(key < root->data)
		{return recsearch(root->llink, key); }
	else if(key > root->data)
		{return recsearch(root->rlink, key);}
}
Nodeptr Max(Nodeptr root)
{
	if(root == NULL){return NULL;}
	else if(root->rlink == NULL)
	{
		return root;
	}
	else
	{
		return Max(root->rlink);
	}
}

//to delete a node, 3 cases:
// 1. no child
// 2. one child
// 3. two children: bring min of R subtree or max of L subtree
Nodeptr Delete(Nodeptr root, int key)
{
	if(root == NULL){return NULL;}
	else if(key < root->data)
	{
		root->llink = Delete(root->llink, key);
	}
	else if(key > root->data)
	{
		root->rlink = Delete(root->rlink, key);
	}
	else	//key == root->data
	{
		if(root->llink == NULL && root->rlink == NULL)
		{
			free(root);
			root = NULL;
		}
		else if(root->llink == NULL)
		{
			Nodeptr temp = root;
			root = root->rlink;
			free(temp);
		}
		else if(root->rlink == NULL)
		{
			Nodeptr temp = root;
			root = root->llink;
			free(temp);
		}
		else
		{
			Nodeptr temp;
			temp = Max(root->llink);
			root->data = temp->data;
			root->llink = Delete(root->llink, temp->data);
		}
	}
}



void inorder(Nodeptr root)
{
	if(root)
	{
		inorder(root->llink);
		printf("%d ",root->data);
		inorder(root->rlink);
	}
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

	inorder(root);
	printf("\n");
	root = Delete(root,10);
	//root = Delete(root,20);
	inorder(root);

	return 0;
}