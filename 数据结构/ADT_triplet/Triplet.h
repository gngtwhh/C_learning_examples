//
// Created by admin on 2023/9/20.
//

#ifndef ADT_TRIPLET_TRIPLET_H
#define ADT_TRIPLET_TRIPLET_H

typedef int Elemtype;
typedef struct Triplet {
    Elemtype *data;
} Triplet;

//创建3元组
Triplet make_triplet(void);
//销毁3元组
int destory_triplet(Triplet *trip);
//输出3元组
void print_triplet(const Triplet *trip);
//存入3元组
int init_triplet(Triplet *trip, Elemtype a, Elemtype b, Elemtype c);
//取最大值
Elemtype get_max_element(const Triplet *trip);
//取最小值
Elemtype get_min_element(const Triplet *trip);
//组内排序
int sort_by_triplet(Triplet *trip, int (*cmp)(void *a, void *b));

#endif //ADT_TRIPLET_TRIPLET_H
