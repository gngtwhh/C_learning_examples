//字符指针数组(?)
#include <stdio.h>
#include <string.h>
int lookup_keyword(char const* keyword[], char const* desiredWord, int N_KEYWORD) {
	for (char const ** kwp = keyword; kwp < keyword + N_KEYWORD; ++kwp) {
		if (strcmp(*kwp, desiredWord) == 0) {
			return kwp - keyword;
		}
	}
	return -1;
}
int main() {
	char const* keyword[] = {
		"do",
		"for",
		"if",
		"register",
		"return",
		"switch",
		"while"
		//如果此处增加一个NULL,那么只需kwp!=NULL即可---无需知道表的长度
	};
	char const* desiredWord = "register";
#define N_KEYWORD (sizeof(keyword)/sizeof(keyword[0]))
	int idx = lookup_keyword(keyword, desiredWord, N_KEYWORD);
	if (idx != -1)
		printf("%s -> %s", desiredWord, keyword[idx]);
	else printf("not found");
	return 0;
}
#if 0
//字符指针数组改为矩阵---只需修改形参和局部变量的声明
#include <stdio.h>
#include <string.h>
int lookup_keyword(char const(*keyword)[9], char const* desiredWord, int N_KEYWORD) {
	for (char const (* kwp)[9] = keyword; kwp < keyword + N_KEYWORD; ++kwp) {
		if (strcmp(*kwp, desiredWord) == 0) {
			return kwp - keyword;
		}
	}
	return -1;
}
int main() {
	char const keyword[][9] = {
		"do",
		"for",
		"if",
		"register",
		"return",
		"switch",
		"while"
	};
	char const* desiredWord = "register";
#define N_KEYWORD (sizeof(keyword)/sizeof(keyword[0]))
	int idx = lookup_keyword(keyword, desiredWord, N_KEYWORD);
	if (idx != -1)
		printf("%s -> %s", desiredWord, keyword[idx]);
	else printf("not found");
	return 0;
}
#endif