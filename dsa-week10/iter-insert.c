
// data structures lab 10 (intro to trees) Q1
//  Implement Binary Tree(BT) using iterative function and display the elements of the
//  BT using recursive in-order, pre-order, post-order traversal methods.
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

//iterative method to create a binary tree
void createbintree(Nodeptr *root, int item)
{
    //first, we initialize the new node
    int option;
    Nodeptr newnode = *root;    //newnode will be used to create a new node later
    Nodeptr presentnode = NULL; //the presentnode used to attach the newnode to the left or right

    //condition: the root is null i.e we are creating a root for the tree
    if(*root == NULL)
    {
        *root = getnode();
        (*root)->data = item;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return;
    }

    // incase root is not null, i.e we create children
    do
    {
        printf("1. insert to the left 2. insert to the right : ");
        scanf(" %d", &option);
        printf("\n");
        presentnode = newnode;
        if(option == 1)
            newnode = newnode->left;
        else if(option == 2)
            newnode = newnode->right;

        if(newnode == NULL)
        {
            //newnode is created
            newnode = getnode();
            newnode->data = item;
            newnode->left = NULL;
            newnode->right = NULL;
            (option == 1)?(presentnode->left = newnode):(presentnode->right = newnode);
            return;
        }

    }while(1);
}

void preorder(Nodeptr root)
{
    if(root != NULL)
    {
        printf(" %d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Nodeptr root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf(" %d", root->data);
        inorder(root->right);
    }
}

void postorder(Nodeptr root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf(" %d", root->data);
    }
}


int main()
{
    int n, ele;
    Nodeptr root;
    root = NULL;
    while(1)
    {
            printf(" \n 1. Iterative insertion\n 2.preorder traversals\n3.inorder traversals\n4. Postorder traversals\n5. Exit\n");
          	scanf(" %d", &n);
          	switch(n)
          	{
                case 1:
                    printf("enter node \n");
                    scanf(" %d", &ele);
                    createbintree(&root, ele);
                    break;
                case 2:
                    preorder(root);
                    break;
                case 3:
                    inorder(root);
                    break;
                case 4:
                    postorder(root);
                    break;

                case 5:
                    exit(0);
          	}
    }

















}
