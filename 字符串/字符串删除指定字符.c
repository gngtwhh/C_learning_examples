#include <stdio.h>
#include <string.h>
int main() {
	char str[100], c;
	int len;
	scanf("%s", str);
	getchar();
	scanf("%c", &c);
	len = strlen(str);
	for(int i=0;i<len;++i){
		if(str[i]!=c)
			continue;
		for(int j=i;j<len;++j)
			str[j]=str[j+1];
		len--;
		i--;
	}
	printf("%s",str);
	return 0;
}