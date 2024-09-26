#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BSTree.h"

int main() {
    int nums[] = {5, 3, 6, 2, 4, 0, 8, 1, 7, 9};
    BTreePtr T = create_tree();
    for (int i = 0; i < 10; ++i) {
        insert(T, nums[i]);
    }
    printf("size: %d\n", tree_size(T));
    while(!is_empty_tree(T)) {
        printf("%d ", find_min(T));
        delete(T, find_min(T));
    }
    printf("\n");
    destroy_tree(T);
    return 0;
}