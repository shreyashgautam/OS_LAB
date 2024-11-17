#include <stdio.h>

int main() {
    int i, j, n, r, alloc[30][30], need[30][30], avail[10], max[30][30];
    int finish[30], work[10], safeseq[30], ind = 0, count = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &r);

    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++) {   
        for (j = 0; j < r; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the max allocation matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the available resources:\n");
    for (i = 0; i < r; i++) {
        scanf("%d", &avail[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        finish[i] = 0;
    }
    for (i = 0; i < r; i++) {
        work[i] = avail[i];
    }

    while (count < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int canFinish = 1;
                for (j = 0; j < r; j++) {
                    if (need[i][j] > work[j]) {
                        canFinish = 0;
                        break;
                    }
                }
                if (canFinish) {
                    for (j = 0; j < r; j++) {
                        work[j] += alloc[i][j];
                    }
                    safeseq[ind++] = i;
                    finish[i] = 1;
                    found = 1;
                    count++;
                }
            }
        }
        if (!found) {
            printf("\nDeadlock detected\n");
            return 0; 
        }
    }

    printf("Safe sequence: ");
    for (i = 0; i < n; i++) {
        printf("P%d ", safeseq[i]);
    }
    printf("\n");

    return 0;
}