#include <stdio.h>

void main() {
    int n, i, j, b[20], sb[20], t, x, c[20][20];
    printf("Enter no. of files:");
    scanf("%d", &n); // n is the number of files
    for (i = 0; i < n; i++) { // Loop through each file
        printf("Enter no. of blocks occupied by file %d:", i + 1);
        scanf("%d", &b[i]); // b[i] is the number of blocks occupied by file i+1
        printf("Enter the starting block of file %d:", i + 1); 
        scanf("%d", &sb[i]); // sb[i] is the starting block of file i+1
        t = sb[i]; // t[i] is the starting block of file i+1
        for (j = 0; j < b[i]; j++) {
            c[i][j] = t++; // c[i][j] is the block number of the jth block of file i+1
        }
    }
    
    printf("\nFilename\tStart block\tLength\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\n", i + 1, sb[i], b[i]);
    }
    
    printf("Enter file name:");
    scanf("%d", &x);
    printf("Length is: %d\n", b[x - 1]);
    printf("Blocks occupied:");
    for (i = 0; i < b[x - 1]; i++) {
        printf("%d", c[x - 1][i]);
    }
    printf("\n");
}