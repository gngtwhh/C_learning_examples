#include <stdio.h>
#include <string.h>
void removeExtraSpaces(char *str) {
	int p = 0, q = 0; // 双指针
	
	/*删除前导空格*/
	while (str[q] && str[q] == ' ') // 当q没有到达字符串末尾并且str[q]是空格 
		q++; // q指针不断后移跳过前导空格
	
	/*处理每一个单词*/
	while (1) {
		/*
		 * 向前复制一个单词
		 * 直到检测到到达末尾或者复制了一个空格
		 */
		while (str[q] && (str[p++] = str[q++]) != ' ');
		/* 
		 * 跳过多余空格
		 * 上一个循环已经多复制了一个空格,
		 * 所以该循环直接跳过剩余所有空格
		 */
		while (str[q] && str[q] == ' ')
			q++;
		/*检查是否到达末尾*/
		if (!str[q])
			break;
	}
	/* 
	 * 处理末尾空格并添加结束符
	 * 如果str[p-1] == ' '则说明有后置空格,用0覆盖
	 * 否则在后面追加一个0
	 */
	if (str[p - 1] == ' ')
		str[p - 1] = 0;
	else str[q] = 0;
}
int main() {
	char text[] = "   This   is    a   test   string   with   spaces.    ";
	printf("Before : \"%s\"\n", text);
	removeExtraSpaces(text);
	printf("After : \"%s\"\n", text);
	return 0;
}
