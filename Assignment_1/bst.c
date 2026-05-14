#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst.h"

// create a new song node and set everything to NULL
SongNode* create_song_node(char title[]) {

    SongNode* newNode = (SongNode*)malloc(sizeof(SongNode));

    strcpy(newNode->title, title); 
    newNode->artists = NULL; // no artists yet
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// insert song into BST - goes left if smaller, right if bigger
SongNode* insert_song(SongNode* root, char title[]) {


    if (root == NULL) {
        return create_song_node(title);
    }

    if (strcmp(title, root->title) < 0) {
        root->left = insert_song(root->left, title);
    }
    else if (strcmp(title, root->title) > 0) {
        root->right = insert_song(root->right, title);
    }
    // if same title already exists just ignore it

    return root;
}