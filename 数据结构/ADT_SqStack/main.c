#include <stdio.h>
#include "SqStack.h"
int main() {
    int data[] = {123,321,345,567,678};
    SqStackPtr stack = make_stack();
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); ++i) {
        push_stack(stack, data[i]);
    }
    printf("stack_height:%d\n", stack_height(stack));
    StackElemType top_num;
    pop_stack(stack, &top_num);
    printf("pop_stack:%d\n", top_num);
    pop_stack(stack, &top_num);
    printf("pop_stack:%d\n", top_num);
    printf("stack_height:%d\n", stack_height(stack));
    destroy_stack(stack);
    stack = NULL;
    return 0;
}
