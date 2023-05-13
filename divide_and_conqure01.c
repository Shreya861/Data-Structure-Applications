///binary search
#include<stdio.h>
main()
{
    int a[50];
    int n,key,s;
    printf("enter n\n");
    scanf("%d",&n);
    readarray(a,n);
    display(a,n);
    printf("enter the key\n");
    scanf("%d",&key);
    s=bin_search(a,key,n);
    if(s==-1)
    {
        printf("key not found\n");
    }
    else
    {
        printf("key found\n");
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
void display(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
int bin_search(int a[],int key,int n)
{
    int l=0;
    int u=n-1;
    int mid;
    while(u>=l)
    {
        mid=(u+l)/2;
        if(key==a[mid])
        {
            return mid;
        }
        else if(key<a[mid])
        {
            u=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return -1;
}

