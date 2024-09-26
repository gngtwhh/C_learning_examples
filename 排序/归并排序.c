#include <stdio.h>
#include <stdlib.h>
void merge(int a[], int left, int mid, int right) {
	int i = left, j = mid + 1, k = 0;
	int* b = (int*)malloc(sizeof(int) * (right - left + 1));
	while (i <= mid && j <= right) {
		if (a[i] <= a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	while (i <= mid)
		b[k++] = a[i++];
	while (j <= right)
		b[k++] = a[j++];
	for (i = left, k = 0; i <= right; ++i)
		a[i] = b[k++];
	free(b);
}
void merge_sort(int a[], int left, int right) {
	//5(0-4)->3(0-2)|2(3-4)
	if (left == right)
		return;
	int mid = (right + left) / 2;
	merge_sort(a, left, mid);
	merge_sort(a, mid + 1, right);
	merge(a, left, mid, right);
}
int main() {
	int n, a[100];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	merge_sort(a, 0, n - 1);
	for (int i = 0; i < n; ++i)
		printf("%d ", a[i]);
	return 0;
}