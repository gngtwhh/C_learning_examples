#include <stdio.h>
void reverse(const char*str) {
	size_t len = 0;
	while (str[len])
		++len;
	while (len--)
		putchar(str[len]);
}
int main() {
	char str[100];
	scanf("%s", str);
	reverse(str);
	return 0;
}