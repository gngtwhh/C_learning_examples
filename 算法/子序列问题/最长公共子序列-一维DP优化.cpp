#include <algorithm>

#define MAXN 100
#define MAXM 1000
int a[MAXN], b[MAXM], f[MAXM];
int n, m;

int dp() {
	int temp = 0, old = 0;
	for (int i = 1; i <= n; ++i) {
		old = f[0]; // ���ó�ʼ��old=f[i-1][0]
		for (int j = 1; j <= m; ++j) {
			temp = f[j]; // ��ǰ,����ǰ��f[i-1][j]
			if (a[i] == b[j]) {
				f[j] = old + 1;
			} else {
				f[j] = std::max(f[j - 1], f[j]);
			}
			old = temp; // �����µ�oldֵ
		}
	}
	return f[m];
}