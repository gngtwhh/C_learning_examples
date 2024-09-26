#include <iostream>
using namespace std;
int main() {
	int i[4] = { 1, 2, 3, 4 }, * p = NULL;
	p = i;
	p = &i[0];
	char* j[3] = { (char*)"int", (char*)"char", (char*)"double" }, * q = NULL;
	q = j[0];
}

//多级指针与自增运算符结合遍历字符串数组
#include <stdio.h>
#include <string.h>
int main() {
	const char* strs[4] = {
		"A string!",
		"Another!",
		"Last one!",
		NULL
	};
	char** pstrs = (char**)strs;
	char* pstr = NULL;
	while ((pstr = *pstrs++) != NULL) {
		printf("%s\n", pstr);
	}
	return 0;
}

//一次性查找(会破坏指针数组)
#include <stdio.h>
#include <assert.h>
#define TRUE 1
#define FALSE 0
int
find_char(char** strings, char value) {
	assert(strings != NULL);
	//对于列表中的每个字符串大大..
	while (*strings != NULL) {
		//观察字符串中的每个字符，看看它是否是我们查找的那个大
		while (**strings != '\0') {
			if (*(*strings)++ == value)
				return TRUE;
		}
		strings++;
	}
	return FALSE;
}
int
main() {
	const char* strs[4] = {
		"A string!",
		"Another!",
		"Last one!",
		NULL
	};
	char c;
	c = getchar();
	printf("%d", find_char((char**)strs, c));
	return 0;
}