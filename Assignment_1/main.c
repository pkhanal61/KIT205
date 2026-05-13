#include <stdio.h>

#include "proto1.h"

int main() {

    Proto1DB db;

    init_db(&db);

    // Add artists
    add_artist(&db, "Drake");
    add_artist(&db, "TaylorSwift");
    add_artist(&db, "EdSheeran");

    // Add songs
    add_song_to_artist(&db, "Drake", "GodsPlan");
    add_song_to_artist(&db, "Drake", "OneDance");
    add_song_to_artist(&db, "Drake", "HotlineBling");

    add_song_to_artist(&db, "TaylorSwift", "LoveStory");
    add_song_to_artist(&db, "TaylorSwift", "BlankSpace");

    // Print results
    print_artists_db(&db);

    print_songs_of_artist(&db, "Drake");
    print_songs_of_artist(&db, "TaylorSwift");

    return 0;
}
