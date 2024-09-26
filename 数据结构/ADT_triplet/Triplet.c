#include <stdio.h>
#include <stdlib.h>
#include "Triplet.h"

/*
typedef int Elemtype;
typedef struct Triplet {
    Elemtype *data;
} Triplet;
 */
//创建3元组
Triplet make_triplet(void) {
    Triplet temp;
    temp.data = (Elemtype *) malloc(sizeof(Elemtype) * 3);
    if (NULL == temp.data) {
        printf("Error in malloc!");
        exit(-1);
    }
    return temp;
}

//销毁3元组
int destory_triplet(Triplet *trip) {
    free(trip->data);
    return 1;
}

//输出3元组
void print_triplet(const Triplet *trip) {
    //根据Elemtype的不同要进行修改
    printf("first: %d,second: %d,third: %d", trip->data[0], trip->data[1], trip->data[2]);
}

//存入3元组
int init_triplet(Triplet *trip, Elemtype a, Elemtype b, Elemtype c) {
    trip->data[0] = a;
    trip->data[1] = b;
    trip->data[2] = c;
    return 1;
}

//取最大值
Elemtype get_max_element(const Triplet *trip) {
    Elemtype max_element = trip->data[0];
    max_element = max_element > (trip->data[1]) ? max_element : trip->data[1];
    return (max_element > (trip->data[2]) ? max_element : trip->data[2]);
}

//取最小值
Elemtype get_min_element(const Triplet *trip) {
    Elemtype min_element = trip->data[0];
    min_element = min_element < (trip->data[1]) ? min_element : trip->data[1];
    return (min_element < (trip->data[2]) ? min_element : trip->data[2]);
}

//组内排序
int sort_by_triplet(Triplet *trip, int (*cmp)(void *a, void *b)) {
    Elemtype temp;
    if (cmp(&(trip->data[0]), &(trip->data[1])) < 0) {
        temp = trip->data[0];
        trip->data[0] = trip->data[1];
        trip->data[1] = temp;
    }
    if (cmp(&(trip->data[0]), &(trip->data[2])) < 0) {
        temp = trip->data[0];
        trip->data[0] = trip->data[2];
        trip->data[2] = temp;
    }
    if (cmp(&(trip->data[1]), &(trip->data[2])) < 0) {
        temp = trip->data[1];
        trip->data[1] = trip->data[2];
        trip->data[2] = temp;
    }
    return 1;
}