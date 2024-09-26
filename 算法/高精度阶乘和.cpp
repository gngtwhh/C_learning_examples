#include <iostream>
#include <string.h>
using namespace std;
int a[1003], b[1003], ans[1003];
int main() {
	int n, t = 0, la = 1, lb = 0, lans = 0;
	cin >> n;
	a[0] = 1;
	for (t = 1; t <= n; ++t) {
		int x = 0, ad = 0;
		do {
			x = a[lb] * t + ad;
			b[lb] += x % 10;
			ad = x / 10;
			lb++;
		} while (lb <= la+2);
		ad = 0;
		for (int i = 0; i <= lb; ++i) {
			ans[i] += b[i] + ad;
			ad = ans[i] / 10;
			ans[i] %= 10;
		}
		for (int i = 0; i <= lb; ++i)
			a[i] = b[i];
		la = lb;
		lb = 0;
		memset(b, 0, sizeof(b));
	}
	lans = la;
	while (!ans[lans])
		lans--;
	for (int i = lans; i >= 0; --i)
		cout << ans[i];
	return 0;
}