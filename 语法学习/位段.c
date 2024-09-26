#include <stdio.h>
#include <string.h>
struct FOO {
	//第一个字节
	unsigned int a0: 5;
	unsigned int b0: 3;
	//第二个字节
	unsigned int a1: 5;
	unsigned int b1: 3;
	//第三个字节
	unsigned int a2: 5;
	unsigned int b2: 3;
	//第四个字节前5位
	unsigned int a3: 5;

	//试验这行加上与否的区别
	//unsigned int : 0;
	
	//一个位的a4
	unsigned int a4: 1;

	int i;
};
int main() {
	printf("%zu", sizeof(struct FOO));
	return 0;
}