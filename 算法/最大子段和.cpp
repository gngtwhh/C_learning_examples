//P1115 常规未优化做法---另见洛谷题解滚动数组(取消数组)空间优化
//状态转移方程:f[i]=max{f[i-1]+a[i] , a[i]}
//答案ans=max{f[i]}
#include <bits/stdc++.h>
using namespace std;
int a[200003],f[200003],n,ans=-999999;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		f[i] = max(f[i - 1] + a[i], a[i]);
		ans = max(f[i], ans);
	}
	cout << ans;
	return 0;
}
//其他写法(贪心???)
//#include<cstdio>
int n, j, sum, maxx; 
int main() {
    scanf("%d%d", &n, &maxx); 
    sum = maxx;
    while (--n) { 
        scanf("%d", &j); 
        sum = sum > 0 ? sum : 0; 
        sum += j; 
        maxx = maxx > sum ? maxx : sum; 
    }
    printf("%d", maxx);
    return 0 
}
