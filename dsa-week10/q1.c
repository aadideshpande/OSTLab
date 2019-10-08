//display elements using inorder, preorder and postorder
#include <stdio.h>
#include <stdlib.h>

typedef struct node *Nodeptr;
typedef struct 
{
	Nodeptr stack[100];
	int top;
}STACK;

void push(STACK *st, Nodeptr cur)
{
	printf("inside push \n");
	st->stack[++(st->top)] = cur;
}

Nodeptr pop(STACK *st)
{
	return st->stack[(st->top)--];
}

int isemptystack(STACK *s)
{
	if(s->top == -1){return 1;}
	else{return 0;}
}

struct node 
{
	int data;
	Nodeptr lchild;
	Nodeptr rchild;
};

Nodeptr getnode()
{
	Nodeptr temp;
	temp = (Nodeptr)malloc(sizeof(struct node));
	return temp;
}

Nodeptr createbintree(int item)
{
	int x;
	if(item != -1)
	{
		Nodeptr temp = getnode();
		temp->data = item;
		printf("enter lchild of %d \n", item );
		scanf("%d", &x);
		temp->lchild = createbintree(x);
		printf("enter rchild of %d \n", item );
		scanf("%d", &x);
		temp->rchild = createbintree(x);
		return temp;
	}
}

void iterative_inorder(Nodeptr root)
{
	Nodeptr cur;
	int done = 1;
	STACK *s, s1;	
	s = &s1;
	s->top = -1;
	
	if(root == NULL)
	{
		printf("empty tree \n");
		return;
	}
	cur = root;

	while(done)
	{
		while(cur!= NULL)
		{
			printf("here1\n");
			push(s,cur);
			cur = cur->lchild;
		}
		if(isemptystack(s))
		{
			printf("here2\n");
			cur = pop(s);
			printf("%d \n",cur->data);
			cur = cur->rchild;
		}
		else
		{
			done = 0;
		}
	}
}

void iterative_preorder(Nodeptr root)
{
	Nodeptr cur;
	int done = 0;
	STACK *s, s1;
	s = &s1;
	s->top = -1;
	if(root == NULL)
	{
		printf("empty tree \n");
		return;
	}
	cur = root;

	while(!done)
	{
		push(s, cur);
		cur = cur->lchild;
	}

	while(!isemptystack(s))
	{
		cur = pop(s);
		printf("%d \n", cur->data);
		cur = cur->rchild;

		if(cur->rchild)
		{
			push(s,cur->rchild);
		}
		if(cur->lchild)
		{
			push(s,cur->lchild);
		}
		else{done = 1;}
	}



}

int main()
{
	Nodeptr root = NULL;
	int item;
	printf("creating a tree\n");
	printf("enter root \n");
	scanf("%d",&item);
	root = createbintree(item);
	iterative_inorder(root);
	iterative_preorder(root);
	return 0;
}

