#include <stdio.h>
void floyd(int a[10][10], int n);
int min(int a, int b);
int main()
{
int a[10][10], i, j, n;
 printf("Enter the number of vertices: ");
 scanf("%d", &n);
 printf("Enter the adjacency matrix:\n");
 for (i = 1; i <= n; i++)
 {
 for (j = 1; j <= n; j++)
{
 scanf("%d", &a[i][j]);
 }
 }
 printf("Entered adjacency matrix is:\n");
 for (i = 1; i <= n; i++)
 {
 for (j = 1; j <= n; j++)
{
 printf("%d\t", a[i][j]);
 }
 printf("\n");
 }
 floyd(a, n);
 printf("All pair shortest path matrix:\n");
 for (i = 1; i <= n; i++)
 {
 for (j = 1; j <= n; j++)
 {
 printf("%d\t", a[i][j]);
 }
 printf("\n");
 }
 return 0;
}
void floyd(int a[10][10], int n)
{
int k, i, j;
 for (k = 1; k <= n; k++)
{
 for (i = 1; i <= n; i++)
{
 for (j = 1; j <= n; j++)
{
 a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
 }
 }
 }
}
int min(int a, int b)
{
if (a > b)
 return b;
 else
 return a;
}
