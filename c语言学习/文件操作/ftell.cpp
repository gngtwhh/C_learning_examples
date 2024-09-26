#include <stdio.h>

int main () {
	FILE *fp;
	int len;

	fp = fopen("in.txt", "r+");
	if ( fp == NULL ) {
		perror ("打开文件错误");
		return (-1);
	}
	fseek(fp, 0, SEEK_END);

	fputs("abc",fp);
	len=ftell(fp);
	fclose(fp);
	printf("in.txt 的总大小 = %d 字节\n", len);

	return (0);
}