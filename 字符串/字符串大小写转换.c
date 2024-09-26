#include <stdio.h>
#include <string.h>
int main() {
	char str[100];
	int len, i, m;
	scanf("%s", str);
	len = strlen(str);
	printf("to upper(1)/to lower(2)? ");
	scanf("%d", &m);
	if (m == 1) {
		for (i = 0; i < len; ++i)
			if (str[i] >= 'a'&str[i] <= 'z')
				str[i] = str[i] - 'a' + 'A';
	} else if (m == 2) {
		for (i = 0; i < len; ++i)
			if (str[i] >= 'A'&str[i] <= 'Z')
				str[i] = str[i] - 'A' + 'a';
	} else {
		printf("error!");
		return 0;
	}
	printf("%s", str);
	return 0;
}