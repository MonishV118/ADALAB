#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int n, int w[], int p[], int capacity) {
    int v[20][20], i, j;

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else if (w[i] > j)
                v[i][j] = v[i - 1][j];
            else
                v[i][j] = max(v[i - 1][j], p[i] + v[i - 1][j - w[i]]);
        }
    }

    printf("\nMaximum Profit = %d\n", v[n][capacity]);
    printf("Items included (by index): ");
    printf("The contents of the knapsack table are:\n");
 for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
 printf("%d ", v[i][j]);
 }
 printf("\n");
 }

    i = n;
    j = capacity;
    while (i > 0 && j > 0) {
        if (v[i][j] != v[i - 1][j]) {
            printf("%d ", i);
            j = j - w[i];
        }
        i--;
    }
    printf("\n");
}

int main() {
    int n, w[20], p[20], capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights:\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    printf("Enter profits:\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    knapsack(n, w, p, capacity);
    printf("Entered information about knapsack problem are:\n");
 printf("ITEM\tWEIGHT\tPROFIT\n");
 for (int i = 1; i <= n; i++)
 printf("%d\t%d\t%d\n", i, w[i], p[i]);
 printf("Capacity = %d\n", m);
    return 0;
}