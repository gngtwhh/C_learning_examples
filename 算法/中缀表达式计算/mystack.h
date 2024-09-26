/*
**一个堆栈模块的接口
 */
#include <stdlib.h>
#define STACK_TYPE int/*堆栈所存储的值的类型*/
typedef struct STACK_NODE stack_node;
/*
push
把一个新值压入到堆栈中,参数为需要被压入的值
 */
void push(stack_node** stack,STACK_TYPE value);

/*
pop
从堆栈弹出一个值并丢弃
 */
void pop(stack_node** stack);

/*
top
返回堆栈顶部元素,但不对堆栈进行修改
 */
STACK_TYPE top(stack_node** stack);

/*
如果堆栈为空,返回TRUE,否则返回FALSE
 */
int is_empty(stack_node** stack);

/*
如果堆栈已满,返回TRUE,否则返回FALSE
 */
int is_full(stack_node** stack);


