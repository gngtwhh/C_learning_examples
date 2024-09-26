#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
	char c;
	scanf("%c", &c);
	if (isdigit(c))
		printf("yes");
	else printf("no");
	/*
	字符分类
	iscntrl()任何控制字符
	isspace()空白字符
	isdigit()十进制数字
	isxdigit()十六进制数字
	islower()小写字母
	isupper()大写字母
	isalpha()字母
	isalnum()字母或数字
	ispunct()标点符号(任何不属于字母或数字的可打印字符)
	isgraph()任何图形字符
	isprint()任何可打印字符
	 */
	/*
	字符转换
	tolower()
	toupper()
	 */
	return 0;
}