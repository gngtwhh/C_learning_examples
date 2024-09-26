//
// Created by WAHAHA on 2023/10/11.
//
#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

int main() {
    printf("make_stack\n");
    StackPtr stack = make_stack();
    int num[4] = {
            8, 9, 5, 4
    };
    printf("pushing [8,9,5,4] into stack\n");
    for (int i = 0; i < 4; ++i) {
        push_stack(stack, num[i]);
    }
    printf("current len of stack is %d\n", stack_height(stack));
    StackElementType top_num;
    pop_stack(stack, &top_num);
    printf("pop_stack:%d\n", top_num);
    pop_stack(stack, &top_num);
    printf("pop_stack:%d\n", top_num);
    pop_stack(stack, &top_num);
    printf("pop_stack:%d\n", top_num);

    printf("is_empty_stack:%d\n", is_empty_stack(stack));
    printf("destroy_stack\n");
    destroy_stack(stack);
    return 0;
}