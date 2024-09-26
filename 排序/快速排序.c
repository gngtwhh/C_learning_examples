#include <stdio.h>
int a[1000];
void quick_sort( int left, int right) {
	if (left >= right)
		return;
	int key = a[left], i = left, j = right, temp;
	//以最左边的元素为基准
	while (i < j) {
		while (a[j] >= key && i < j)
			--j;
		while (a[i] <= key && i < j)
			++i;
		if (i != j) { //两边交换法
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	a[left] = a[i];
	a[i] = key;
	quick_sort(left, i - 1);
	quick_sort( i + 1, right);
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	quick_sort( 0, n - 1);
	for (int i = 0; i < n; ++i)
		printf("%d ", a[i]);
	return 0;
}

//ljj
/*==================
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define LENGTH 7
int Denji[LENGTH];
int ChainsawMan(int a[], int b);
void QuickSort(int array[], int L, int R);
int main(void)
{

	int i;

	printf("Enter three numbers and I will return the biggest one.\n");
	for (size_t i = 0; i < LENGTH; i++)
		scanf("%d", &Denji[i]);

	printf("The biggest number is %d", ChainsawMan(Denji, LENGTH));

	return 0;
}
int ChainsawMan(int a[], int b)
{
	int i;

	QuickSort(a, 0, b - 1);

	for (size_t i = 0; i < b; i++)
	{
		printf("%-3d", a[i]);
	}
	return a[b - 1];
}
void QuickSort(int array[], int L, int R)
{
	if (L >= R)
		return;
	int left, right, pivot;
	left = L;
	right = R;
	pivot = array[left];

	while (left < right)
	{
		while (left < right && array[right] >= pivot)
		{
			right--;
		}
		if (left < right)
		{
			array[left] = array[right];
		}
		while (left < right && array[left] <= pivot)
		{
			left++;
		}
		if (left < right)
		{
			array[right] = array[left];
		}
		if (left >= right)
		{
			array[left] = pivot;
		}
	}
	QuickSort(array, L, right - 1);
	QuickSort(array, left + 1, R);
}
=======================*/