#include <stdio.h>
void fpWrite();
void fpRead();
int main(void)
{
	fpWrite();
	fpRead();


	return 0;
}
// ?write the new file
void fpWrite()
{
 		char ch;
		int cnt=0;
		FILE *fpWrite=NULL;
		fpWrite= fopen("text.txt", "a");
		if(fpWrite==NULL)
			printf("\n unable to open file...");
		else
		{
			while( (ch=fgetc(stdin))!=EOF)
			{
				cnt++;
				fputc(ch, fpWrite);
			}
			fclose(fpWrite);
			printf("%d char added to file", cnt);
		}
}
//read the file1
void fpRead()
{
	char ch;
	int cnt, line, tabs, alphabets, digits, spaces;
	FILE *fpRead=NULL;

	fpRead= fopen("text.txt", "r");
	if(fpRead==NULL)
		printf("\n unable to read file...");
	else
	{
		cnt= line= tabs= alphabets= digits= spaces=0;
		while( (ch=fgetc(fpRead))!=EOF)
		{
			//getchar();
			fputc(ch, stdout);
			if ( ( ch>=65 && ch<=90) || (ch>=97 && ch<=122))
				alphabets++;
			else if(ch>=48 && ch<=57)
				digits++;
			else if(ch=='\t')
				tabs++;
			else if(ch=='\n')
					line++;
			else if(ch==' ')
					spaces++;
			cnt++;
		}
		fclose(fpRead);
		printf("\n data read from file");
		printf("\nno of char=%d", cnt);
		printf("\nno of lines=%d", line);
		printf("\nno of tabs=%d", tabs);
		printf("\nno of spaces=%d", spaces);
		printf("\nno of digits=%d", digits);
		printf("\nno of alphabets=%d", alphabets);

	}

}
