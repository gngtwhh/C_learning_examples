#include <stdio.h>
#include <string.h>
int main(){
	/*
	void* memcpy(void *dst,void const*src,size_t length);
		从src的起始位置开始赋值length个字节到dst的起始位置
		整数数组的话可以length可以换为sizeof(values)(?)
		dst和src不能重叠
	void* memmove(void *dst,void const*src,size_t length);
		dst和src可以重叠
	void* memcmp(void const *a,void const *b,size_t length);
		内存比较(返回的结果和strcmp一样---非单字节的结果不可预料(未定义?))
	void* memchr(void const *a,int ch,size_t length);
		从a的起始位置开始查找ch
	void* memset(void *a,int ch,size_t length);
	*/
	/*
	length表示1需要处理的字节数---遇到NUL不会停止
	 */
	return 0;
}