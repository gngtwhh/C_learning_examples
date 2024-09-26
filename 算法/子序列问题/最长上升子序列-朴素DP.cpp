// ¼û²©¿Í
#include <iostream>
#define MAXN 5001
using namespace std;

int dp(int s[], int f[], int n) {
	int ans = 0;
	for (int i = 0;i < n;++i) {
		f[i] = 1;
		for (int j = 0;j < i;++j) {
			if (s[j] < s[i]) {
				f[i] = max(f[i], f[j] + 1);
			}
		}
		ans = max(ans, f[i]);
	}
	return ans;
}

int main() {
	int s[MAXN];
	int f[MAXN];
	int n;
	cin >> n;
	for (int i = 0;i < n;++i)
		cin >> s[i];
	int ans = dp(s, f, n); // dp
	cout << ans;
	return 0;
}