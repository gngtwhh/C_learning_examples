#include "mystack.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#define FALSE 0

/*
定义一个结构以存储堆栈元素,其中next字段将指向堆栈的下一个元素
 */
typedef struct STACK_NODE {
    STACK_TYPE value;
    struct STACK_NODE *next;

} stack_node;

/*
push
 */
void push(stack_node **stack, STACK_TYPE value) {
    stack_node *new_node;

    new_node = malloc(sizeof(stack_node));
    assert(new_node != NULL);
    new_node->next = *stack;
    new_node->value = value;
    *stack = new_node;
}

/*
pop
 */
void pop(stack_node **stack) {
    stack_node *first_node;
    first_node = *stack;
    *stack = first_node->next;
    free(first_node);
}
/*
top
 */
STACK_TYPE top(stack_node **stack) {
    return (*stack)->value;
}

/*
is_empty
 */
int is_empty(stack_node **stack) {
    return *stack == NULL;
}

/*
is_full
 */
int is_full(stack_node **stack) {
    return FALSE;
}


/*
destory_stack
 */
void destory_stack(stack_node **stack) {
    while (!is_empty(stack))
        pop(stack);
}