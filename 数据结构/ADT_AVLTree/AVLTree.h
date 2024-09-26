//
// Created by WAHAHA on 2023/12/9.
//

#ifndef ADT_AVLTREE_AVLTREE_H
#define ADT_AVLTREE_AVLTREE_H

#define true 1
#define false 0
#define error -1
#define status int

typedef int ElementType;
typedef struct AVLNode {
    ElementType data;
    int height;
    struct AVLNode *left;
    struct AVLNode *right;
} AVLNode;

typedef struct {
    AVLNode *root;
    // int (*compare)(ElementType*, ElementType*); // 需要注册的比较函数
    int size;
} AVLTree;

// default compare function
// int defaultCompare(ElementType *a, ElementType *b);

// create and destroy
// AVLTree *AVLTreeCreate(int (*compare)(ElementType*, ElementType*));
AVLTree *AVLTreeCreate(void);
void AVLTreeDestroy(AVLTree *tree);
void AVLTreeDestroyRun(AVLNode *node);

// insert and delete
status AVLTreeInsert(AVLTree *tree, ElementType data);
status AVLTreeInsertRun(AVLNode **root, ElementType data);
status AVLTreeDelete(AVLTree *tree, ElementType data);
status AVLTreeDeleteRun(AVLNode **root, ElementType data);

// search
status AVLTreeSearch(AVLTree *tree, ElementType data);

// get max and min
status AVLTreeGetMax(AVLTree *tree, ElementType *result);
status AVLTreeGetMin(AVLTree *tree, ElementType *result);

// get status
int AVLTreeGetHeight(AVLTree *tree);
int GetNodeHeight(AVLNode *node);
int AVLTreeGetSize(AVLTree *tree);
status AVLTreeIsEmpty(AVLTree *tree);
ElementType GetNodeMin(AVLNode *node);
ElementType GetNodeMax(AVLNode *node);

// rotate
void LeftRotation(AVLNode **node);
void RightRotation(AVLNode **node);

// private functions
int max(int a, int b);

#endif //ADT_AVLTREE_AVLTREE_H
