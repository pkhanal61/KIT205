#ifndef AVL_H
#define AVL_H

typedef struct AVLNode {

    char title[100];

    struct AVLNode* left;
    struct AVLNode* right;

    int height;

} AVLNode;

// functions
AVLNode* create_avl_node(char title[]);
AVLNode* insert_avl(AVLNode* root, char title[]);
void inorder_avl(AVLNode* root);

#endif