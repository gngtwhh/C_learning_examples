#include <stdio.h>
unsigned long long fun(int n) {
	if (n == 1)
		return 1;
	return n * fun(n - 1);
}
int main() {
	unsigned long long ans;
	for (int i = 1; i <= 20; ++i) {
		ans = fun(i);
		printf("%2d!=%llu\n",i, ans);
	}
	return 0;
}