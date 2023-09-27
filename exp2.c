#include<stdio.h>
int a[50][3];
int fstatus(int nf){
	printf("Available frames: ");
	for(int k=0;k<nf;k++)
		if(a[k][1]==0)
			printf("%d ",k);
	printf("\n");
}
int main(){
	int ms,ps,i,nf,j,c=0,np,f,k,p;
	printf("Enter the total memory size: ");
	scanf("%d",&ms);
	printf("Enter the page size: ");
	scanf("%d",&ps);
	nf=ms/ps;
	for(i=0;i<nf;i++){
		a[i][0]=-1; //page number
		a[i][1]=0; //status of frame
		a[i][2]=-1; //process id
	}
	printf("Enter the total number of process: ");
	int npg[np];
	scanf("%d",&np);
	for(i=0;i<np;i++){
		printf("Enter the number of pages needed for process %d : ",i);
		scanf("%d",&npg[i]);
		if(npg[i]>nf)
			printf("Process cannot be allocated\n");
		else{
		fstatus(nf);
			for(j=0;j<npg[i];j++){
				do{
					printf("Enter the frame number for P%d[%d]: ",i,j);
					scanf("%d",&f);
					if(a[f][1]==0){
						a[f][0]=j;
						a[f][1]=1;
						a[f][2]=i;
						c++;
					}
					else{
						printf("Frame is already allocated\n");
						fstatus(nf);
						if(c==nf){
							printf("Enter the process to be removed from frame: ");
							scanf("%d",&p);
							for(k=0;k<nf;k++){
								if(a[k][2]==p){
									a[k][0]=-1;
									a[k][1]=0;
									a[k][2]=-1;
									c--;
								}
							}
							fstatus(nf);
							goto label;
						}
						else{
							label:printf("Enter the frame number for P%d[%d]: ",i,j);
							scanf("%d",&f);
							if(a[f][1]==0){
								a[f][0]=j;
								a[f][1]=1;
								a[f][2]=i;
								c++;
							}
						}
							
					}
				}while(a[f][0]!=j);
			}
		}
	}
	printf("\n----------PAGE TABLE----------\n");
	printf("Process.no\tpage.no\t\tFrame\n");
	for(i=0;i<np;i++){
		for(j=0;j<npg[i];j++){
			for(k=0;k<nf;k++){
				if(a[k][2]==i){
					if(a[k][0]==j&&a[k][1]==1){
						printf("%d\t\t%d\t\t%d\n",i,j,k);
						break;
					}
				}
				else{
					if(k+1==nf)
						printf("%d\t\t%d\t\t-1\n",i,j);
				}
			}
		}
	}
	printf("\n----------FRAME TABLE----------\n");
	printf("Frame.no\tpage.no\tProcess.no\n");
	for(i=0;i<nf;i++)
		printf("%d\t\t%d\t\t%d\n",i,a[i][0],a[i][2]);
	return 0;
}

