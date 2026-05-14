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
    ArtistListBST* artists; // linked list of artist names

    struct SongNode* left;
    struct SongNode* right;

} SongNode;

//Functions
SongNode* create_song_node(char title[]);
SongNode* insert_song(SongNode* root, char title[]);


void add_artist_to_bst_song(SongNode* song, char artistName[]);
SongNode* find_song(SongNode* root, char title[]);
void inorder_songs(SongNode* root);
void print_bst_with_global(SongNode* artistTree, SongNode* globalTree);

#endif