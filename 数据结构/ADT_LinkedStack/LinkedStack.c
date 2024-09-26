//
// Created by WAHAHA on 2023/10/11.
//

#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

// make and destroy
StackPtr make_stack(void) {
    StackPtr new_stack = NULL;
    new_stack = (StackPtr) malloc(sizeof(Stack));
    if (NULL == new_stack) {
        printf("error in malloc!new_stack malloc failed!\n");
        exit(-1);
    }
    new_stack->base = BASE_PTR;
    new_stack->top = BASE_PTR;
    new_stack->stack_height = 0;
    return new_stack;
}

bool destroy_stack(StackPtr S) {
    clear_stack(S);
    free(S);
    return true;
}

// check status
bool is_empty_stack(StackPtr S) {
    return S->stack_height == 0 ? true : false;
}

int stack_height(StackPtr S){
    return S->stack_height;
}

// operations
bool push_stack(StackPtr S, StackElementType e) {
    StackNode *new_node = NULL;
    new_node = (StackNode *) malloc(sizeof(StackNode));
    if (NULL == new_node) {
        printf("error in malloc!new_node malloc failed!\n");
        return false;
    }
    new_node->value = e;
    new_node->next = S->top;
    S->top = new_node;
    S->stack_height++;
    return true;
}

// 如果第二个参数为NULL，则不返回栈顶元素
bool pop_stack(StackPtr S, StackElementType *e) {
    if (is_empty_stack(S)) {
        printf("error in pop_stack()!the stack is empty!\n");
        return false;
    }
    StackNode *temp = S->top;
    S->top = S->top->next;
    if (NULL != e)
        *e = temp->value;
    free(temp);
    S->stack_height--;
    return true;
}

// 复制返回栈顶元素
StackElementType top_stack(StackPtr S) {
    if (is_empty_stack(S)) {
        printf("error in top_stack()!the stack is empty!\n");
        exit(-1);
    }
    return S->top->value;
}

bool clear_stack(StackPtr S) {
    while (!is_empty_stack(S)) {
        pop_stack(S, NULL);
    }
    return true;
}