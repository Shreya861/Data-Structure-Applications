///minimum product subset of an array
#include <stdio.h>
#include<limits.h>
main()
{
    int a[50];
    int n,p;
    printf("enter n\n");
    scanf("%d",&n);
    readarray(a,n);
    display(a,n);
    p=min_product(a,n);
    printf("%d",p);
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
int min_product(int a[], int n)
{
    int i;
    int zero = 0,pos=0,negt=0;
    int p = 1;
    int maximum_negt = INT_MIN;
    int minimum_pos = INT_MAX;
    if (n == 1)
    {
       return a[0];
    }
    for ( i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            zero++;
            continue;
        }

        if (a[i] < 0)
        {
            negt++;
            maximum_negt = max(maximum_negt, a[i]);
        }
        if (a[i] > 0)
            minimum_pos = min(minimum_pos, a[i]);
            p = p * a[i];
        }
    if (zero == n || (negt == 0 && zero > 0))
        return 0;
    if (negt == 0)
        return minimum_pos;
    if (!(negt & 1) && negt != 0)
        p= p/ maximum_negt;
    return p;
}
int max(int a, int b)
{
    if(a>b)
    {
        return a;
    }
    else
        return b;
}

int min(int a, int b)
{
    if(a>b)
    {
        return b;
    }
    else
        return b;

}


