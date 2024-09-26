#include <stdio.h>
int main() {
	double score[10], sum = 0, average = 0;
	int i, num = 0;
	for (i = 0; i < 10; ++i) {
		scanf("%lf", &score[i]);
	}
	for (i = 0; i < 10; ++i) {
		sum = sum + score[i];
	}
	average = sum / 10;
	for (i = 0; i < 10; ++i) {
		if (score[i] < average) {
			num++;
		}
	}
	printf("%d", num);
	return 0;
}