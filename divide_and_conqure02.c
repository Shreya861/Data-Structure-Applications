///maximum sub array sum
#include<stdio.h>
main()
{
    int a[50];
    int n,s;
    printf("enter n\n");
    scanf("%d",&n);
    readarray(a,n);
    display(a,n);
    int l,u;
    printf("enter the l and u of sub array\n");
    scanf("%d%d",&l,&u);
    if(l>u)
    {
        printf("invalid\n");
    }
    else
    {
       s=max_sum(a,l,u);
       printf("maximum sub array sum= %d ",s);
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
int max_sum(int a[],int l,int u)
{
    if(l==u)
    {
        return a[l];
    }
    else
    {
        int mid=(l+u)/2;
        int x=a[mid];
        int i,j;
        int lsum=0;
        int rsum=0;
        for(i=l;i<=mid;i++)
        {
            lsum=lsum+a[i];
        }
        for(j=mid;j<=u;j++)
        {
          rsum=rsum+a[j];
        }
        int t=lsum+rsum-x;
        if(t>lsum&&t>rsum)
        {
            return t;
        }
        else if(lsum>t&&lsum>rsum)
        {
            return lsum;
        }
        else
            return rsum;
    }
}
