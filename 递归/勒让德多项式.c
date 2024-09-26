#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double p(int n,double x)
{
	if (n == 0)
		return 1;
	else if (n == 1)
		return x;
	return ( ( (2*n-1)*x-p(n-1,x)-(n-1)*p(n-2,x) )/n );
}
int main()
{
	int num;
	double x;
	scanf("%d%lf", &num,&x);
	double ans=p(num,x);
	printf("%lf", ans);
}