/*
 * @file: File name
 * @description: Briefly describe the file
 * @author: WAHAHA
 * @Date: 2024-04-30 13:11:49
 * @LastEditTime: 2024-04-30 13:11:54
 * @FilePath: \cpp\¿˝Ã‚\≈≈–Ú\∆Ê≈º≈≈–Ú.c
 * @category: File category
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int arr[20];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 20; ++i)
		arr[i] = rand() % 100;
	int issorted = 0;
	int n = 20;
	while (!issorted) {
		issorted = 1;
		for (int i = 0;i < n - 2;i++) {
			if (arr[i] > arr[i + 1]) {
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				issorted = 0;
			}
		}
		for (int i = 1;i < n - 1;i++) {
			if (arr[i] > arr[i + 1]) {
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				issorted = 0;
			}
		}
	}
	for(int i = 0; i < 20; ++i)
		printf("%d ", arr[i]);

	return 0;
}