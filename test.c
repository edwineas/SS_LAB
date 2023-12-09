#include <stdio.h>

int main(){
	int n,i,j,nb[10],b[10][10],x;
	printf("Enter the number of files : ");
	scanf("%d",&n);
	for (i=0;i<n;i++){
		printf("Enter the number of blocks occupied by file %d : ", i+1);
		scanf("%d",&nb[i]);
		printf("Enter the blocks occupied by file %d : ",i+1);
		for (j=0;j<nb[i];j++){
			scanf("%d",&b[i][j]);
		}
	}
	
	printf("File name\tindex\tLength\n");
	for(i=0;i<n;i++){
		printf("%d\t%d\t%d\n",i+1,b[i][0],nb[i]);
	}
	
	printf("Enter the file name : ");
	scanf("%d",&x);
	printf("Length is : %d\n",nb[x-1]);
	printf("Staring index is : %d\n",b[x-1][0]);
	printf("Blocks occupied are : ");
	for(j=0;j<nb[x-1];j++){
		printf("%d ",b[x-1][j]);
	}
	printf("\n");
}
