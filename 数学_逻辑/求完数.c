//求1000以内的完数---一个数恰好等于它的因子之和
#include <stdio.h>
int main() {
	int t, sum, j;
	for (int i = 2; i <= 1000; ++i) {
		sum = 0;
		t = 1;
		j = i;
		while (j != 1 && t < i) {
			if (j % t == 0)
				sum += t;
			t++;
		}
		if (sum == i)
			printf("%d ", i);
	}
	return 0;
}