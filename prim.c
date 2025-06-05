#include <stdio.h>
#define INF 9999
#define MAX 10

void primMST(int n, int cost[MAX][MAX]) {
    int selected[MAX] = {0};
    int i, j, u, v, min, totalCost = 0;

    selected[0] = 1;

    printf("The edges in the Minimum Spanning Tree are:\n");

    for (i = 0; i < n - 1; i++) {
        min = INF;
        u = v = -1;

        for (j = 0; j < n; j++) {
            if (selected[j]) {
                for (int k = 0; k < n; k++) {
                    if (!selected[k] && cost[j][k] && cost[j][k] < min) {
                        min = cost[j][k];
                        u = j;
                        v = k;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            printf("%d ---> %d (Cost = %d)\n", u, v, cost[u][v]);
            selected[v] = 1;
            totalCost += cost[u][v];
        }
    }

    printf("Total cost of Minimum Spanning Tree = %d\n", totalCost);
}

int main() {
    int n, cost[MAX][MAX];
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    primMST(n, cost);
    return 0;
}
