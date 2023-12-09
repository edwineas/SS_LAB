#include <stdio.h>

int main(){
	int n,i,j,b[10],sb[10],c[10][10],x,t;
    printf("Enter the Number of files : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
		printf("Enter the number of blocks in file %d : ",i+1);
		scanf("%d",&b[i]);
		printf("Enter the starting block of file %d : ",i+1);
		scanf("%d",&sb[i]);
		t = sb[i];
		for(j=0;j<b[i];j++){
			c[i][j]=t++;
		}
	}
	
	printf("File Name\tstarting block\tLength\n");
	for(i=0;i<n;i++){
			printf("%d\t%d\t%d\n",i+1,sb[i],b[i]);
	}
	
	printf("Enter the file name : ");
	scanf("%d",&x);
	printf("Length of file is : %d\n",b[x-1]);
	printf("Blocks occupied by file : ");
	for(j=0;j<b[x-1];j++){
		printf("%d ",c[x-1][j]);
	}
	printf("\n");
}
