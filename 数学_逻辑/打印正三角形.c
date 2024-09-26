#include <stdio.h>
int main() {
	int i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		for(j=0;j<n-i-1;++j)
			putchar(' ');
		for(j=0;j<i*2+1;++j)
			putchar('*');
		putchar('\n');
	}
	return 0;
}