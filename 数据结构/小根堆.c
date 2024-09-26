#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000
int heap[MAXN], size;//用realloc改写成动态?
void swap(int a, int b)
{
	int temp;
	temp = heap[a];
	heap[a] = heap[b];
	heap[b] = temp;
}
void insert(int num)
{
	heap[++size] = num;
	int pos = size;
	while (pos != 1) {
		if (heap[pos >> 1] > heap[pos]) {//小根堆
			swap(pos >> 1, pos);
			pos >>= 1;
		}
		else break;
	}
}
void initHeap()
{
	int n, m;
	printf("元素个数:");
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &m);
		insert(m);
	}
}
void pop()
{
	heap[1] = heap[size--];
	int temp = 1, pos = 1;
	while (1) {
		int l = pos << 1;
		int r = (pos << 1) + 1;
		/*if (r<=size&&heap[pos] > heap[l] && heap[l] < heap[r])
			temp = l;
		else if(r<=size&&heap[pos]>heap[r])*/
		if (l <= size) {
			if (r <= size && heap[pos] > heap[l] && heap[l] > heap[r])
				temp = r;
			else if (heap[pos] > heap[l])
				temp = l;
		}
		if (pos != temp) {
			swap(pos, temp);
			pos = temp;
		}
		else break;
	}
}
void printHeap()
{
	while (size > 0) {
		printf("%d ", heap[1]);
		pop();
	}
}
int main()
{
	initHeap();
	printHeap();
	return 0;
}