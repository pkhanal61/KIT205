#ifndef AVL_H
#define AVL_H


typedef struct ArtistList {
    char name[100];
    struct ArtistList* next;
} ArtistList;
typedef struct AVLNode {

    char title[100];

    ArtistList* artists; 
    struct AVLNode* left;
    struct AVLNode* right;

    int height;

} AVLNode;

// functions
AVLNode* create_avl_node(char title[]);
AVLNode* insert_avl(AVLNode* root, char title[]);
void add_artist_to_song(AVLNode* song, char artistName[]);
AVLNode* find_avl(AVLNode* root, char title[]);
void inorder_avl(AVLNode* root);
void print_songs_with_artists(AVLNode* artistTree, AVLNode* globalTree);

#endif