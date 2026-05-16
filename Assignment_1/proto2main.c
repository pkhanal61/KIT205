#include <stdio.h>
#include "proto2.h"

int main() {

    Proto2DB db;

// initialize system
    init_proto2(&db);

//  Artists
  
    add_artist_p2(&db, "Zayn Malik");
    add_artist_p2(&db, "Harry Styles");
    add_artist_p2(&db, "Liam Payne");

    // Solo songs

    add_song_p2(&db, "Zayn Malik", "Dusk Till Dawn");
    add_song_p2(&db, "Zayn Malik", "I Don't Wanna Live Forever");

    add_song_p2(&db, "Harry Styles", "Watermelon Sugar");
    add_song_p2(&db, "Harry Styles", "As It Was");

    add_song_p2(&db, "Liam Payne", "Strip That Down");
    add_song_p2(&db, "Liam Payne", "Stack It Up");


// Many to many songs

    add_song_p2(&db, "Zayn Malik", "What Makes You Beautiful");
    add_song_p2(&db, "Harry Styles", "What Makes You Beautiful");
    add_song_p2(&db, "Liam Payne", "What Makes You Beautiful");

    add_song_p2(&db, "Zayn Malik", "Steal My Girl");
    add_song_p2(&db, "Harry Styles", "Steal My Girl");
    add_song_p2(&db, "Liam Payne", "Steal My Girl");


//Output

    printf("\nARTISTS \n");
    print_artists_p2(&db);

    printf("\n\nSONGS Zayn Malik\n");
    print_songs_p2(&db, "Zayn Malik");

    printf("\n\nSONGS (Harry Styles)\n");
    print_songs_p2(&db, "Harry Styles");

    printf("\n\nSONGS (Liam Payne) \n");
    print_songs_p2(&db, "Liam Payne");

    return 0;
}