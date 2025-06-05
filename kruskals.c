/*#include<stdio.h>
int kruskals(int n,int mincost,int cost[10][10])
{
    int ne=1,a=0,b=0,u=0,v=0,i,j,min;
    int parent[10]={0};
    while(ne<n)
    {
        min=999;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
    }
    while(parent[u]>0)
    u=parent[u];
    while(parent[v]>0)
    v=parent[v];
    if(u!=v)
    {
        printf("\n%dEdge from %d to %d:%d",ne,a,b,min);
        mincost+=min;
        ne++;
    }
    cost[a][b]=cost[b][a]=999;
    return mincost;
}

int main()
{
    int n,cost[10][10],i,j,mincost;
    printf("\n Enter the number of nodes:");
    scanf("%d",&n);
    printf("\nEnter the cost matrix:");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d\t",&cost[i][j]);
        }
    }
    mincost=kruskals(n,mincost,cost);
    printf("The minimum cost is:%d",mincost);
    return 0;
}*/
#include <stdio.h>

int kruskals(int n, int mincost, int cost[10][10]) {
    int ne = 1, a = 0, b = 0, u = 0, v = 0, i, j, min;
    int parent[10] = {0}; 

    while (ne < n) {
        min = 999;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

       
        while (parent[u] > 0)
            u = parent[u];
        while (parent[v] > 0)
            v = parent[v];

        if (u != v) {
            printf("\n%d) Edge (%d --> %d) with cost: %d", ne, a, b, min);
            mincost += min;
            parent[v] = u; 
            ne++;
        }

        cost[a][b] = cost[b][a] = 999; 
    }

    return mincost;
}

int main() {
    int n, cost[10][10], i, j, mincost = 0;

    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    mincost = kruskals(n, mincost, cost);
    printf("\nThe minimum cost is: %d\n", mincost);

    return 0;
}
