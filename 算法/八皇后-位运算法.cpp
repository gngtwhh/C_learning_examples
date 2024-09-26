#include <iostream>
#include <cmath>
#define MAX_N 51
using namespace std;
typedef unsigned long long ull;
int n, sum, flag, ans[MAX_N];
ull col, dia1, dia2;

void dfs(int step, ull col, ull dia1, ull dia2) { //step为行
	if (step == n + 1) {
		if (flag < 3) {
			for (int i = 1; i <= n; ++i)
				printf("%d ", ans[i]);
			printf("\n");
			flag++;
		}
		sum++;
		return;
	}

	unsigned long long bits = (~(col | dia1 | dia2)) & ((1 << n) - 1);
	unsigned long long bit;
	while (bits) {
		bit = bits & -bits;
		ans[step] = log2(bit) + 1;
		dfs(step + 1, col | bit, (dia1 | bit) << 1, (dia2 | bit) >> 1);
		ans[step] = 0;
		bits = bits & (bits - 1);
	}
}
int main() {
	cin >> n;
	dfs(1, 0, 0, 0);
	cout << sum;
	return 0;
}