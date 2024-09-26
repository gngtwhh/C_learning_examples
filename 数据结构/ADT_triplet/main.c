#include <stdio.h>
#include "Triplet.h"

/*
typedef int Elemtype;
typedef struct Triplet {
    Elemtype *data;
} Triplet;
 */

int ascending_cmp(void *a, void *b) {
    //升序
    return *(Elemtype *) b - *(Elemtype *) a;
}

int main() {
    Triplet t1 = make_triplet();
    Triplet t2 = make_triplet();

    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    init_triplet(&t1, a, b, c);
    scanf("%d%d%d", &a, &b, &c);
    init_triplet(&t2, a, b, c);

    printf("testing print func:\n");
    print_triplet(&t1);
    putchar('\n');
    print_triplet(&t2);
    putchar('\n');

    printf("testing sort func:\n");
    sort_by_triplet(&t2, ascending_cmp);
    print_triplet(&t2);
    putchar('\n');

    printf("the max element in t1 is %d\n", get_max_element(&t1));
    printf("the min element in t1 is %d\n", get_min_element(&t1));

    return 0;
}
