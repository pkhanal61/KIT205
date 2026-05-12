#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "bst.h"

typedef struct Artist {
    char name[100];

    SongNode* songs;

    struct Artist* next;

} Artist;

Artist* create_artist(char name[]);
void insert_artist(Artist** head, char name[]);
Artist* find_artist(Artist* head, char name[]);
void print_artists(Artist* head);

#endif