#include<stdio.h>
main()
{
    int a[50];
    int n,key,res;
    printf("enter n\n");
    scanf("%d",&n);
    readarray(a,n);
    displayarray(a,n);
    res=lin_search(a,n,key);
    if(res==1)
    {
        printf("key found\n");
    }
    else
    {
        printf("key not found\n");
    }
}
void readarray(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void displayarray(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
int lin_search(int a[],int n,int key)
{
    printf("enter key\n");
    scanf("%d",&key);
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
        {
           return 1;
        }
    }
    return 0;
}
