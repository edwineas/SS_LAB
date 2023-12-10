#include <stdio.h>

void main() {
    int n, i, j, nb[20], sb[20], t, x, b[20][20];
    printf("Enter no. of files:");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter no. of blocks occupied by file %d:", i + 1);
        scanf("%d", &nb[i]);
        printf("Enter the starting block of file %d:", i + 1); 
        scanf("%d", &sb[i]);
        t = sb[i];
        for (j = 0; j < nb[i]; j++) {
            b[i][j] = t++;
        }
    }
    
    printf("\nFilename\tStart block\tLength\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\n", i + 1, sb[i], nb[i]);
    }
    
    printf("Enter file name:");
    scanf("%d", &x);
    printf("Length is: %d\n", nb[x - 1]);
    printf("Blocks occupied:");
    for (i = 0; i < nb[x - 1]; i++) {
        printf("%d", b[x - 1][i]);
    }
    printf("\n");
}