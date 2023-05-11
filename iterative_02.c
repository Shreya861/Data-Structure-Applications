#include<stdio.h>
main()
{
    int r,c,i,j;
    printf("enter r and c\n");
    scanf("%d%d",&r,&c);
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            printf("*");
        }
         printf("\n");
    }

}
