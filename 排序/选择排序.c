#include <stdio.h>
void selection_sort(int* nums, int n) {
	int k, temp;
	for (int i = 0; i < n - 1; ++i) {
		k = i;
		for (int j = i + 1; j < n; ++j) {
			if (nums[j] < nums[k])
				k = j;
		}
		temp = nums[k];
		nums[k] = nums[i];
		nums[i] = temp;
	}
}
int main() {
	int nums[100], n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &nums[i]);
	selection_sort(nums, n);
	for (int i = 0; i < n; ++i)
		printf("%d ", nums[i]);
	return 0;
}