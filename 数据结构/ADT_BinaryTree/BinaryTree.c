//
// Created by WAHAHA on 2023/10/30.
//

#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

// make,init and destroy

void
link_tree(TreeNode *root, TreeElementType *level_order, int index, int length) {
    // length从0开始计数,这意味着对树的结点进行赋值时需要减1
    root->value = level_order[index - 1];
    if (index * 2 <= length && level_order[index * 2 - 1] != '#') {
        root->left = (TreeNode *) malloc(sizeof(TreeNode));
        link_tree(root->left, level_order, index * 2, length);
    } else
        root->left = NULL;

    if (index * 2 + 1 <= length && level_order[index * 2] != '#') {
        root->right = (TreeNode *) malloc(sizeof(TreeNode));
        link_tree(root->right, level_order, index * 2 + 1, length);
    } else
        root->right = NULL;
}

BTreePtr create_tree(void) {
    BTreePtr T = (BTreePtr) malloc(sizeof(BTree));
    if (T == NULL) {
        printf("Error: create tree failed.\n");
        return NULL;
    }
    T->root = NULL;
    // T->height = 0;
    T->size = 0;
    return T;
}

bool
init_tree_levelorder(BTreePtr T, TreeElementType *level_order, int length) {
    T->root = (TreeNode *) malloc(sizeof(TreeNode));
    link_tree(T->root, level_order, 1, length);
    // T->height = tree_height(T);
    T->size = length;
    return true;
}

bool destroy_tree(BTreePtr T) {
    TreeNode *root = T->root;
    if (root == NULL) {
        free(T);
        return true;
    }
    destroy_tree_recursive(root);
    free(T);
    return true;
}

bool destroy_tree_recursive(TreeNode *root) {
    if (root == NULL) {
        return true;
    }
    destroy_tree_recursive(root->left);
    destroy_tree_recursive(root->right);
    free(root);
    return true;
}

// check status
bool is_empty_tree(BTreePtr T) {
    return T->root == NULL;
}

// int tree_height(BTreePtr T);
int tree_size(BTreePtr T) {
    return T->size;
}

// operations
void invert_tree_run(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    invert_tree_run(root->left);
    invert_tree_run(root->right);
}

// 接口
void invert_tree(BTreePtr T) {
    invert_tree_run(T->root);
}

void print_tree_levelorder(BTreePtr T) {
    if (T->root == NULL) {
        printf("Error: tree is empty.\n");
        return;
    }
    TreeNode *root = T->root;
    TreeNode *queue[T->size];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front != rear) {
        TreeNode *temp = queue[front++];
        printf("%c ", temp->value);
        if (temp->left != NULL) {
            queue[rear++] = temp->left;
        }
        if (temp->right != NULL) {
            queue[rear++] = temp->right;
        }
    }

    /*queue[rear++] = root;
    while (front != rear) {
        TreeNode *temp = queue[front++];

        printf("%c ", temp->value);
        if (temp->left != NULL) {
            queue[rear++] = temp->left;
        }
        if (temp->right != NULL) {
            queue[rear++] = temp->right;
        }
    }
    printf("\n");*/
}