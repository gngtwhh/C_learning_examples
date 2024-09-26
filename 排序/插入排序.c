#include <stdio.h>
void insertion_sort(int* nums, int n) {
	int temp,j;
	for (int i = 1; i < n; ++i) {
		temp = nums[i];
		for (j = i - 1; j >= 0 && nums[j] > temp; --j) {
			nums[j + 1] = nums[j];
		}
		nums[j+1] = temp;
	}
}
int main() {
	int nums[100], n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &nums[i]);
	insertion_sort(nums, n);
	for (int i = 0; i < n; ++i)
		printf("%d ", nums[i]);
	return 0;
}