#include <iostream>
#define MAX_N 51
using namespace std;
int n, sum, flag, col[MAX_N + 1], dia1[MAX_N * 2], dia2[MAX_N * 2], ans[MAX_N + 1];
void dfs(int step) { //step为行
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

	for (int i = 1; i <= n; ++i) { //i为列
		if (col[i] + dia1[i - step + n] + dia2[i + step - 1] == 0) {
			col[i] = dia1[i - step + n] = dia2[i + step - 1] = 1;

			ans[step] = i;
			dfs(step + 1);

			col[i] = dia1[i - step + n] = dia2[i + step - 1] = 0;
		}
	}
	// cout<<step<<endl;
}
int main() {
	cin >> n;
	dfs(1);
	cout << sum;
	return 0;
}