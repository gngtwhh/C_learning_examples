//
// Created by WAHAHA on 2023/10/11.
//

#ifndef ADT_LINKEDSTACK_LINKEDSTACK_H
#define ADT_LINKEDSTACK_LINKEDSTACK_H

#define bool int
#define true 1
#define false 0

#define BASE_PTR NULL
/*
#define STATUS_OK 1
#define STATUS_ERROR 0
*/

typedef int StackElementType;

typedef struct STACK_NODE {
    StackElementType value;
    struct STACK_NODE *next;
} StackNode;

typedef struct {
    int stack_height;
    StackNode *top;
    StackNode *base;
} Stack,*StackPtr;

// make and destroy
StackPtr make_stack(void);
bool destroy_stack(StackPtr S);

// check status
bool is_empty_stack(StackPtr S);
int stack_height(StackPtr S);

// operations
bool push_stack(StackPtr S, StackElementType e);
bool pop_stack(StackPtr S, StackElementType *e); // 如果第二个参数为NULL，则不返回栈顶元素
StackElementType top_stack(StackPtr S); // 复制返回栈顶元素
bool clear_stack(StackPtr S);


#endif //ADT_LINKEDSTACK_LINKEDSTACK_H
