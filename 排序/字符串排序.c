#include <stdio.h>
#include <string.h>
void bubble_sort(char strs[][100], int n) {
	char temp[100];
	for (int i = 0; i < n - 1; ++i)
		for (int j = 0; j < n - i - 1; ++j) {
			if (strcmp(strs[j], strs[j + 1]) > 0) {
				strcpy(temp, strs[j]);
				strcpy(strs[j], strs[j + 1]);
				strcpy(strs[j + 1], temp);
			}
		}
}
int main() {
	char strs[100][100];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%s", strs[i]);
	bubble_sort(strs, n);
	for (int i = 0; i < n; ++i)
		printf("%s\n", strs[i]);
	return 0;
}