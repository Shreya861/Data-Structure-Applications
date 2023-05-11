#include<stdio.h>
main()
{
    int a[50];
    int n,key,s;
    printf("enter n\n");
    scanf("%d",&n);
    readarray(a,n);
    displayarray(a,n);
    printf("enter key\n");
    scanf("%d",&key);
    s=frequency(a,n,key);
    printf("frequency=%d",s);
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
int frequency(int a[],int n,int key)
{
    int i;
    int c=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            c++;
        }
    }
    return c;
}
