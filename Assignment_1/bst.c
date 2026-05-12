#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst.h"

SongNode* create_song_node(char title[]) {

    SongNode* newNode = (SongNode*)malloc(sizeof(SongNode)); //allocating memory

    strcpy(newNode->title, title); //it stores the song title

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

SongNode* insert_song(SongNode* root, char title[]) {

    if (root == NULL) {
        return create_song_node(title); 
    }

    if (strcmp(title, root->title) < 0) {

        root->left = insert_song(root->left, title); //going left

    }
    else if (strcmp(title, root->title) > 0) {

        root->right = insert_song(root->right, title); //going right
    }

    return root;
}

void inorder_songs(SongNode* root) {

    if (root == NULL) {
        return;
    }

    inorder_songs(root->left);

    printf("%s\n", root->title); //it prints the current node

    inorder_songs(root->right);
}