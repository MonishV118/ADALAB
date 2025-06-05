#include <stdio.h>
#include <stdlib.h>

int count = 0, x[10];

int place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return 0;
    }
    return 1;
}

void nqueen(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;
            if (k == n) {
                count++;
                printf("solution=%d\n", count);
                for (int j = 1; j <= n; j++) {
                    for (int p = 1; p <= n; p++) {
                        if (x[j] == p)
                            printf("$\t");
                        else
                            printf("0\t");
                    }
                    printf("\n");
                }
                printf("\n");
            } else {
                nqueen(k + 1, n);
            }
        }
    }
}

int main() {
    int n;
    printf("\nEnter the number of queens: ");
    scanf("%d", &n);
    nqueen(1, n);
    if (count == 0)
        printf("\nNo solution found");
    else
        printf("\nNumber of solutions found: %d\n", count);
    return 0;
}
