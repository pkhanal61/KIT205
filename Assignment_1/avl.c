#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"

// get height
int height(AVLNode* n) {
    if (n == NULL) return 0;
    return n->height;
}

// max
int max(int a, int b) {
    return (a > b) ? a : b;
}

// it creates node
AVLNode* create_avl_node(char title[]) {

    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));

    strcpy(node->title, title);
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

// it rotates right
AVLNode* right_rotate(AVLNode* y) {

    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// it rotates left
AVLNode* left_rotate(AVLNode* x) {

    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// balance factor
int get_balance(AVLNode* n) {
    if (n == NULL) return 0;
    return height(n->left) - height(n->right);
}

// inserting
AVLNode* insert_avl(AVLNode* node, char title[]) {

    if (node == NULL)
        return create_avl_node(title);

    if (strcmp(title, node->title) < 0)
        node->left = insert_avl(node->left, title);

    else if (strcmp(title, node->title) > 0)
        node->right = insert_avl(node->right, title);

    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = get_balance(node);

    // LL
    if (balance > 1 && strcmp(title, node->left->title) < 0)
        return right_rotate(node);

    // RR
    if (balance < -1 && strcmp(title, node->right->title) > 0)
        return left_rotate(node);

    // LR
    if (balance > 1 && strcmp(title, node->left->title) > 0) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    // RL
    if (balance < -1 && strcmp(title, node->right->title) < 0) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

// inorder
void inorder_avl(AVLNode* root) {

    if (root == NULL)
        return;

    inorder_avl(root->left);
    printf("%s\n", root->title);
    inorder_avl(root->right);
}