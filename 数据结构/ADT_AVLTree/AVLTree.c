//
// Created by WAHAHA on 2023/12/9.
//

#include "AVLTree.h"
#include <stdio.h>
#include <stdlib.h>

AVLTree *AVLTreeCreate(void) {
    AVLTree *tree = (AVLTree *) malloc(sizeof(AVLTree));
    if (tree == NULL) {
        printf("malloc failed\n");
        return NULL;
    }
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

void AVLTreeDestroyRun(AVLNode *node) {
    if (node == NULL) {
        return;
    }
    AVLTreeDestroyRun(node->left);
    AVLTreeDestroyRun(node->right);
    free(node);
}

void AVLTreeDestroy(AVLTree *tree) {
    if (tree == NULL) {
        printf("tree is NULL\n");
        return;
    }
    // recursive destroy
    AVLTreeDestroyRun(tree->root);
    free(tree);
}

// insert and delete
status AVLTreeInsert(AVLTree *tree, ElementType data) {
    if (tree == NULL) {
        printf("tree is NULL\n");
        return error;
    }
    status result = AVLTreeInsertRun(&tree->root, data);
    // check status
    if (result == true) {
        tree->size++;
        return true;
    } else if (result == false)
        return false;
    return error;
}

/*
 * insert data into AVLTree
 * return true if insertion successfully
 * return false if insertion failed
 * return error if insertion error (malloc() failed)
 */
status AVLTreeInsertRun(AVLNode **root, ElementType data) {
    /* if the tree is empty */
    if (*root == NULL) {
        *root = (AVLNode *) malloc(sizeof(AVLNode));
        if (*root == NULL) {
            printf("malloc failed\n");
            return error;
        }
        (*root)->data = data;
        (*root)->height = 1;
        (*root)->left = (*root)->right = NULL;
        return true;
    }

    /* if the data already exists */
    if ((*root)->data == data)
        return false;
    else if ((*root)->data < data) {
        /*
         * the data is larger than the current subtree root
         * insert into right subtree
         */
        status result = AVLTreeInsertRun(&(*root)->right, data);
        if (result == false)
            return false;
        else if (result == error)
            return error;

        int leftHeight = GetNodeHeight((*root)->left);
        int rightHeight = GetNodeHeight((*root)->right);
        // after insert, we need check if the tree is balanced
        // in this case, we insert into right subtree,
        // so rightHeight >= leftHeight
        if (rightHeight - leftHeight == 2) {
            if ((*root)->right->data < data) {
                // type RR
                LeftRotation(root);
            } else {
                // type RL
                RightRotation(&(*root)->right);
                LeftRotation(root);
            }
        }
    } else {
        /*
         * the data is smaller than the current subtree root
         * insert into left subtree
         */
        status result = AVLTreeInsertRun(&(*root)->left, data);
        if (result == false)
            return false;
        else if (result == error)
            return error;

        int leftHeight = GetNodeHeight((*root)->left);
        int rightHeight = GetNodeHeight((*root)->right);
        // after insert, we need check if the tree is balanced
        // in this case, we insert into left subtree,
        // so leftHeight >= rightHeight
        if (leftHeight - rightHeight == 2) {
            if ((*root)->left->data > data) {
                // type LL
                RightRotation(root);
            } else {
                // type LR
                LeftRotation(&(*root)->left);
                RightRotation(root);
            }
        }
    }
    // update height if abs(leftHeight - rightHeight) != 2
    // function RightRotation() contains the operation to update the height
    (*root)->height =
            max(GetNodeHeight((*root)->left), GetNodeHeight((*root)->right)) +
            1;
    return true;
}

status AVLTreeDelete(AVLTree *tree, ElementType data) {
    if (tree == NULL) {
        printf("tree is NULL\n");
        return error;
    }
    status result = AVLTreeDeleteRun(&tree->root, data);
    // check status
    if (result == true) {
        tree->size--;
        return true;
    } else if (result == false)
        return false;
    return error;
}

/*
 * delete data from AVLTree
 * return true if deletion successfully
 * return false if deletion failed
 * return error if deletion error (malloc() failed)
 */
status AVLTreeDeleteRun(AVLNode **root, ElementType data) {
    if (*root == NULL)
        return false;
    if ((*root)->data == data) {
        // find the node
        if ((*root)->left != NULL && (*root)->right != NULL) {
            // left and right subtree both exist

            // find the min node in right subtree and replace the node
            ElementType key = GetNodeMin((*root)->right);
            (*root)->data = key;

            // delete the min node in right subtree
            // In effect, the question is shifted to deleting the min node in right subtree
            AVLTreeDeleteRun(&(*root)->right, key);

            int leftHeight = GetNodeHeight((*root)->left);
            int rightHeight = GetNodeHeight((*root)->right);
            // after delete, we need check if the tree is balanced
            // in this case, we delete the min node in right subtree,
            // so leftHeight >= rightHeight
            if (leftHeight - rightHeight == 2) {
                // check >= , not >
                if (GetNodeHeight((*root)->left->left) >=
                    GetNodeHeight((*root)->left->right)) {
                    // type LL
                    RightRotation(root);
                } else {
                    // type LR
                    LeftRotation(&(*root)->left);
                    RightRotation(root);
                }
            }
        } else if ((*root)->left == NULL) {
            // left subtree is empty
            AVLNode *temp = *root;
            *root = (*root)->right;
            free(temp);
            temp = NULL;
            return true;
        } else {
            // right subtree is empty
            AVLNode *temp = *root;
            *root = (*root)->left;
            free(temp);
            temp = NULL;
            return true;
        }
    } else if ((*root)->data < data) {
        // find in right subtree
        status result = AVLTreeDeleteRun(&(*root)->right, data);
        if (result == false)
            return false;
        else if (result == error)
            return error;

        int leftHeight = GetNodeHeight((*root)->left);
        int rightHeight = GetNodeHeight((*root)->right);
        // after delete, we need check if the tree is balanced
        // in this case, we delete in right subtree,
        // so leftHeight >= rightHeight
        if (leftHeight - rightHeight == 2) {
            // check >= , not >
            if (GetNodeHeight((*root)->left->left) >=
                GetNodeHeight((*root)->left->right)) {
                // type LL
                RightRotation(root);
            } else {
                // type LR
                LeftRotation(&(*root)->left);
                RightRotation(root);
            }
        }
    } else {
        // find in left subtree
        status result = AVLTreeDeleteRun(&(*root)->left, data);
        if (result == false)
            return false;
        else if (result == error)
            return error;

        int leftHeight = GetNodeHeight((*root)->left);
        int rightHeight = GetNodeHeight((*root)->right);
        // after delete, we need check if the tree is balanced
        // in this case, we delete in left subtree,
        // so rightHeight >= leftHeight
        if (rightHeight - leftHeight == 2) {
            // check >= , not >
            if (GetNodeHeight((*root)->right->right) >=
                GetNodeHeight((*root)->right->left)) {
                // type RR
                LeftRotation(root);
            } else {
                // type RL
                RightRotation(&(*root)->right);
                LeftRotation(root);
            }
        }
    }

    // update height if abs(leftHeight - rightHeight) != 2 (?)
    (*root)->height =
            max(GetNodeHeight((*root)->left), GetNodeHeight((*root)->right)) +
            1;
    return true;
}

// search
status AVLTreeSearch(AVLTree *tree, ElementType data) {
    if (tree == NULL) {
        printf("tree is NULL\n");
        return error;
    }
    if (tree->root == NULL) {
        printf("tree is empty\n");
        return false;
    }
    AVLNode *node = tree->root;
    while (node != NULL) {
        if (node->data == data) {
            return true;
        } else if (node->data > data) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return false;
}

// get max or min
status AVLTreeGetMax(AVLTree *tree, ElementType *result) {
    if (tree == NULL) {
        printf("tree is NULL\n");
        return error;
    }
    if (tree->root == NULL) {
        printf("tree is empty\n");
        return error;
    }
    AVLNode *node = tree->root;
    while (node->right != NULL) {
        node = node->right;
    }
    *result = node->data;
    return true;
}

status AVLTreeGetMin(AVLTree *tree, ElementType *result) {
    if (tree == NULL) {
        printf("tree is NULL\n");
        return error;
    }
    if (tree->root == NULL) {
        printf("tree is empty\n");
        return error;
    }
    AVLNode *node = tree->root;
    while (node->left != NULL) {
        node = node->left;
    }
    *result = node->data;
    return true;
}

// get status
int AVLTreeGetHeight(AVLTree *tree) {
    if (tree == NULL)
        return -1;
    if (tree->root == NULL)
        return 0;
    return tree->root->height;
}

int GetNodeHeight(AVLNode *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

ElementType GetNodeMax(AVLNode *node) {
    if (node == NULL)
        return -1;
    while (node->right != NULL) {
        node = node->right;
    }
    return node->data;
}

ElementType GetNodeMin(AVLNode *node) {
    if (node == NULL)
        return -1;
    while (node->left != NULL) {
        node = node->left;
    }
    return node->data;
}

int AVLTreeGetSize(AVLTree *tree) {
    if (tree == NULL)
        return -1;
    return tree->size;
}

status AVLTreeIsEmpty(AVLTree *tree) {
    if (tree == NULL)
        return error;
    return tree->size == 0;
}

// rotate
void LeftRotation(AVLNode **root) {
    AVLNode *node = *root;
    AVLNode *temp = node->right;
    // rotate
    node->right = temp->left;
    temp->left = node;
    *root = temp;
    // update height
    node->height =
            max(GetNodeHeight(node->left), GetNodeHeight(node->right)) + 1;
    temp->height = max(GetNodeHeight(node), GetNodeHeight(temp->right)) + 1;
}

void RightRotation(AVLNode **root) {
    AVLNode *node = *root;
    AVLNode *temp = node->left;
    // rotate
    node->left = temp->right;
    temp->right = node;
    *root = temp;
    // update height
    node->height =
            max(GetNodeHeight(node->left), GetNodeHeight(node->right)) + 1;
    temp->height = max(GetNodeHeight(node), GetNodeHeight(temp->left)) + 1;
}

// private functions
int max(int a, int b) {
    return a > b ? a : b;
}