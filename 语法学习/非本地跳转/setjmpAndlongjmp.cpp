#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

void handle_exception() {
	printf("Caught exception\n");
}

void foo() {
	int x = 0;
	if (setjmp(buf) != 0) {
		handle_exception();
		return;
	}

	printf("Enter a number: ");
	scanf("%d", &x);

	if (x < 0) {
		longjmp(buf, 1);
	}

	printf("The number is %d\n", x);
}

int main() {
	foo();
	return 0;
}
