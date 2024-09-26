#include <stdio.h>
#include <stdarg.h>
void printParams(int paramNum,...) {
	va_list args;
	va_start(args, paramNum);
	for (int i = 1; i <= paramNum; ++i) {
		printf("第%d个参数: %d\n",i, va_arg(args,int));
	}
}
int main() {
	printParams(4, 2, 3, 4, 5);
	return 0;
}