#include <iostream>
#define MAXN 5001
using namespace std;

int dp(int s[], int f[], int n) {
    // 朴素DP
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

int bsearch(int *arr, int n,int key) {
    int l = 0, r = n - 1;
    while (l <= r) {
        //int mid = l + ((r-l+1)>>1); // 避免溢出
        int mid = l + r >> 1;
        if (arr[mid] >= key)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}

int bsearch2(int arr[], int n, int key) {
	int l = 0, r = n - 1;
	while (l < r) {
		int mid = l + r >> 1;
		if (arr[mid] >= key)
			r = mid;
		else
			l = mid + 1;
	}
	return l;
}
int dp2(int s[], int low[], int n) {
	int ans = 0;
	for (int i = 0;i < n;++i)
		low[i] = 0x7fffffff;
	low[0] = s[0];
	for (int i = 1;i < n;++i) {
		if (s[i] > low[ans])
			low[++ans] = s[i];
		else {
            // 两个二分查找模板均可
			// int pos = bsearch(low, ans + 1, s[i]);
            int pos = bsearch2(low, ans + 1, s[i]);
			low[pos] = s[i];
		}
	}
	return ans + 1; // ans is the index of the last element
}

int main() {
	int s[MAXN];
	int f[MAXN];
	int n;
	cin >> n;
	for (int i = 0;i < n;++i)
		cin >> s[i];
	// int ans = dp(s, f, n); // 朴素dp
	int ans = dp2(s, f, n); // greedy + binary search
	cout << ans;
	return 0;
}