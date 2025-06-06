#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10000
int partition(int a[],int low,int high)
{
    int pivot=a[low];
    int start=low;
    int end=high;
    while(start<end)
    {
    while(a[start<=pivot])
    {
        start++;
    }
    while(a[end]>pivot)
    {
        end--;
    }
    if(start<end)
    {
        int temp=a[start];
        a[start]=a[end];
        a[end]=a[start];
    }
    }
    int temp=a[low];
    a[low]=a[high];
    a[high]=temp;
}

void quicksort(int a[] ,int low,int high)
{
    int pivotindex=partition(a,low,high);
    quicksort(a,low,pivotindex-1);
    quicksort(a,pivotindex+1,high);
}
void display(int a[], int low, int high)
{
int i;
 printf("\nElements after sorting are:\n");
 for(i=0;i<=high;i++)
{
 printf("%d\t",a[i]);
 }
}
int main()
{
int n;
 int a[MAX];
 printf("Enter the number of elements N to perform QUICK SORT : ");
 scanf("%d", &n);
 srand(time(NULL));
 for (int i = 0 ; i<n ; i++ )
{
a[i]=rand()%500;
printf("%d\t",a[i]);
 }
clock_t start = clock();
 quicksort(a, 0, n - 1);
 display(a,0,n-1);
 clock_t end = clock();
 double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000; 
 printf("\nTime taken to sort %d elements: %f milliseconds\n", n, time_taken);
return 0;
}
