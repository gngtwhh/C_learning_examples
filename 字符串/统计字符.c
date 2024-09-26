#include <stdio.h>
int main() {
	char c;
	int alpha, space, num, other;
	alpha = space = num = other = 0;
	while ((c = getchar()) != '\n') {
		if (('a' <= c && 'z' >= c) || ('A' <= c && 'Z' >= c))
			alpha++;
		else if ('0' <= c && '9' >= c)
			num++;
		else if (c == ' ')
			space++;
		else
			other++;
	}
	printf("alpha:%d,space:%d,num:%d,other:%d", alpha, space, num, other);
	return 0;
}