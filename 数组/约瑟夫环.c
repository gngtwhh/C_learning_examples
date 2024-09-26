//从1数到3,数到3的人出局,求最后留下的人的编号(从1开始)
#include <stdio.h>
int main() {
	int cir[101], n, k = 1, cnt = 0, idx = 1;
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
		cir[i] = i;
	while (cnt < n - 1) {
		while (!cir[idx])
			idx = idx % n + 1;
		if (k == 3) {
			cir[idx] = 0;
			cnt++;
		}
		idx = idx % n + 1;
		k = k % 3 + 1;
	}
	for (i = 1; i <= n; ++i)
		if (cir[i]) {
			printf("number:%2d", i);
			break;
		}
	return 0;
}