//
// Created by WAHAHA on 2023/9/27.
//
#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"

// make,init and destroy
SqListPtr make_sqlist(void) {
    SqListPtr new_list = NULL;
    new_list = (SqListPtr) malloc(sizeof(SqList));
    if (NULL == new_list) {
        printf("error in malloc!new_list malloc failed!\n");
        exit(-1);
    }
    new_list->list_len = 0;
    new_list->cur_max_len = INITIAL_LEN;
    new_list->list = (ElementType *) malloc(sizeof(ElementType) * INITIAL_LEN);
    if (NULL == new_list->list) {
        printf("error in malloc!new_list->list malloc failed!\n");
        exit(-1);
    }
    return new_list;
}

bool init_by_arr(SqListPtr L, ElementType *src, int size) {
    if (NULL == L) {
        printf("error in init_sqlist()! the pointer of sqlist is NULL!\n");
        return false;
    }
    bool status;
    for (int i = 0; i < size; ++i) {
        status = push_back(L, src[i]);
        if (status == false)
            return false;
    }
    return true;
}

bool init_by_value(SqListPtr L, ElementType e, int size) {
    if (NULL == L) {
        printf("error in init_sqlist()! the pointer of sqlist is NULL!\n");
        return false;
    }
    bool status;
    for (int i = 0; i < size; ++i) {
        status = push_back(L, e);
        if (status == false)
            return false;
    }
    return true;
}

bool inc_sqlist(SqListPtr L) {
    L->list = (ElementType *) realloc(L->list, sizeof(ElementType) *
                                               (L->cur_max_len + INC_LEN));
    if (NULL == L->list) {
        printf("error in inc_sqlist()!realloc failed!\n");
        return false;
    }
    L->cur_max_len += INC_LEN;
    return true;
}

bool destroy_sqlist(SqListPtr L) {
    free(L->list);
    free(L);
    return true;
}

// check status
bool is_full(SqListPtr L) {
    return L->cur_max_len == L->list_len;
}

bool is_empty(SqListPtr L) {
    return L->list_len == 0;
}

int locate_data(SqListPtr L, ElementType e) {
    for (int i = 0; i < L->list_len; ++i) {
        if (L->list[i] == e)
            return i;
    }
    return -1;
}

// operations

bool push_back(SqListPtr L, ElementType e) {
    if (is_full(L)) {
        inc_sqlist(L);
    }
    L->list[L->list_len++] = e;
    return true;
}

bool insert_at(SqListPtr L, int i, ElementType e) {
    if (is_full(L)) {
        inc_sqlist(L);
    }
    if (i > L->list_len) {
        printf("The inserted index is invalid!\n");
        return false;
    }
    for (int round = L->list_len; round > i; --round) {
        L->list[round] = L->list[round - 1];
    }
    L->list[i] = e;
    ++L->list_len;
    return true;
}

bool insert_to_sorted(SqListPtr L, ElementType e,
                      int (*compare)(ElementType, ElementType)) {
    if (is_full(L)) {
        inc_sqlist(L);
    }
    int i;
    for (i = 0; i < L->list_len; ++i) {
        if (compare(L->list[i], e) > 0) {
            break;
        }
    }
    return insert_at(L, i, e);
}

bool insert_after_value(SqListPtr L, ElementType key, ElementType e){
    int i = locate_data(L,key);
    if(i == -1){
        printf("error in insert_after_value()!key not found!\n");
        return false;
    }
    return insert_at(L,i+1,e);
}

bool delete_at(SqListPtr L, int i) {
    if (is_empty(L)) {
        printf("error in delete_at()!sqlist is empty!\n");
        return false;
    }
    if (i >= L->list_len) {
        printf("The deleted index is invalid!\n");
        return false;
    }
    for (int round = i; round < L->list_len - 1; ++round) {
        L->list[round] = L->list[round + 1];
    }
    --L->list_len;
    return true;
}

bool sort_by(SqListPtr L, int (*compare)(ElementType, ElementType)) {
    if (is_empty(L)) {
        printf("error in sort_by()!sqlist is empty!\n");
        return false;
    }
    for (int i = 0; i < L->list_len - 1; ++i) {
        for (int j = 0; j < L->list_len - i - 1; ++j) {
            if (compare(L->list[j], L->list[j + 1]) > 0) {
                ElementType temp = L->list[j];
                L->list[j] = L->list[j + 1];
                L->list[j + 1] = temp;
            }
        }
    }
    return true;
}

// I/O operations
bool print_sqlist(SqListPtr L) {
    for (int i = 0; i < L->list_len; ++i) {
        printf("%d ", L->list[i]);
    }
}

ElementType get_value_at(SqListPtr L, int i) {
    return L->list[i];
}