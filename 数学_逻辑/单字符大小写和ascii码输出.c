#include <stdio.h>
int main()
{
	char i;
	scanf("%c", &i);
	printf("%c %c %d", i, i + ('a' - 'A'), i);

	return 0;
}