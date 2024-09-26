#include <stdio.h>
#include <iostream>
using namespace std;
int n, num[23];
int main()
{
	cin >> n;
	int i, j;
	num[1] = 1;
	for (i = 1; i <= n; ++i) {
		for (j = i; j >= 1; --j) {
			cout << num[j]<<' ';
			if (j == i)
				num[j+1] = 1;
			num[j] += num[j - 1];
		}
		cout << endl;
	}
	return 0;
}