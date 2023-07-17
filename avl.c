#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	int height;
};
int i;
struct Node* insert(struct Node* node, int key);
main()
{
struct Node *root = NULL;
int max,x;
printf("enter the maximum elements to be added in the tree\n");
scanf("%d",&max);
for(i=0;i<max;i++)
{
    printf("enter the element to be added\n");
    scanf("%d",&x);
    root=insert(root,x);
}

preorder(root);


}

int height(struct Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}
int max(int a, int b)
{
	if(a>b)
        return a;
    else
        return b;
}

struct Node* newNode(int key)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // new node is initially added at leaf
	return(node);
}
struct Node *rightRotate(struct Node *y)
{
	struct Node *x = y->left;
	struct Node *T2 = x->right;

	x->right = y;
	y->left = T2;

	
	y->height = max(height(y->left),height(y->right)) + 1;
	x->height = max(height(x->left),height(x->right)) + 1;
        return x;
}

struct Node *leftRotate(struct Node *x)
{
	struct Node *y = x->right;
	struct Node *T2 = y->left;

	
	y->left = x;
	x->right = T2;
	x->height = max(height(x->left),height(x->right)) + 1;
	y->height = max(height(y->left),height(y->right)) + 1;
	return y;
}

int getBalance(struct Node *N)
{
    if (N == NULL)
	return 0;
    return height(N->left) - height(N->right);
}
struct Node* insert(struct Node* node, int key)
{
		if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else 
		return node;

        node->height = 1 + max(height(node->left),height(node->right));
        int balance = getBalance(node);
        if (balance > 1 && key < node->left->key)
	return rightRotate(node);
        if (balance < -1 && key > node->right->key)
        return leftRotate(node);
        if (balance > 1 && key > node->left->key)
	{
	     node->left = leftRotate(node->left);
	     return rightRotate(node);
	}
       if (balance < -1 && key < node->right->key)
	{
	     node->right = rightRotate(node->right);
	     return leftRotate(node);
	}
       return node;
}
void preorder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ",root->key);
	preorder(root->left);
	preorder(root->right);
    }
}

