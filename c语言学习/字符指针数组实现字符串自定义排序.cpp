/*用指向指针的指针数组方法对10个英文单词排序，
每个单词的大小由该单词中最后一个字母决定，
最后一个字母相同则由倒是第二个字母决定，依次类推。
例如apple>banana，因为e > a，apple<blue，因为l < u*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void bubble_sort(const char* a[], int);
int cmp(const char*, const char*);
//void bubble_sort(const char**a, int len)
void bubble_sort(const char* a[], int len)
{
	const char* temp;
	for (int i = len-1; i > 0; --i)
		for (int j = 0; j < i; ++j)
		{
			if (cmp(a[j], a[j + 1]))
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
}
int cmp(const char* str1, const char* str2)
{
	int len1 = strlen(str1)-1, len2 = strlen(str2)-1;
	while (len1 >= 0 && len2 >= 0)
	{
		if (str1[len1] > str2[len2])
			return 1;
		else if (str1[len1] < str2[len2])
			return 0;
		--len1;
		--len2;
	}
	if (len1 >= 0) return 1;
	return 0;
}
int main()
{
	const char* a[10] = { "apple","pear","peach","apricot",
		"grape","cherry","plum","strawberry","date","watermelon" };
	bubble_sort(a, 10);
	for (int i = 0; i < 10; ++i)
		printf("%s ", a[i]);
	return 0;
}