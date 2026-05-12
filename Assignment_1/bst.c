#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst.h"

SongNode* create_song_node(char title[], char artistName[]) {

    SongNode* newNode = (SongNode*)malloc(sizeof(SongNode));

    strcpy(newNode->title, title); //it store songs
    strcpy(newNode->artistName, artistName); //it store artists

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

SongNode* insert_song(SongNode* root, char title[], char artistName[]) {

    if (root == NULL) {
        return create_song_node(title, artistName);
    }

    if (strcmp(title, root->title) < 0) {
        root->left = insert_song(root->left, title, artistName);
    }
    else if (strcmp(title, root->title) > 0) {
        root->right = insert_song(root->right, title, artistName);
    }

    return root;
}

void inorder_songs(SongNode* root) {

    if (root == NULL) return;

    inorder_songs(root->left);

    printf("%s - %s\n", root->title, root->artistName);

    inorder_songs(root->right);
}
