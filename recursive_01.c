#include <stdio.h>
main()
{
    int p,q,ans;
    printf("Enter no's p and q\n");
    scanf("%d %d",&p,&q);
    ans= gcd(p,q);
    printf("GCD= %d",ans);
}
int gcd(int p, int q)
 {
     if (q!= 0)
        return gcd(q, p%q);
     else
        return p;
}
