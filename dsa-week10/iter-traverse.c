// data structures lab 10 (intro to trees) Q2
// Display the elements of Binary Tree created using iterative preorder, post-order
//(Use single stack), in-order and level-order traversals.

#include <stdio.h>
#include <stdlib.h>

typedef struct node *Nodeptr;

//structure of tree node
struct node
{
    struct node *left;
    int data;
    struct node *right;
};

//for memory allocation
Nodeptr getnode()
{
    Nodeptr temp;
    temp = (Nodeptr)malloc(sizeof(struct node));
    return temp;
}

typedef struct
{
	Nodeptr stack[100];
	int top;
}STACK;

void push(STACK *st, Nodeptr cur)
{
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

Nodeptr show(STACK *s)
{
    if(isemptystack(s))
    {
        return NULL;
    }
    else{
        return s->stack[s->top];
    }
}

//the idea is to insert all the elements of the left side of the root,
// then move to the right side
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
void iterative_preorder(Nodeptr root)
{
	printf("printing using preorder\n");
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
		while(!isemptystack(s))
		{

			cur = pop(s);
			printf("%d \n", cur->data);
			if(cur->right)
			{
				push(s,cur->right);
			}
			if(cur->left)
			{
				push(s,cur->left);
			}
			else{done = 1;}
		}
	}
}

void iterative_inorder(Nodeptr root)
{
    Nodeptr cur;
    int done = 0;
    STACK *s, s1;
    s = &s1;
    s->top = -1;
    // empty condition for tree
    if(root == NULL)
    {
        printf("empty tree \n");
        return;
    }

    cur = root;
    while(!done)
    {
        while(cur != NULL)
        {
            push(s,cur);
            cur = cur->left;
        }

        if(!isemptystack(s))
        {
            cur = pop(s);
            printf("%d ", cur->data);
            cur = cur->right;
        }
        else
        {
            done = 1;
        }

    }
}

//idea is to move down to leftmost node...while going down,
//push current node and current node's right child to stack.
//on reaching leftmost node, print it if there is no right child
// if right child there then, change root so right child is processed
//before
void iterative_postorder(Nodeptr root)
{
    STACK *s, s1;
    s = &s1;
    Nodeptr curr = root;
    //empty condition for tree
    if(curr == NULL)
    {
        printf("tree is empty \n");
        return;
    }

    do
    {
        while(curr)
        {
            if(curr->right)
                push(s,curr->right);  //push right child to stack
            push(s,curr);   //push current child to stack

            curr = curr->left;  //go to next right node
        }

        //now we have reached the end, so pop the top nodeptr
        curr = pop(s);
        if(curr->right && show(s) == curr->right)
        {   //if right child is there, change the current node to it
            pop(s);
            push(s,curr);
            curr = curr->right;
        }
        else    //if right child is not there,print the current node
        {
            printf(" %d", curr->data);
            curr = NULL;
        }
    }while(!isemptystack(s));

}


int main()
{
    int item;
    Nodeptr root = NULL;
    printf("enter the root item : \n");
    scanf(" %d", &item);
    root = createbintree(item);
    iterative_preorder(root);
    iterative_inorder(root);
    iterative_postorder(root);
    return 0;
}
