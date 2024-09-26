#include <stdio.h>
int main() {
	unsigned long long ans=1;
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
			ans*=i;
		printf("%llu",ans);
    return 0;
}