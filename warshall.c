#include <stdio.h>
#define MAX 10
void warshall(int n, int A[MAX][MAX], int R[MAX][MAX])
{
 for (int i = 0; i < n; i++)
{
 for (int j = 0; j < n; j++)
{
 R[i][j] = A[i][j];
 }
 }
 for (int k = 0; k < n; k++)
{
 for (int i = 0; i < n; i++)
{
 for (int j = 0; j < n; j++)
{
 R[i][j] = R[i][j] || (R[i][k] && R[k][j]);
 }
 }
 }
}

void printMatrix(int n, int R[MAX][MAX])
{
printf("Transitive closure:\n");
 for (int i = 0; i < n; i++)
{
 for (int j = 0; j < n; j++)
{
 printf("%d ", R[i][j]);
 }
 printf("\n");
 }
}
int main()
{
int n;
 printf("Enter the number of vertices: ");
 scanf("%d", &n);
 int A[MAX][MAX];
 printf("Enter the adjacency matrix (%d x %d):\n", n, n);
 for (int i = 0; i < n; i++)
{
 for (int j = 0; j < n; j++)
{
 scanf("%d", &A[i][j]);
 }
 }
int R[MAX][MAX]; 
 warshall(n, A, R);
 printMatrix(n, R);
 return 0;
}