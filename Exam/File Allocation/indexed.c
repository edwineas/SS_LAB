#include <stdio.h>

void main() {
    int n, nb[20], i, j, b[20][20], x;
    
    printf("Enter no. of files:");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter no. of blocks occupied by file %d:", i + 1);
        scanf("%d", &nb[i]);
        printf("Enter index of blocks of file %d:", i + 1);
        for (j = 0; j < nb[i]; j++)
            scanf("%d", &b[i][j]);
    }
    
    printf("\nFile\t index\tlength\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", i + 1, b[i][0], nb[i]);
    }
    
    printf("\nEnter file name:");
    scanf("%d", &x);
    printf("Index is: %d\n", b[x-1][0]);
    printf("Block occupied are:");
    for (j = 0; j < nb[x-1]; j++) {
        printf("%d", b[x-1][j]);
    }
    printf("\n");
}