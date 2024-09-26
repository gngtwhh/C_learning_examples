//
// Created by WAHAHA on 2023/10/15.
//

#include "SqStack.h"
#include <stdio.h>
#include <stdlib.h>

// make and destroy
SqStackPtr make_stack(void) {
    SqStackPtr new_stack = NULL;
    new_stack = (SqStackPtr) malloc(sizeof(SqStack));
    if (NULL == new_stack) {
        printf("error in malloc!new_stack malloc failed!\n");
        exit(-1);
    }
    new_stack->top = -1;
    return new_stack;
}

bool destroy_stack(SqStackPtr S) {
    if (NULL == S) {
        printf("error in destroy_stack()!the stack is NULL!\n");
        return false;
    }
    free(S);
    S = NULL;
    return true;
}

// check status
bool is_empty_stack(SqStackPtr S) {
    return S->top == -1 ? true : false;
}

int stack_height(SqStackPtr S) {
    return S->top + 1;
}

int is_full_stack(SqStackPtr S) {
    return S->top == STACK_SIZE - 1 ? true : false;
}

// operations
bool push_stack(SqStackPtr S, StackElemType e) {
    if (is_full_stack(S)) {
        printf("error in push_stack()!the stack is full!\n");
        return false;
    }
    S->data[++S->top] = e;
    return true;
}

bool pop_stack(SqStackPtr S, StackElemType *e) {
    if (is_empty_stack(S)) {
        printf("error in pop_stack()!the stack is empty!\n");
        return false;
    }
    if (NULL == e) {
        S->top--;
        return true;
    }
    *e = S->data[S->top--];
    return true;
}

StackElemType top_stack(SqStackPtr S) {
    if (is_empty_stack(S)) {
        printf("error in top_stack()!the stack is empty!\n");
        return false;
    }
    return S->data[S->top];
}

bool clear_stack(SqStackPtr S) {
    S->top = -1;
    return true;
}