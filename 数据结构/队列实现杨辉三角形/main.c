#include <stdio.h>
#include <string.h>
#include "ArrCircularQueue.h"

void YangHuiTriangle() {
    int n;
    QueuePtr triangle = make_queue();
    printf("please input the number of lines:\n");
    scanf("%d", &n);
    push_queue(triangle, 1);
    for (int i = 1; i <= n; ++i) {
        int a = 0, b;
        for (int j = 1; j <= i; ++j) {
            pop_queue(triangle, &b);
            printf("%3d ", b);
            push_queue(triangle, a + b);
            a=b;
        }
        push_queue(triangle,1);
        putchar('\n');
    }
    destroy_queue(triangle);
}

int main() {
    YangHuiTriangle();
    return 0;
}
