#include <stdio.h>
#include <string.h>
int main() {
	char s[] = "cat is not fat,cat is thin";
	char *pc = NULL;

	//单个字符
	pc = strchr(s, 'i'); //左边第一次出现的位置
	printf("%d: %c\n", pc - s, *pc);
	pc = strrchr(s, 'i'); //右边第一次出现的位置
	printf("%d: %c\n", pc - s, *pc);

	//任意几个字符
	char keys[] = "ctf";
	pc = strpbrk(s, keys);
	printf("%d: %c\n", pc - s, *pc);

	//查找子串
	char s2[] = "fat";
	pc = strstr(s, s2);
	int s2Len = strlen(s2);
	for (int i = 0; i < s2Len; ++i) {
		putchar(pc[i]);
	}
	return 0;
}