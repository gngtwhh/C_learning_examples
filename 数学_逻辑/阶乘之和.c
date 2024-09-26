//求1+2!+3!+...+20!的和
#include <stdio.h>
int main() {
	unsigned long long ans = 1, sum = 0;
	int i;
	for (i = 1; i <= 20; ++i) {
		ans *= i;
		sum+=ans;
	}
	printf("%llu", sum);
	return 0;
}


