#include <stdio.h>
#include "proto1.h"

int main() {

    Proto1DB db;

// initialize system
    init_db(&db);

// Artists
    add_artist(&db, "Zayn Malik");
    add_artist(&db, "Harry Styles");
    add_artist(&db, "Liam Payne");

// Solo songs
    add_song_to_artist(&db, "Zayn Malik", "Dusk Till Dawn");
    add_song_to_artist(&db, "Zayn Malik", "I Don't Wanna Live Forever");

    add_song_to_artist(&db, "Harry Styles", "Watermelon Sugar");
    add_song_to_artist(&db, "Harry Styles", "As It Was");

    add_song_to_artist(&db, "Liam Payne", "Strip That Down");
    add_song_to_artist(&db, "Liam Payne", "Stack It Up");

// Many to many songs
    add_song_to_artist(&db, "Zayn Malik",  "What Makes You Beautiful");
    add_song_to_artist(&db, "Harry Styles", "What Makes You Beautiful");
    add_song_to_artist(&db, "Liam Payne",  "What Makes You Beautiful");

    add_song_to_artist(&db, "Zayn Malik",  "Steal My Girl");
    add_song_to_artist(&db, "Harry Styles", "Steal My Girl");
    add_song_to_artist(&db, "Liam Payne",  "Steal My Girl");

// Output
    printf("\nARTISTS\n");
    print_artists_db(&db);

    printf("\n\nSONGS (Zayn Malik)\n");
    print_songs_of_artist(&db, "Zayn Malik");

    printf("\n\nSONGS (Harry Styles)\n");
    print_songs_of_artist(&db, "Harry Styles");

    printf("\n\nSONGS (Liam Payne)\n");
    print_songs_of_artist(&db, "Liam Payne");

    return 0;
}