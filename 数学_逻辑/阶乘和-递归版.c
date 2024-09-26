#include <stdio.h>
typedef unsigned long long ull;
ull ans = 0;
ull frac(ull i) {
	if (i == 1) {
		ans += 1;
		return 1;
	}
	ull temp = frac(i - 1)*i;
	ans += temp;
	return temp;
}
int main() {
	int n;
	scanf("%d",&n);
	frac(n);
	printf("%llu",ans);
	return 0;
}
