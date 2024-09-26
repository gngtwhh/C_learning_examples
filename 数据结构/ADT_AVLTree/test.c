//
// Created by WAHAHA on 2023/12/10.
//

#include <stdio.h>
#include "AVLTree.h"

int main() {
    int nums[] = {5, 3, 6, 2, 4, 0, 8, 1, 7, 9};
    AVLTree *tree = AVLTreeCreate();
    for (int i = 0; i < 10; ++i) {
        AVLTreeInsert(tree, nums[i]);
    }
    printf("size: %d\n", AVLTreeGetSize(tree));
    while (!AVLTreeIsEmpty(tree)) {
        ElementType result;
        AVLTreeGetMin(tree, &result);
        printf("%d ", result);
        AVLTreeDelete(tree, result);
    }
    printf("\n");
    AVLTreeDestroy(tree);
    return 0;
}
