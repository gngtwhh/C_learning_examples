//
// Created by WAHAHA on 2023/10/18.
//

#ifndef ADT_BIN_SEARCH_TREE_BSTREE_H
#define ADT_BIN_SEARCH_TREE_BSTREE_H

#define bool int
#define true 1
#define false 0

typedef int TreeElementType;
typedef struct TreeNode {
    TreeElementType value;
    // int height;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct {
    TreeNode *root;
    int size;
} BTree, *BTreePtr;

// create and destroy
BTreePtr create_tree(void);
void destroy_tree_run(TreeNode *node);
void destroy_tree(BTreePtr T);

// check status
bool is_empty_tree(BTreePtr T);
// int tree_height(BTreePtr T);
int tree_size(BTreePtr T);
TreeElementType find_min(BTreePtr T);
TreeElementType find_max(BTreePtr T);

// operations
bool insert(BTreePtr T, TreeElementType value);
bool delete(BTreePtr T, TreeElementType value);
// bool invert_tree(BTreePtr T);

#endif //ADT_BIN_SEARCH_TREE_BSTREE_H
