#include<stdio.h>
#include<string.h>
main()
{
    char txt[25];
    char patt[25];
    int n,m,y;
    printf("enter two strings\n");
    scanf("%s",txt);
    scanf("%s",patt);
    n=strlen(txt);
    printf("%d\n",n);
    m=strlen(patt);
    printf("%d\n",m);
    y=string_search(txt,patt,n,m);
    printf("the pattern is found from=%d th character of txt\n",y);


}
int string_search(char txt[],char patt[],int n,int m)
{
    int i,j;
    for(i=0;i<(n-m);i++)
    {
        j=0;
        while(j<m&&patt[j]==txt[i+j])
        {
            j++;
        }
    if(j==m)
    {
        return i+1;
    }
    }

}
