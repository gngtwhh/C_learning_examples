#include <stdio.h>
int main() {
	double score[10],sum=0;
	int i;
	for(i=0;i<10;++i){
		scanf("%lf",&score[i]);
	}
	for(i=0;i<10;++i){
		sum+=score[i];
	}
	printf("sum=%.2f\n",sum);
	printf("average=%.2f",sum/10);
	return 0;
}