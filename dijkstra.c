#include <stdio.h>
#define MAX 10
void dij(int cost[MAX][MAX], int dist[MAX], int sv, int n, int path[MAX], int visited[MAX]);
void printpath(int sv, int n, int dist[MAX], int path[MAX], int visited[MAX]);
int main()
{
int i, j;
int dist[MAX], visited[MAX], cost[MAX][MAX], path[MAX];
 printf("**** DIJKSTRA'S ALGORITHM ******\n");
 printf("Enter the number of nodes: ");
 int n;
 scanf("%d", &n);
 printf("Enter the cost matrix\n");
 for (i = 0; i < n; i++)
{
 for (j = 0; j < n; j++)
{
 scanf("%d", &cost[i][j]);
 }
 }
 printf("The entered cost matrix is\n");
 for (i = 0; i < n; i++)
{
 for (j = 0; j < n; j++)
{
 printf("%d\t", cost[i][j]);
 }
 printf("\n");
}
 printf("Enter the source vertex: ");
 int sv;
 scanf("%d", &sv);
 dij(cost, dist, sv, n, path, visited);
 printpath(sv, n, dist, path, visited);
 printf("\n********* *************** *********\n");
 return 0;
}
void dij(int cost[MAX][MAX], int dist[MAX], int sv, int n, int path[MAX], int visited[MAX])
{
int count = 1, min, u = 0;
 for (int i = 0; i < n; i++)
{
 visited[i] = 0;
 dist[i] = cost[sv][i];
 if (cost[sv][i] == 999)
 path[i] = 0;
 else
 path[i] = sv;
 }
 visited[sv] = 1;
 while (count < n)
{
 min = 999;
 for (int v = 0; v < n; v++)
{
 if (dist[v] < min && visited[v] == 0)
{
 min = dist[v];
 u = v;
 }
 }
 visited[u] = 1;
 count++;
 for (int v = 0; v < n; v++)
{
 if ((dist[v]) > (dist[u] + cost[u][v]))
{
 dist[v] = dist[u] + cost[u][v];
 path[v] = u;
 }
 }
 }
}
void printpath(int sv, int n, int dist[MAX], int path[MAX], int visited[MAX])
{
for (int u = 0; u < n; u++)
{
 if (visited[u] == 1 && u != sv)
{
 printf("The shortest distance between ");
 printf("%d-> =%d is :%d\n", sv, u, dist[u]);
 int t = path[u];
 printf("The path is:\n");
 printf(" %d", u);
 while (t != sv)
{
 printf("<-->%d", t);
 t = path[t];
 }
 printf("<-->%d", sv);
 printf("\n");
 }
 }
}
