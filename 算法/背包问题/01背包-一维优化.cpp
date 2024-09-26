// Âå¹ÈP1048 ²ÉÒ©

#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 100
#define MAXM 1000
using namespace std;
int main() {
    int m, n;
    cin >> n >> m;
    vector<int> w(n + 1);
    vector<int> v(n + 1);
    vector<int> dp(m + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
        v[i] *= w[i];
    }

    for (int i = 0;i < n;++i) {
        for (int j = m;j >= w[i];--j) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[m];
    return 0;
}