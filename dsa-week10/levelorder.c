#include <stdio.h>
#include <stdlib.h>

typedef struct node *Nodeptr;
struct node{
	int data;
	Nodeptr left;
	Nodeptr right;
};

Nodeptr getnode(){
	Nodeptr temp = (Nodeptr)malloc(sizeof(struct node));
	return temp;
}

typedef struct
{
	Nodeptr queue[20];
	int front;
	int rear;
}QUEUE;

void insert(QUEUE *ptr, Nodeptr node)
{
	if(ptr->rear == 19)
	{
		printf("queue full \n");
		return;
	}
	else if(ptr->front == -1 && ptr->rear == -1)
	{
		ptr->front = 0;
		ptr->rear = 0;
		ptr->queue[ptr->rear] = node;
	}
	else
	{
		ptr->queue[++(ptr->rear)] = node;
	}
}

Nodeptr delete(QUEUE *ptr)
{
	if(ptr->front == -1 && ptr->rear == -1)
	{
		printf("queue is empty \n");
		return NULL;
	}
	else if(ptr->front == ptr->rear)
	{
		Nodeptr temp = ptr->queue[ptr->front];
		ptr->front = -1;
		ptr->rear = -1;
		return temp;
	}	
	else
	{
		return ptr->queue[(ptr->front)++];
	}
}

Nodeptr createbintree(int item)
{
    int x;
    if(item != -1)
    {
        Nodeptr temp = getnode();
        temp->data = item;

        printf("enter the left child of %d  \n", item);
        scanf(" %d", &x);
        temp->left = createbintree(x);

        printf("enter the right child of %d  \n", item);
        scanf(" %d", &x);
        temp->right = createbintree(x);

        return temp;
    }
}

void levelorder(Nodeptr root)
{
	Nodeptr temp;
	QUEUE *q, q1;
	q = &q1;
	q->front = -1;
	q->rear = -1;
	insert(q,root);
	while(!(q->front == -1 && q->rear == -1))
	{
		temp = delete(q);
		printf("%d ", temp->data);
		if(temp->left){insert(q,temp->left);}
		if(temp->right){insert(q,temp->right);}
	}
}






int main()
{
    int item;
    Nodeptr root = NULL;
    printf("enter the root item : \n");
    scanf(" %d", &item);
    root = createbintree(item);
    levelorder(root);
    return 0;
}
