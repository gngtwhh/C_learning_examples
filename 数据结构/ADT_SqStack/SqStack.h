//
// Created by WAHAHA on 2023/10/15.
//

#ifndef ADT_SQSTACK_SQSTACK_H
#define ADT_SQSTACK_SQSTACK_H

#define STACK_SIZE 20
#define bool int
#define true 1
#define false 0

typedef int StackElemType;
typedef struct {
    StackElemType data[STACK_SIZE];
    int top;
}SqStack,* SqStackPtr;

// make and destroy
SqStackPtr make_stack(void);
bool destroy_stack(SqStackPtr S);

// check status
bool is_empty_stack(SqStackPtr S);
int stack_height(SqStackPtr S);
int is_full_stack(SqStackPtr S);

// operations
bool push_stack(SqStackPtr S, StackElemType e);
bool pop_stack(SqStackPtr S, StackElemType *e); // 如果第二个参数为NULL，则不返回栈顶元素
StackElemType top_stack(SqStackPtr S); // 复制返回栈顶元素
bool clear_stack(SqStackPtr S);


#endif //ADT_SQSTACK_SQSTACK_H
