#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "proto1.h"

void init_db(Proto1DB* db) {
    db->artists = NULL;
    db->all_songs = NULL;   // global song BST starts empty
}

void add_artist(Proto1DB* db, char name[]) {
    insert_artist(&db->artists, name);
}

void add_song_to_artist(Proto1DB* db, char artistName[], char songTitle[]) {

    Artist* artist = find_artist(db->artists, artistName);
    if (artist == NULL) return;

    // STEP 1: look for the song in the ONE shared global BST
    SongNode* song = find_song(db->all_songs, songTitle);

    // STEP 2: if not found, insert it into the global BST
    if (song == NULL) {
        db->all_songs = insert_song(db->all_songs, songTitle);
        song = find_song(db->all_songs, songTitle);
    }

    // STEP 3: add this artist to that shared song node
    add_artist_to_bst_song(song, artistName);

    // STEP 4: also insert into the artist's own BST
    //         (so we can print "songs by X")
    artist->songs = insert_song(artist->songs, songTitle);
}

void print_artists_db(Proto1DB* db) {
    print_artist_list(db->artists);
}

void print_songs_of_artist(Proto1DB* db, char artistName[]) {

    Artist* artist = find_artist(db->artists, artistName);
    if (artist == NULL) return;

    printf("\nSongs by %s:\n", artistName);

    // walk this artist's songs, look each one up in the global BST
    print_bst_with_global(artist->songs, db->all_songs);
}