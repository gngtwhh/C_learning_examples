#include <stdio.h>
#include <stdlib.h>
#include "BSTree.h"


// create and destroy
BTreePtr create_tree(void) {
    BTreePtr T = (BTreePtr) malloc(sizeof(BTree));
    if (T == NULL) {
        printf("Error: create tree failed.\n");
        return NULL;
    }
    T->root = NULL;
    T->size = 0;
    return T;
}

void destroy_tree_run(TreeNode *node) {
    if (node == NULL) {
        return;
    }
    destroy_tree_run(node->left);
    destroy_tree_run(node->right);
    free(node);
}

void destroy_tree(BTreePtr T) {
    destroy_tree_run(T->root);
    free(T);
}

// check status
bool is_empty_tree(BTreePtr T) {
    return T->size == 0;
}

// int tree_height(BTreePtr T);

int tree_size(BTreePtr T) {
    return T->size;
}

TreeElementType find_min(BTreePtr T) {
    TreeNode *p = T->root;
    while (p->left != NULL) {
        p = p->left;
    }
    return p->value;
}

TreeElementType find_max(BTreePtr T) {
    TreeNode *p = T->root;
    while (p->right != NULL) {
        p = p->right;
    }
    return p->value;
}

// operations
bool insert(BTreePtr T, TreeElementType value) {
    TreeNode *node = (TreeNode *) malloc(sizeof(TreeNode));
    if (node == NULL) {
        printf("Error: create node failed.\n");
        return false;
    }
    node->value = value;
    node->left = NULL;
    node->right = NULL;

    if (T->root == NULL) {
        T->root = node;
        T->size++;
        return true;
    }

    TreeNode *p = T->root;
    while (p != NULL) {
        if (value < p->value) {
            if (p->left == NULL) {
                p->left = node;
                T->size++;
                return true;
            }
            p = p->left;
        } else if (value > p->value) {
            if (p->right == NULL) {
                p->right = node;
                T->size++;
                return true;
            }
            p = p->right;
        } else {
            printf("Error: value %d already exists.\n", value);
            return false;
        }
    }
    return false;
}

bool delete(BTreePtr T, TreeElementType value) {
    TreeNode *p = T->root;
    TreeNode *parent = NULL;
    // find the node to delete
    while (p != NULL) {
        if (value < p->value) {
            parent = p;
            p = p->left;
        } else if (value > p->value) {
            parent = p;
            p = p->right;
        } else {
            break;
        }
    }
    // if not found
    if (p == NULL) {
        printf("Error: value %d not found.\n", value);
        return false;
    }

    /*
     * case 1: p is a leaf node
     */
    if (p->left == NULL && p->right == NULL) {
        if (parent == NULL) {
            T->root = NULL;
        } else if (parent->left == p) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        free(p);
        T->size--;
        return true;
    }

    /*
     * case 2: p has only one child
     */
    if (p->left == NULL) {
        if (parent == NULL) {
            T->root = p->right;
        } else if (parent->left == p) {
            parent->left = p->right;
        } else {
            parent->right = p->right;
        }
        free(p);
        T->size--;
        return true;
    }
    if (p->right == NULL) {
        if (parent == NULL) {
            T->root = p->left;
        } else if (parent->left == p) {
            parent->left = p->left;
        } else {
            parent->right = p->left;
        }
        free(p);
        T->size--;
        return true;
    }

    /*
     * case 3: p has two children
     */
    TreeNode *q = p->right;
    TreeNode *q_parent = p;
    // find the smallest node in the right subtree of p
    while (q->left != NULL) {
        q_parent = q;
        q = q->left;
    }
    // replace p with q
    p->value = q->value;
    // delete q,q is a leaf node or has only one child---its right child
    // In effect, the question is shifted to deleting a node with no left child
    // It doesn't really matter here q->right is NULL or not
    if (q_parent->left == q) {
        q_parent->left = q->right;
    } else {
        q_parent->right = q->right;
    }
    free(q);
    T->size--;
    return true;
}

// bool invert_tree(BTreePtr T);