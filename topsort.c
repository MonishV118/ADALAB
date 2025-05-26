#include<stdlib.h>
#include<stdio.h>
#define MAX 100
int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top=-1;
void dfs(int v)
{
    visited[v]=1;
    for(int i=0;i<MAX;i++)
    {
        if(adj[v][i] && !visited[i])
        {
        dfs(i);
        }
    }
stack[++top]=v;
}

void topologicalsort(int V)
{
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }
printf(" Topological sort order ");
while(top!=-1)
{
    printf("\t%d",stack[top--]);
}
}
void main()
{
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix: \n");
    for (int i = 0; i < n; i++)
    for(int j=0;j<n;j++)
    scanf("%d", &adj[i][j]); 
    topologicalsort(n);
}
