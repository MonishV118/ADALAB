#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 1000
void selectionsort(int a[10],int n)
{
    int i,j,temp,min;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        temp=a[min];
        a[min]=a[i];
        a[i]=temp; 
    }
    printf("The sorted elements are:");
    for(i=0;i<n;i++)
    printf("\t%d",a[i]);
}

int main()
{
    srand(time(NULL));
    int n,i,a[10];
    printf("\nEnter the number of elements:");
    scanf("%d",&n);
    printf("The elements are:");
    for(i=0;i<n;i++)
    {
        a[i]=rand()%200;
        printf("\t%d",a[i]);
    }
    clock_t start=clock();
    selectionsort(a,n);
    clock_t end=clock();
    double time_taken=(double)(end-start)/(CLOCKS_PER_SEC * 1000);
    printf("\nEstimated time of %d in milliseconds is %f",n,time_taken);
    return 0;
}

