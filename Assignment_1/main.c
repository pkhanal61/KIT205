#include <stdio.h>

#include "linkedlist.h"
#include "bst.h"

int main() {

    Artist* artistList = NULL; // it creats empty artist list
    //adding artists
    insert_artist(&artistList, "Drake");
    insert_artist(&artistList, "TaylorSwift");
    insert_artist(&artistList, "EdSheeran");

    print_artists(artistList); // displaying all artists

    Artist* drake = find_artist(artistList, "Drake");

    if (drake != NULL) {

        drake->songs = insert_song(drake->songs, "GodsPlan", "Drake");
        drake->songs = insert_song(drake->songs, "OneDance", "Drake");
        drake->songs = insert_song(drake->songs, "HotlineBling", "Drake");

        printf("\nSongs by Drake:\n");

        inorder_songs(drake->songs); // it prints all the songs in sorted order
    }

    return 0;
}