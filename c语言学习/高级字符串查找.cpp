#include <stdio.h>
#include <string.h>
int main() {
	char s[] = "1,2,3,4,haha,hoho";
	
	//查找字符串前缀
	char keys[] = "0123456789";
	char keys2[] = "0123456789,";
	printf("%d\n",strspn(s,keys));
	printf("%d\n\n",strspn(s,keys2));
	//查找标记
	//该函数见资料
	char s2[] = "1,2,3,4|haha|hoho";
	char sep[]=",|";
	char *p;
	for(p=strtok(s2,sep);p!=NULL;p=strtok(NULL,sep)){
		printf("%s\n",p);
	}
	//s2中的分隔符被替换为'\0' (?)
	return 0;
}