//一球从100米高度自由落下，每次落地后反跳回原高度的一半；再落下，
//求它在第10次落地时，共经过多少米？第10次反弹多高？
#include <stdio.h>
int main() {
	double sum=0,h=100;
	for(int i=0;i<10;++i){
		sum+=h;
		h/=2;
		sum+=h;
	}
	sum-=h;
	printf("sum=%lf h=%lf",sum,h);
	return 0;
}