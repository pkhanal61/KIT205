#include <stdio.h>

#include "proto1.h"
#include "proto2.h"
#include "evaluation.h"

int main() {

//PROTOTYPE 1
    
    Proto1DB db1;

    init_db(&db1);

    // Artists
    add_artist(&db1, "Zayn Malik");
    add_artist(&db1, "Harry Styles");
    add_artist(&db1, "Liam Payne");

    // Solo songs
    add_song_to_artist(&db1, "Zayn Malik", "Dusk Till Dawn");
    add_song_to_artist(&db1, "Zayn Malik", "I Don't Wanna Live Forever");

    add_song_to_artist(&db1, "Harry Styles", "Watermelon Sugar");
    add_song_to_artist(&db1, "Harry Styles", "As It Was");

    add_song_to_artist(&db1, "Liam Payne", "Strip That Down");
    add_song_to_artist(&db1, "Liam Payne", "Stack It Up");

    // Many to many songs
    add_song_to_artist(&db1, "Zayn Malik", "What Makes You Beautiful");
    add_song_to_artist(&db1, "Harry Styles", "What Makes You Beautiful");
    add_song_to_artist(&db1, "Liam Payne", "What Makes You Beautiful");

    add_song_to_artist(&db1, "Zayn Malik", "Steal My Girl");
    add_song_to_artist(&db1, "Harry Styles", "Steal My Girl");
    add_song_to_artist(&db1, "Liam Payne", "Steal My Girl");


    printf("\nPROTO 1 OUTPUT");
    printf("\n===================\n");

    printf("\nARTISTS\n");
    print_artists_db(&db1);

    printf("\n\nSONGS (Zayn Malik)\n");
    print_songs_of_artist(&db1, "Zayn Malik");

    printf("\n\nSONGS (Harry Styles)\n");
    print_songs_of_artist(&db1, "Harry Styles");

    printf("\n\nSONGS (Liam Payne)\n");
    print_songs_of_artist(&db1, "Liam Payne");


// PROTOTYPE 2

    Proto2DB db2;

    init_proto2(&db2);

    // Artists
    add_artist_p2(&db2, "Zayn Malik");
    add_artist_p2(&db2, "Harry Styles");
    add_artist_p2(&db2, "Liam Payne");

    // Solo songs
    add_song_p2(&db2, "Zayn Malik", "Dusk Till Dawn");
    add_song_p2(&db2, "Zayn Malik", "I Don't Wanna Live Forever");

    add_song_p2(&db2, "Harry Styles", "Watermelon Sugar");
    add_song_p2(&db2, "Harry Styles", "As It Was");

    add_song_p2(&db2, "Liam Payne", "Strip That Down");
    add_song_p2(&db2, "Liam Payne", "Stack It Up");

    // Many to many songs
    add_song_p2(&db2, "Zayn Malik", "What Makes You Beautiful");
    add_song_p2(&db2, "Harry Styles", "What Makes You Beautiful");
    add_song_p2(&db2, "Liam Payne", "What Makes You Beautiful");

    add_song_p2(&db2, "Zayn Malik", "Steal My Girl");
    add_song_p2(&db2, "Harry Styles", "Steal My Girl");
    add_song_p2(&db2, "Liam Payne", "Steal My Girl");


    printf("\nPROTO 2 OUTPUT");
    printf("\n===================\n");


    printf("\nARTISTS\n");
    print_artists_p2(&db2);

    printf("\n\nSONGS (Zayn Malik)\n");
    print_songs_p2(&db2, "Zayn Malik");

    printf("\n\nSONGS (Harry Styles)\n");
    print_songs_p2(&db2, "Harry Styles");

    printf("\n\nSONGS (Liam Payne)\n");
    print_songs_p2(&db2, "Liam Payne");

    run_evaluation();

    return 0;
}