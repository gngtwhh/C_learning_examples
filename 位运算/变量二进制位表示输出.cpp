#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int bitNum;
	short shortVar=-1;
	char charVar='a';
	int intVar=123;
	char bitStr[40];
	memset(bitStr, 0, sizeof(bitStr));
	bitNum = sizeof(short) * 8;
	for (int i = 0; i < bitNum; ++i) {
		bitStr[i] = (shortVar & 1)+'0';
		shortVar >>= 1;
	}
	for (int i = bitNum; i>=0; --i) {
		printf("%c", bitStr[i]);
	}
	return 0;
}


#if 0
//改进---未实现
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void bitPrint(char *bitStr,void*var,int bitNum) {
	memset(bitStr, 0, sizeof(bitStr));
	for (int i = 0; i < bitNum; ++i) {
		bitStr[i] = (var & 1) + '0';
		shortVar >>= 1;
	}
	for (int i = bitNum; i >= 0; --i) {
		printf("%c", bitStr[i]);
	}
}
int main()
{
	int bitNum;
	short shortVar=-1;
	char charVar='a';
	int intVar=123;
	char bitStr[40];
	bitNum = sizeof(short) * 8;
	bitPrint(bitStr, &, bitNum);
	memset(bitStr, 0, sizeof(bitStr));
	for (int i = 0; i < bitNum; ++i) {
		bitStr[i] = (shortVar & 1)+'0';
		shortVar >>= 1;
	}
	for (int i = bitNum; i>=0; --i) {
		printf("%c", bitStr[i]);
	}
	return 0;
}
#endif
