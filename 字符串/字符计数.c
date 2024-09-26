#include <stdio.h>
int main() {
	char c;
	int n, lower, upper, number, space, other;
	n = lower = upper = number = space = other = 0;
	while ((c = getchar()) != '\n') {
		if ('0' <= c && '9' >= c)
			number++;
		else if ('a' <= c && 'z' >= c)
			lower++;
		else if ('A' <= c && 'Z' >= c)
			upper++;
		else if (c == ' ')
			space++;
		else if (c == '\n')
			n++;
		else other++;
	}
	printf("大写:%d 小写:%d 数字:%d 空格:%d 其他:%d", upper, lower, number, space, other);
	return 0;
}