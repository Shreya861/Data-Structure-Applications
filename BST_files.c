#include <stdio.h>
#include <stdlib.h>
struct node
{
    int key;
    struct node* left;
    struct node* right;
};
struct node* newNode(int item);
struct node* insert(struct node* node, int key);
void inorder(struct node* root);
int max,i;
FILE*fp1,*fp2,*fp3,*fp4;
main()
{
    fp1=fopen("f1.txt","w");
    struct node* root = NULL;
    printf("enter the value for max\n");
    scanf("%d",&max);
    int a[max];
    for(i=0;i<max;i++)
    {
       a[i]=rand()%1000;
       printf("%d  ",a[i]);
       fprintf(fp1,"%d  ",a[i]);
    }
    fclose(fp1);
    printf("\n");
    fp1=fopen("f1.txt","r");
    for(i=0;i<max;i++)
    {
        fscanf(fp1,"%d",&a[i]);
        int x=a[i];
        root = insert(root,x);
    }
    fclose(fp1);
    //fp2=fopen("f2.txt","a");
    printf("inorder:");
    inorder(root);
    //fclose(fp3);
    printf("\n");
    //fp3=fopen("f3.txt","a");
    printf("preorder:");
    preorder(root);
    //fclose(fp3);
    printf("\n");
    //fp4=fopen("f4.txt","a");
    printf("postorder:");
    postorder(root);
    //fclose(fp4);
    printf("\n");



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
struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inorder(struct node* root)
{
    fp2=fopen("f2.txt","a");
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        fprintf(fp2,"%d ", root->key);
        inorder(root->right);
    }
    fclose(fp2);
}


void preorder(struct node* root)
{
    fp3=fopen("f3.txt","a");
    if (root != NULL)
    {
        printf("%d ", root->key);
        fprintf(fp3,"%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
    fclose(fp3);
}
void postorder(struct node* root)
{
     fp4=fopen("f4.txt","a");
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
        fprintf(fp4,"%d ", root->key);
    }
    fclose(fp4);
}
