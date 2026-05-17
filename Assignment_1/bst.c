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

// add an artist to a song node
// uses a linked list so one song can have multiple artists
void add_artist_to_bst_song(SongNode* song, char artistName[]) {

    if (song == NULL) return;

    // check if artist is already in the list
    ArtistListBST* temp = song->artists;
    while (temp != NULL) {
        if (strcmp(temp->name, artistName) == 0) {
            return; // already exists, don't add again
        }
        temp = temp->next;
    }

    // create new artist and add to front of list
    ArtistListBST* newArtist = (ArtistListBST*)malloc(sizeof(ArtistListBST));
    strcpy(newArtist->name, artistName);
    newArtist->next = song->artists;
    song->artists = newArtist;
}


SongNode* find_song(SongNode* root, char title[]) {

    if (root == NULL) return NULL; // not found

    int cmp = strcmp(title, root->title);

    if (cmp == 0) return root; // found it

    if (cmp < 0)
        return find_song(root->left, title); // go left

    return find_song(root->right, title); // go right
}


void inorder_songs(SongNode* root) {

    if (root == NULL) return;

    inorder_songs(root->left);

    printf("%s - ", root->title);

    // print all artists for this song
    ArtistListBST* a = root->artists;
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

    inorder_songs(root->right);
}

// print songs for one artist but look up each song in the global tree
// this way we get ALL artists on shared songs not just one
void print_bst_with_global(SongNode* artistTree, SongNode* globalTree) {

    if (artistTree == NULL) return;

    print_bst_with_global(artistTree->left, globalTree);

    SongNode* globalSong = find_song(globalTree, artistTree->title);

    printf("    %s", artistTree->title);

    // only print artists if more than one (shared song)
    if (globalSong != NULL && globalSong->artists != NULL && globalSong->artists->next != NULL) {
        printf(" - All three : ");
        ArtistListBST* a = globalSong->artists;
        int first = 1;
        while (a != NULL) {
            if (!first) printf(", ");
            printf("%s", a->name);
            first = 0;
            a = a->next;
        }
    }

    printf("\n");

    print_bst_with_global(artistTree->right, globalTree);
}