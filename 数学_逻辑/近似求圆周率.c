//n越大精度越高
#include<stdio.h>
int main() {
	int i,n=1000;
	double ans = 1;
	for (i = 1; i <= n; ++i)
		ans *= ((2.0 * i / (2 * i - 1)) * (2.0 * i) / (2 * i + 1));
	ans*=2;
	printf("%lf",ans);
	return 0;
}