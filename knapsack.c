#include<stdio.h>
int main()
{
    float weight[10],profit[10],ratio[10],TotalValue,item,capacity,amount;
    int i,j,num;
    printf("Enter the number of items:");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        printf("\n\nEnter the weight and profit for item[%d]:\n",i);
        scanf("%f\t%f",&weight[i],&profit[i]);
    }
    printf("\n\nEnter Capcity of knapsack:\n");
    scanf("%f",&capacity);
    for(i=0;i<num;i++)
    {
        ratio[i]=profit[i]/weight[i];
    }
    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            if(ratio[i]<ratio[j])
            {
                int temp;
                temp=ratio[i];ratio[i]=ratio[j];ratio[j]=temp;
                temp=weight[i];weight[i]=weight[j];weight[j]=temp;
                temp=profit[i];profit[i]=profit[j];profit[j]=temp;
            }
        }
    }
    printf("\nThe Knapsack Problem Using Greedy Method:\n");
    for(i=0;i<num;i++)
    {
    if(weight[i]>capacity)
    break;
    else
    {
        TotalValue=TotalValue+profit[i];
        capacity=capacity-weight[i];
    }
}
if(i<num)
{
    TotalValue=TotalValue+(ratio[i]*capacity);
    }
    printf("The Maximum Value is:%f\n",TotalValue);
    return 0;
}
