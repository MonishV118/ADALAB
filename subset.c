#include<stdio.h>
void subset(int cs,int k,int r,int x[10],int w[10],int d);
int c=0;
int main()
{
    int n,i,d,r,x[10],j,w[10],sum=0;
    printf("\nEnter the number of elements:");
    scanf("%d",&n);
    printf("\nEnter the elements in ascending order:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
    }
    printf("\nEnter the desired sum:");
    scanf("%d",&d);
    for(i=0;i<n;i++)
    {
     sum=sum+w[i];
    }
    printf("\nThe sum is : %d",sum);
    if(sum<d || w[0]>d)
    {
    printf("\nSum is not possible!");
    return 0;
    }
    subset(0,0,sum,w,x,d);
    if(c==0)
    printf("\nSum is not possible");
    return 0;
}

void subset(int cs,int k,int r,int w[10],int x[10],int d)
{
    x[k]=1;
    if(cs+w[k]==d)
{
        c++;
    printf("\nThe solution of %d {",c);
        for(int i=0;i<=k;i++)
        {
            if(x[i]==1)
            {
            printf(" %d ",w[i]);
            }
        }
        printf("}\n");
}
    else if (cs+w[k]+w[k+1]<=d)
    {
    subset(cs+w[k],k+1,r-w[k],w,x,d);
    }
    if(cs+r-w[k]>=d && w[k+1]<=d)
    {
    x[k]=0;
    subset(cs,k+1,r-w[k],w,x,d);
    }
}
