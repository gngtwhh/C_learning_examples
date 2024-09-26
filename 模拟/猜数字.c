#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	int n=-1,cnt = 0;
	srand((int)time(NULL));
	int m = (rand() % 100) + 1;
	while(n!=m){
		scanf("%d",&n);
		if(n<m)
			printf("too small\n");
		if(n>m)
			printf("too big\n");
		cnt++;
	}
	printf("correct!\ntotal:%d",cnt);
	return 0;
}