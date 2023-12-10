#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display(){
	char str;
	FILE *fp1,*fp2,*fp3;
	printf("\nThe content of the Input table\n");
	fp1 = fopen("input.txt","r");
	str = fgetc(fp1);
	while (str!=EOF){
		printf("%c",str);
		str = fgetc(fp1);
	}
	fclose(fp1);
	printf("\n\nThe content of the Intermediate table\n");
	fp2 = fopen("intermediate.txt","r");
	str = fgetc(fp2);
	while (str!=EOF){
		printf("%c",str);
		str = fgetc(fp2);
	}
	fclose(fp2);
	printf("\n\nThe content of the Symbol table\n");
	fp3 = fopen("symtab.txt","r");
	str = fgetc(fp3);
	while (str!=EOF){
		printf("%c",str);
		str = fgetc(fp3);
	}
	fclose(fp3);
}

int main(){
	char label[10],opcode[10],operand[10],code[10],mnemonic[10];
	int start,locctr,length;
	FILE *fp1,*fp2,*fp3,*fp4,*fp5;
	fp1 = fopen("input.txt","r");
	fp2 = fopen("optab.txt","r");
	fp3 = fopen("symtab.txt","w");
	fp4 = fopen("intermediate.txt","w");
	fp5 = fopen("length.txt","w");
	
	fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);
	if (strcmp(opcode,"START")==0){
		start = atoi(operand);
		locctr = start;
		fprintf(fp4,"\t%s\t%s\t%s\n",label,opcode,operand);
		fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);
	}
	else
		locctr = 0;
	while (strcmp(opcode,"END")!=0){
		fprintf(fp4,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
		if (strcmp(label,"**")!=0){
			fprintf(fp3,"%s\t%d\n",label,locctr);
		}
		fscanf(fp2,"%s\t%s",code,mnemonic);
		while (strcmp(code,"END")!=0){
			if(strcmp(code,opcode)==0){
				locctr+=3;
				break;				
			}
			fscanf(fp2,"%s\t%s",code,mnemonic);
		}
		if(strcmp(opcode,"WORD")==0)
			locctr +=3;
		else if (strcmp(opcode,"RESW")==0)
			locctr += (3*(atoi(operand)));
		else if (strcmp(opcode,"BYTE")==0)
			++locctr;
		else if (strcmp(opcode,"RESB")==0)
			locctr += atoi(operand);
		fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);
	}
	fprintf(fp4,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
	fclose(fp4);
	fclose(fp3);
	fclose(fp2);
	fclose(fp1);
	display();
	length = locctr - start;
	fprintf(fp5,"%d",length);
	fclose(fp5);
	printf("\nLength of the code : %d\n",length);
}
