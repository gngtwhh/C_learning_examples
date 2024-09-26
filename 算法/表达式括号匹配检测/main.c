#include <stdio.h>
#include <string.h>
#include "SqStack.h"


void BracketMatching() {
    char expression[100];
    int length = 0;
    SqStackPtr bracket = make_stack();
    int flag = 0;
    // 换行结束
    printf("please input the expression(end with enter):\n");
    scanf("%s", expression);
    length = strlen(expression);
    for (int i = 0; i < length; ++i) {
        if (expression[i] == '(') {
            push_stack(bracket, expression[i]);
        } else if (expression[i] == ')') {
            if (is_empty_stack(bracket)) {
                flag = 2;
                break;
            }
            pop_stack(bracket, NULL);
        }
    }
    if (!is_empty_stack(bracket)) {
        flag = 1;
    }
    if (!flag) {
        printf("the expression is matched!\n");
    } else if(flag == 1){
        printf("the expression is not matched!\n");
        printf("the left bracket '(' is more than the right bracket!\n");
    }else{
        printf("the expression is not matched!\n");
        printf("the right bracket ')' is more than the left bracket!\n");
    }
    destroy_stack(bracket);
}

int main() {
    BracketMatching();
    return 0;
}
