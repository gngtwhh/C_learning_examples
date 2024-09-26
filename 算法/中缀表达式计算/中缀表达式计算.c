/*
 * 功能:
 *     利用栈实现中缀表达式向后缀表达式的转换;
 *     利用栈实现后缀表达式的计算;
 */
#include <stdio.h>
#include "mystack.h"

#define MAX_EXPRESSION_LEN 100
stack_node *operator_s = NULL;//运算符栈
stack_node *operand_s = NULL;//操作数栈

char infix[MAX_EXPRESSION_LEN];
char postfix[MAX_EXPRESSION_LEN];
int infix_idx = 0, postfix_idx = 0;
int ans = 0;

int is_higher_then(int a, int b) {
    if ((a == '(') && (b == '+' || b == '-' || b == '*' || b == '/'))
        return 1;
    else if ((a == '*' || a == '/') && (b == '+' || b == '-'))
        return 1;
    return 0;
}

void infix_to_postfix() {
    while (infix[infix_idx] != '\0') {
        if (infix[infix_idx] >= '0' && infix[infix_idx] <= '9') {
//            postfix[postfix_idx++] = infix[infix_idx];
            while (infix[infix_idx] >= '0' && infix[infix_idx] <= '9')
                postfix[postfix_idx++] = infix[infix_idx++];
            postfix[postfix_idx++] = ' ';
            --infix_idx;
        } else if (infix[infix_idx] == ')') {
            while (top(&operator_s) != '(') {
                postfix[postfix_idx++] = top(&operator_s);
                pop(&operator_s);
            }
            pop(&operator_s);
        } else {
            if (is_empty(&operator_s)) {
                push(&operator_s, infix[infix_idx]);
            } else if (is_higher_then(infix[infix_idx], top(&operator_s))) {
                push(&operator_s, infix[infix_idx]);
            } else {
                while (!is_empty(&operator_s) && !is_higher_then(infix[infix_idx], top(&operator_s))) {
                    if (top(&operator_s) != '(') {
                        postfix[postfix_idx++] = top(&operator_s);
                        pop(&operator_s);
                    } else break;
                }
                push(&operator_s, infix[infix_idx]);
            }
        }
        ++infix_idx;
    }

    while (!is_empty(&operator_s)) {
        postfix[postfix_idx++] = top(&operator_s);
        pop(&operator_s);
    }
    postfix[postfix_idx] = '\0';

}

int calculate_step(int a, int b, char operate) {
    switch (operate) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            return 0;
    }
}

void calculate_postfix() {
    postfix_idx = 0;
    int temp = 0;
    char c;
    while (postfix[postfix_idx] != '\0') {
        if(postfix[postfix_idx]==' ')
            ++postfix_idx;
        else if (postfix[postfix_idx] >= '0' && postfix[postfix_idx] <= '9') {
            while (postfix[postfix_idx] >= '0' && postfix[postfix_idx] <= '9')
                temp = temp * 10 + postfix[postfix_idx++] - '0';
            push(&operand_s, temp);
        } else {
            int b = top(&operand_s);
            pop(&operand_s);
            int a = top(&operand_s);
            pop(&operand_s);
            temp = calculate_step(a, b, postfix[postfix_idx]);
            push(&operand_s, temp);
            ++postfix_idx;
        }
        temp = 0;
    }
    ans = top(&operand_s);
    pop(&operand_s);
}

int main() {
    printf("输入中缀表达式:\n");
    scanf("%s", infix);

    infix_to_postfix();
    printf("转换为后缀表达式:\n");
    printf("%s\n", postfix);

    calculate_postfix();
    printf("运算结果为:\n");
    printf("%d", ans);
    getchar();
    getchar();
    return 0;
}