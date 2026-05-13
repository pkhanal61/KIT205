#ifndef PROTO2_H
#define PROTO2_H

#include "hashtable.h"
#include "avl.h"

#define TABLE_SIZE 100

typedef struct Proto2DB {
    ArtistHash* table[TABLE_SIZE];
} Proto2DB;

// operations
void init_proto2(Proto2DB* db);

void add_artist_p2(Proto2DB* db, char name[]);
void add_song_p2(Proto2DB* db, char artistName[], char songTitle[]);

void print_artists_p2(Proto2DB* db);
void print_songs_p2(Proto2DB* db, char artistName[]);

#endif