#include <stdio.h>
int main()
{
	double d;
	scanf("%lf", &d);
	printf("周长=%.2lf\n", d * 3.14);
	printf("面积=%.2lf",(d/2)*(d/2)*3.14);
	return 0;
}