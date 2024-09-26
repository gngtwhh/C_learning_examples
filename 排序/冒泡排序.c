#include <stdio.h>
void bubble_sort(int* nums, int n) {
	int temp;
	for (int i = 0; i < n - 1; ++i)
		for (int j = 0; j < n - i - 1; ++j) {
			if (nums[j] > nums[j + 1]) {
				temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
}
int main() {
	int nums[100], n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &nums[i]);
	bubble_sort(nums, n);
	for (int i = 0; i < n; ++i)
		printf("%d ", nums[i]);
	return 0;
}