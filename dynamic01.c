#include<stdio.h>
main()
{
    int a[50][50],n;
    printf("enter n value:\n");
    scanf("%d",&n);
    printf("enter the adjacency matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    warshalls(a,n);
    printf("all pair shortest path:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
void warshalls(int a[50][50],int n)
{
  for(int k=0;k<n;k++)
  {
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][k]==1 &&a[k][j]==1)
            {
                a[i][j]=1;
            }
        }
    }
  }
}
