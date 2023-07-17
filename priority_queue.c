#include<stdio.h>
#include<time.h>
#define max 10
struct node
{
    int a[max];
    int priority;

};
 int f;
int r;
struct node queue[max];
FILE*fp1;
main()
{

   struct node p;
   f=-1;
   r=-1;
   int i,j,ch;
   i=0;
   time_t s;
   srand((unsigned)time(&s));
   while(1)
   {
      printf("1.insert\n");
      printf("2.delete\n");
      printf("3.display\n");
      printf("4.exit\n");
      printf("enter the choice\n");
      scanf("%d",&ch);
      switch(ch)
   {
       case 1:if(i<=max)
            {
              p.a[i]=rand();
              //p.priority=rand();
              i++;
              insert(p);
            }
            else
            {
                printf("queue is full\n");
            }
               break;
       case 2: delet(p);
                break;
        //case 3: display(p);
               // break;
        case 4:exit(0);
                break;
        default:printf("invalid choice\n");
                break;
   }
   }
}
void insert(struct node p)
{
    fp1=fopen("f1.txt","a");
    if(r==max-1)
    {
        printf("queue is full\n");
    }
    else
    {
        if(f==-1&&r==-1)
        {
            r++;
            f++;
            queue[r]=p;
        }
        else
        {
            r++;
            queue[r]=p;
            sort();
            fprintf(fp1,"%d ",queue[r]);
        }
    }
    fclose(fp1);
}
void delet(struct node p)
{
    struct node data;
    if(f==-1&&r==-1)
    {
        printf("queue is empty\n");
    }
    else
    {
        if(f==r)
        {
            data=queue[f];
            f=-1;
            r=-1;
        }
        else
        {
            data=queue[f];
             f++;
        }
    }
}
/*void display()
{
    if(f==-1&&r==-1)
    {
        printf("queue is empty\n");
    }
    else
    {
        int i;
        for(i=f;i<=r;i++)
        {
            printf("%s\t",queue[i].name);
        }
        printf("%s\t",queue[i].name);
    }
    printf("\n");

}*/
void sort()
{
    struct node temp;
    int i,j;
    for(i=f;i<=r-f+1;i++)
    {
        for(j=f;j<=r-f-i;j++)
        {
            if(queue[j].priority<queue[j+1].priority)
            {
                temp=queue[j];
                queue[j]=queue[j+1];
                queue[j+1]=temp;
            }
        }
        printf("\t");
    }
}


