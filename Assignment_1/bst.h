#ifndef BST_H
#define BST_H

typedef struct SongNode {

    char title[100];

    struct SongNode* left;
    struct SongNode* right;

} SongNode;

SongNode* create_song_node(char title[]);
SongNode* insert_song(SongNode* root, char title[]);
void inorder_songs(SongNode* root);

#endif