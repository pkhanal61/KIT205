#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"

int height(AVLNode* n) {
    if (n == NULL) return 0;
    return n->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

// create a new AVL node for a song
AVLNode* create_avl_node(char title[]) {

    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));

    strcpy(node->title, title);

    node->artists = NULL;   // no artists linked yet
    node->left = NULL;
    node->right = NULL;
    node->height = 1;  // new node starts at height 1

    return node;
}

// right rotation to fix left heavy tree
AVLNode* right_rotate(AVLNode* y) {

    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x; // x is new root
}

// left rotation to fix right heavy tree
AVLNode* left_rotate(AVLNode* x) {

    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

// doing the rotation
    y->left = x;
    x->right = T2;

// update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y; // here y is new root
}

// balance factor: positive means left heavy, negative means right heavy
int get_balance(AVLNode* n) {
    if (n == NULL) return 0;
    return height(n->left) - height(n->right);
}

// insert a song title into the AVL tree
// tree stays balanced automatically using rotations
AVLNode* insert_avl(AVLNode* node, char title[]) {

    // normal BST insert first
    if (node == NULL)
        return create_avl_node(title);

    if (strcmp(title, node->title) < 0)
        node->left = insert_avl(node->left, title);

    else if (strcmp(title, node->title) > 0)
        node->right = insert_avl(node->right, title);

    else
        return node; 

// update height of current node
    node->height = 1 + max(height(node->left), height(node->right));

// check if tree is unbalanced
    int balance = get_balance(node);

//Left left - left heavy and new node went left
    if (balance > 1 && strcmp(title, node->left->title) < 0)
        return right_rotate(node);

//Right right
    if (balance < -1 && strcmp(title, node->right->title) > 0)
        return left_rotate(node);

//Left right
    if (balance > 1 && strcmp(title, node->left->title) > 0) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }
//Right left
    if (balance < -1 && strcmp(title, node->right->title) < 0) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node; // already balanced
}

// add an artist to a song node
// checks for duplicates 
void add_artist_to_song(AVLNode* song, char artistName[]) {

    if (song == NULL) return;

    ArtistList* temp = song->artists;


    while (temp != NULL) {
        if (strcmp(temp->name, artistName) == 0) {
            return; // already exists
        }
        temp = temp->next;
    }


    ArtistList* newArtist = (ArtistList*)malloc(sizeof(ArtistList));
    strcpy(newArtist->name, artistName);
    newArtist->next = song->artists;
    song->artists = newArtist;
}

// search for a song in the AVL tree by title
AVLNode* find_avl(AVLNode* root, char title[]) {

    if (root == NULL) return NULL; // not found

    int cmp = strcmp(title, root->title);

    if (cmp == 0) return root; // found it

    if (cmp < 0)
        return find_avl(root->left, title); // go left

    return find_avl(root->right, title); // go right
}

void inorder_avl(AVLNode* root) {

    if (root == NULL) return;

    inorder_avl(root->left);

    printf("%s - ", root->title);

    // print artist list for this song
    ArtistList* a = root->artists;
    if (a == NULL) {
        printf("No artists");
    } else {
        while (a != NULL) {
            printf("%s", a->name);
            if (a->next != NULL) printf(", ");
            a = a->next;
        }
    }

    printf("\n");

    inorder_avl(root->right);
}

// print songs for one artist 
void print_songs_with_artists(AVLNode* artistTree, AVLNode* globalTree) {

    if (artistTree == NULL) return;

    print_songs_with_artists(artistTree->left, globalTree);

// look up this song in the global tree to get all artists not just one
    AVLNode* globalSong = find_avl(globalTree, artistTree->title);

    printf("%s - ", artistTree->title);

    if (globalSong == NULL || globalSong->artists == NULL) {
        printf("No artists");
    } else {
        ArtistList* a = globalSong->artists;
        while (a != NULL) {
            printf("%s", a->name);
            if (a->next != NULL) printf(", ");
            a = a->next;
        }
    }

    printf("\n");

    print_songs_with_artists(artistTree->right, globalTree);
}