#include <stdio.h>
int main( ) {
    int a[11] = {1, 4, 6, 9, 13, 16, 19, 28, 40, 100};
    int temp1, temp2, number, end, i, j;
    for (i = 0; i < 10; i++)
        printf("%d ", a[i]);
    printf("\n");
    scanf("%d", &number);
    if (number > a[9])
        a[10] = number;
    else {
        for (i = 9; i >= 0; i--) {
            if (a[i] > number)
                a[i + 1] = a[i];
            else
                break;
        }
        a[i + 1] = number;
    }
    for (i = 0; i < 11; i++)
        printf("%d ", a[i]);
}
