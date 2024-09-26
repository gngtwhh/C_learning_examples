//
// Created by WAHAHA on 2023/10/30.
//

#ifndef ADT_BINARYTREE_BINARYTREE_H
#define ADT_BINARYTREE_BINARYTREE_H

#define bool int
#define true 1
#define false 0

typedef char TreeElementType;
typedef struct TreeNode{
    TreeElementType value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct BTree{
    TreeNode *root;
    // int height;
    int size;
} BTree, *BTreePtr;

// make,init and destroy
void link_tree(TreeNode*root, TreeElementType *level_order, int length, int index);
BTreePtr create_tree(void);
bool init_tree_levelorder(BTreePtr T, TreeElementType *level_order, int length);
bool destroy_tree(BTreePtr T);
bool destroy_tree_recursive(TreeNode *root);

// check status
bool is_empty_tree(BTreePtr T);
// int tree_height(BTreePtr T);
int tree_size(BTreePtr T);

// operations
void invert_tree(BTreePtr T);
void print_tree_levelorder(BTreePtr T);

#endif //ADT_BINARYTREE_BINARYTREE_H
