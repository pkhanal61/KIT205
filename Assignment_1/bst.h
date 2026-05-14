#ifndef BST_H
#define BST_H

// linked list to store artist names for each song
typedef struct ArtistListBST {
    char name[100];
    struct ArtistListBST* next;
} ArtistListBST;

//BST node
typedef struct SongNode {
    char title[100];
    ArtistListBST* artists;

    struct SongNode* left;
    struct SongNode* right;

} SongNode;

//Functions
SongNode* create_song_node(char title[]);
SongNode* insert_song(SongNode* root, char title[]);

#endif