#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void passOne(char label[10], char opcode[10], char operand[10], char code[10], char mnemonic[3]);
void display();

int main(){
	char label[10], opcode[10], operand[10]; // for reading from input
	char code[10], mnemonic[3];// for reading from optab
	passOne(label, opcode, operand, code, mnemonic);
	return 0;
}

void passOne(char label[10], char opcode[10], char operand[10], char code[10], char mnemonic[3]){
	int locctr, start, length;
	FILE *fp1, *fp2, *fp3, *fp4, *fp5; // file pointers
	fp1 = fopen("input.txt", "r"); // read mode
    fp2 = fopen("optab.txt", "r");
    fp3 = fopen("symtab.txt", "w"); // write mode
    fp4 = fopen("intermediate.txt", "w");
    fp5 = fopen("length.txt", "w");
    fscanf(fp1, "%s\t%s\t%s", label, opcode, operand); // read first line
    if (strcmp(opcode, "START") == 0) {
    	start = atoi(operand); //it converts ASCII to integer
    	locctr = start;
    	fprintf(fp4, "\t%s\t%s\t%s\n", label, opcode, operand); // write to output file
    	fscanf(fp1, "%s\t%s\t%s", label, opcode, operand);
    }
    else
    	locctr=0;
    while (strcmp(opcode, "END") != 0) {
    	fprintf(fp4, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);
    	if (strcmp(label, "**") != 0) {
            fprintf(fp3, "%s\t%d\n", label, locctr);
        }
        fscanf(fp2, "%s\t%s", code, mnemonic); //read from optab
        while (strcmp(code, "END") != 0) {
        	if (strcmp(opcode, code) == 0){
        		locctr += 3;
                break;
        	}
        	fscanf(fp2, "%s\t%s", code, mnemonic);
        }
        if (strcmp(opcode, "WORD") == 0) // WORD -> add 3 to locctr
            locctr += 3;
        else if (strcmp(opcode, "RESW") == 0) // RESW -> add 3*operand to locctr
            locctr += (3 * (atoi(operand)));
    	else if (strcmp(opcode, "BYTE") == 0) // BYTE -> add 1 to locctr 
            ++locctr;
        else if (strcmp(opcode, "RESB") == 0) // RESB -> add operand to locctr
            locctr += atoi(operand);
        fscanf(fp1, "%s\t%s\t%s", label, opcode, operand);
    }
    fprintf(fp4, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand); //transfer last line to file
    fclose(fp4);
    fclose(fp3);
    fclose(fp2);
    fclose(fp1);
    display();
    length = locctr - start;
    fprintf(fp5, "%d", length);
    fclose(fp5);
    printf("\nThe length of the code : %d\n", length);
}

void display() {
	char str;
    FILE *fp1, *fp2, *fp3;
    printf("\nThe contents of Input Table :\n\n"); //Input Table
    fp1 = fopen("input.txt", "r");
    str = fgetc(fp1);
    while (str != EOF) {
        printf("%c", str);
        str = fgetc(fp1);
    }
    fclose(fp1);
    printf("\n\nThe contents of Intermediate Table :\n\n"); //Output Table
    fp2 = fopen("intermediate.txt", "r");
    str = fgetc(fp2);
    while (str != EOF) {
        printf("%c", str);
        str = fgetc(fp2);
    }
    fclose(fp2);
    printf("\n\nThe contents of Symbol Table :\n\n"); //Symtable
    fp3 = fopen("symtab.txt", "r");
    str = fgetc(fp3);
    while (str != EOF) {
        printf("%c", str);
        str = fgetc(fp3);
    }
    fclose(fp3);
}
