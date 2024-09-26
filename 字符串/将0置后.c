//输入
//4
//1 2 0 4
//
//输出
//1240
#include <stdio.h>
void reverse(int *left, int n) {
	int* right = left + n - 1, * now = left, *move = left + 1;
	int temp;
	while (move <= right) {
		if (!*now) {
			if (!*move)
				move++;
			else {
				*now = *move;
				*move = 0;
				now++;
				move++;
			}
		} else {
			now++;
			move++;
		}
	}
}
int main() {
	int a[100], n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	reverse(a, n);
	for (int i = 0; i < n; ++i)
		printf("%d", a[i]);
	return 0;
}
