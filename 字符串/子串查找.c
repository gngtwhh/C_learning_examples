#include <stdio.h>
#include <string.h>
int main() {
	char str[100], p[100];
	int slen, plen, i, j, flag = 1, cnt = 0;
	scanf("%s%s", str, p);
	slen = strlen(str);
	plen = strlen(p);

	for (i = 0; i < slen; ++i) {
		for (j = 0; j < plen && str[j] != '\0'; ++j) {
			if (str[i + j] != p[j]) {
				flag = 0;
				break;
			}
		}
		if (flag)
			cnt++;
		else
			flag = 1;
	}
	printf("%d", cnt);
	return 0;
}