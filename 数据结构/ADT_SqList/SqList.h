//
// Created by WAHAHA on 2023/9/27.
//

#ifndef ADT_SQLIST_SQLIST_H
#define ADT_SQLIST_SQLIST_H

#define INITIAL_LEN 10
#define INC_LEN 10
#define bool int
#define true 1
#define false 0

typedef int ElementType;
typedef struct {
    int cur_max_len;
    int list_len;
    ElementType *list;
}SqList, *SqListPtr;


// make,init and destroy
SqListPtr make_sqlist(void);
bool init_by_arr(SqListPtr L, ElementType *src, int size);
bool init_by_value(SqListPtr L, ElementType e, int size);
bool inc_sqlist(SqListPtr L);
bool destroy_sqlist(SqListPtr L);

// check status
bool is_full(SqListPtr L);
bool is_empty(SqListPtr L);
int locate_data(SqListPtr L, ElementType e);

// operations
bool push_back(SqListPtr L, ElementType e);
bool insert_at(SqListPtr L, int i, ElementType e);
bool insert_to_sorted(SqListPtr L, ElementType e,
                      int (*compare)(ElementType, ElementType));
bool insert_after_value(SqListPtr L, ElementType key, ElementType e);
bool delete_at(SqListPtr L, int i);
bool sort_by(SqListPtr L, int (*compare)(ElementType, ElementType));

// I/O operations
bool print_sqlist(SqListPtr L);
ElementType get_value_at(SqListPtr L, int i);

#endif //ADT_SQLIST_SQLIST_H
