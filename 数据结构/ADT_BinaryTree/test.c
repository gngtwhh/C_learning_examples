//
// Created by WAHAHA on 2023/10/31.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinaryTree.h"

int main() {
    BTreePtr tree = create_tree();
    char level_order[] = "ABC##DE######F#";
    init_tree_levelorder(tree, level_order, strlen(level_order));
    invert_tree(tree);
    print_tree_levelorder(tree);
    destroy_tree(tree);
    return 0;
}