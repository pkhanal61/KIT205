#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "proto2.h"
#include "hashtable.h"
#include "avl.h"
void init_proto2(Proto2DB* db) {

    for (int i = 0; i < TABLE_SIZE; i++) {
        db->table[i] = NULL;
    }
}
void add_artist_p2(Proto2DB* db, char name[]) {
    insert_artist_hash(db->table, name);
}
//Adding song
void add_song_p2(Proto2DB* db, char artistName[], char songTitle[]) {

    ArtistHash* artist = find_artist_hash(db->table, artistName);

    if (artist != NULL) {
        artist->songs = insert_avl(artist->songs, songTitle);
    }
}
//printing artist
void print_artists_p2(Proto2DB* db) {
    print_artists_hash(db->table);
}

//printing song
void print_songs_p2(Proto2DB* db, char artistName[]) {

    ArtistHash* artist = find_artist_hash(db->table, artistName);

    if (artist != NULL) {
        printf("\nSongs by %s:\n", artistName);
        inorder_avl(artist->songs);
    }
}