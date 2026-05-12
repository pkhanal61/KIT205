#ifndef PROTO1_H
#define PROTO1_H

#include "linkedlist.h"
#include "bst.h"

typedef struct Proto1DB {
    Artist* artists;
} Proto1DB;

void init_db(Proto1DB* db);

void add_artist(Proto1DB* db, char name[]);
void add_song_to_artist(Proto1DB* db, char artistName[], char songTitle[]);

void print_artists_db(Proto1DB* db);
void print_songs_of_artist(Proto1DB* db, char artistName[]);

#endif