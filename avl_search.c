
#include <stdio.h>
#include <stdlib.h>

struct node 
{
   int key;
   struct node *left, *right;
};
main()
{
    int max,x,i,key;
    struct node* root = NULL;
    printf("enter the max. elements to be added in the tree\n");
    scanf("%d",&max);
    for(i=0;i<max;i++)
    {
       printf("enter the element to be added\n");
       scanf("%d",&x);
       root=insert(root,x);
    }
	printf("enter the key to be found\n");
	scanf("%d",&key);
	if (search(root, key) == NULL)
		printf("%d not found\n", key);
	else
		printf("%d found\n", key);
	
}

struct node*newNode(int key)
{
   struct node* temp= (struct node*)malloc(sizeof(struct node));
   temp->key = item;
   temp->left = temp->right = NULL;
   return temp;
}

struct node* insert(struct node* node, int key)
{
  if (node == NULL)
     return newNode(key);
  if (key < node->key)
     node->left = insert(node->left, key);
  else if (key > node->key)
	node->right = insert(node->right, key);
  return node;
}

struct node* search(struct node* root, int key)
{
     if (root == NULL || root->key == key)
	  return root;
     if (root->key <key)
	  return search(root->right, key);
     return search(root->left, key);
}


