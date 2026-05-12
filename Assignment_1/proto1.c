#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "proto1.h"

void init_db(Proto1DB* db) {
    db->artists = NULL;
}

// adding artist
void add_artist(Proto1DB* db, char name[]) {
    insert_artist(&db->artists, name);
}

// adding songs
void add_song_to_artist(Proto1DB* db, char artistName[], char songTitle[]) {

    Artist* artist = find_artist(db->artists, artistName);

    if (artist != NULL) {
        artist->songs = insert_song(artist->songs, songTitle, artistName);
    }
}

// prints artist
void print_artists_db(Proto1DB* db) {
    print_artist_list(db->artists);
}

// prints songs
void print_songs_of_artist(Proto1DB* db, char artistName[]) {

    Artist* artist = find_artist(db->artists, artistName);

    if (artist != NULL) {
        printf("\nSongs by %s:\n", artistName);
        inorder_songs(artist->songs);
    }
}