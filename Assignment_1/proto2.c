#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "proto2.h"
#include "hashtable.h"
#include "avl.h"
// set all table slots to NULL and global song tree to empty
void init_proto2(Proto2DB* db) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        db->table[i] = NULL;
    }
    db->all_songs = NULL;   // global song tree starts empty
}

// adding artist to the hash table
void add_artist_p2(Proto2DB* db, char name[]) {
    insert_artist_hash(db->table, name);
}

void add_song_p2(Proto2DB* db, char artistName[], char songTitle[]) {

// find the artist in the hash table first
    ArtistHash* artist = find_artist_hash(db->table, artistName);
    if (artist == NULL) return;

// check if song already exists in the global shared tree
    AVLNode* song = find_avl(db->all_songs, songTitle);

// if song not in global tree yet then add it
    if (song == NULL) {
        db->all_songs = insert_avl(db->all_songs, songTitle);
        song = find_avl(db->all_songs, songTitle);
    }

// this is how many-to-many works - all artists point to same song node
    add_artist_to_song(song, artistName);


    artist->songs = insert_avl(artist->songs, songTitle);
}
// print all artists in the database
void print_artists_p2(Proto2DB* db) {
    print_artists_hash(db->table);
}

void print_songs_p2(Proto2DB* db, char artistName[]) {

    ArtistHash* artist = find_artist_hash(db->table, artistName);
    if (artist == NULL) return;

    printf("\nSongs by %s:\n", artistName);

// here shared songs show all artists, not just the one we are currently looking at
    print_songs_with_artists(artist->songs, db->all_songs);
}