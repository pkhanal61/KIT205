#ifndef BST_H
#define BST_H

typedef struct SongNode {

    char title[100];
    char artistName[100]; // it stores artist

    struct SongNode* left;
    struct SongNode* right;

} SongNode;

SongNode* create_song_node(char title[], char artistName[]);
SongNode* insert_song(SongNode* root, char title[], char artistName[]);
void inorder_songs(SongNode* root);

#endif