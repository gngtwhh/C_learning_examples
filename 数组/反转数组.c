#include <stdio.h>
int main() {
	int nums[100], n;
	int i, temp;
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d", &nums[i]);
	for (i = 0; i < n / 2; ++i) {
		temp = nums[i];
		nums[i] = nums[n - i - 1];
		nums[n - i - 1] = temp;
	}
	for (i = 0; i < n; ++i)
		printf("%d ", nums[i]);
	return 0;
}