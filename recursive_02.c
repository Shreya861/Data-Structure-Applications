#include <stdio.h>
main()
{
    int a[6];
    int n=6;
    int largest;
    readarray(a,n);
    displayarray(a,n);
    largest=max(a,0,5);
    printf("max element of array= %d",largest);

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
int max(int a[],int l,int u)
{
    int maximum;
    if (l==u)
        return a[l];
    else
    {
      maximum = max(a,l+1,u);
      if (a[l] >= maximum)
        return a[l];
     else
      return maximum;
    }
}
