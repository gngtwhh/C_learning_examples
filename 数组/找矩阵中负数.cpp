#include <stdio.h>
int main() {
	int matrix[3][4],sum=0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			scanf("%d", &matrix[i][j]);
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			if(matrix[i][j]<0)
				sum++;
		}
	}
	printf("%d",sum);
	return 0;
}