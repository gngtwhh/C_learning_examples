//
// Created by WAHAHA on 2023/9/27.
//
#include <stdio.h>
#include "SqList.h"

int my_compare(ElementType a, ElementType b) {
    return a - b; // 升序
}

int main() {
    /*
    （1）	建立4个元素的顺序表SqList={2，3，4，5}，实现顺序表的基本操作；
    （2）	在SqList={2,3,4,5}的元素4与5之间插入一个元素9，实现顺序表插入的基本操作；
    （3）	在SqList={2,3,4,9,5}中删除指定位置(i=3)上的元素，实现顺序表删除的操作
     */
    SqListPtr L = make_sqlist();
    int arr[] = {2, 3, 4, 5};

    printf("init sqlist with {2,3,4,5}:\n");
    init_by_arr(L, arr, sizeof(arr) / sizeof(arr[0]));
    print_sqlist(L);
    putchar('\n');

    printf("4,5之间插入9:\n");
    insert_after_value(L, 4, 9);
    print_sqlist(L);
    putchar('\n');

    printf("删除下标为3的元素:\n");
    delete_at(L, 3);
    print_sqlist(L);
    putchar('\n');

    destroy_sqlist(L);

    return 0;
}
