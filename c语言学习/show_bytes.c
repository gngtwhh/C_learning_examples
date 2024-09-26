#include <stdio.h>
typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, size_t len) {
	size_t i;
	for (i = 0; i < len; ++i)
		printf(" %.2x", start[i]);
}
void show_int(int x) {
	show_bytes((byte_pointer)&x, sizeof(int));
}
void show_short(int x) {
	show_bytes((byte_pointer)&x, sizeof(short));
}
void show_double(double x) {
	show_bytes((byte_pointer)&x, sizeof(double));
}
int main() {
	/*int i = 11;
	short j = 17;
	show_int(i);
	printf("\n");
	show_short(j);*/
	double i=3.14;
	show_double(i);
	return 0;
}