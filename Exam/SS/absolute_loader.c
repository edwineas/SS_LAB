#include <stdio.h>
#include <string.h>
char input[10], label[10], ch2;
int w = 0, start, length = 0, end, count = 0, k, taddr, address, i = 0;
FILE *fp1, *fp2;
void check();
int main()
{
	fp1 = fopen("input.txt", "r");
	fp2 = fopen("output.txt", "w");
	fscanf(fp1, "%s", input);
	while (strcmp(input, "E") != 0)
	{
		if (strcmp(input, "H") == 0)
		{
			fscanf(fp1, "%s %x %x %s", label, &start, &end, input);
			address = start;
		}
		else if (strcmp(input, "T") == 0)
		{
			fscanf(fp1, "%x %x %s", &taddr, &length, input);
			while(address<taddr)
			{
				fprintf(fp2, "xx");
				check();
			}
			if (w==0){
				fprintf(fp2, "\n\n%x\t\t", taddr);
				w=1;
			}
			fprintf(fp2, "%c%c", input[0], input[1]);
			check();
			fprintf(fp2, "%c%c", input[2], input[3]);
			check();
			fprintf(fp2, "%c%c", input[4], input[5]);
			check();
			fscanf(fp1, "%s", input);
		}
		else
		{
			fprintf(fp2, "%c%c", input[0], input[1]);
			check();
			fprintf(fp2, "%c%c", input[2], input[3]);
			check();
			fprintf(fp2, "%c%c", input[4], input[5]);
			check();
			fscanf(fp1, "%s", input);
		}
	}
	fclose(fp1);
	fclose(fp2);
	printf("\n\n The contents of output file:\n");
	fp2 = fopen("output.txt", "r");
	ch2 = fgetc(fp2);
	while (ch2 != EOF)
	{
		printf("%c", ch2);
		ch2 = fgetc(fp2);
	}
	fclose(fp2);
}
void check()
{
	count++;
	address++;
	if (count == 4)
	{
		fprintf(fp2, "  ");
		i++;
		if (i == 4)
		{
			fprintf(fp2, "\n\n%x\t\t", address);
			i = 0;
		}
		count = 0;
	}
}
