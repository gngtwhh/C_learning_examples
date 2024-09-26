#include <stdio.h>
int main() {
	int nums[100], n, k, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d", &nums[i]);
	scanf("%d", &k);
	for (i = 0; k >= nums[i] && i < n; ++i);
	for (j = n; j > i; --j)
		nums[j] = nums[j - 1];
	nums[i] = k;
	++n;
	for (i = 0; i < n; ++i)
		printf("%d ", nums[i]);
	return 0;
}