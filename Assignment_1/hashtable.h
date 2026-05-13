#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "avl.h"

typedef struct ArtistHash {

    char name[100];
    AVLNode* songs;

    struct ArtistHash* next;

} ArtistHash;

// functions
unsigned int hash(char name[]);

ArtistHash* create_artist_hash(char name[]);
void insert_artist_hash(ArtistHash* table[], char name[]);
ArtistHash* find_artist_hash(ArtistHash* table[], char name[]);
void print_artists_hash(ArtistHash* table[]);

#endif