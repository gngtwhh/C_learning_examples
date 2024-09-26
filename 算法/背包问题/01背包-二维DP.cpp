// 洛谷P1048 采药

#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 100
#define MAXM 1000
using namespace std;
int main() {
    int m, n;
    cin >> m >> n;
    vector<int> w(n + 1);
    vector<int> v(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    for (int i = w[0];i <= m;++i) {
        dp[0][i] = v[0];
    }
    // 两个for循环的顺序颠倒也可以
    for (int i = 1;i < n;++i) {
        for (int j = 0;j <= m;++j) {
            if (j < w[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }
    cout << dp[n - 1][m];
    return 0;
}