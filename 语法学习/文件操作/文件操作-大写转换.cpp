#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	FILE* fp;
	fp = fopen("test.txt", "w+");
	char str[100];
	scanf("%s", str);
	int t;
	t = strlen(str);
	char* p;
	p = str;
	for (int i = 0; i < t; i++)
	{
		if (*p >= 'a' && *p <= 'z')
		{
			*p -= 32;
		}
		fputc(*p, fp);
		p++;
	}
	rewind(fp);
	char c;
	while ((c = fgetc(fp)) != EOF) {
		putchar(c);
	}
	fclose(fp);
	return 0;
}
