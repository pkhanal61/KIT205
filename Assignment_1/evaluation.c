#include <stdio.h>
#include <time.h>

#include "proto1.h"
#include "proto2.h"
#include "evaluation.h"

void run_evaluation() {

    Proto1DB db1;
    Proto2DB db2;

    init_db(&db1);
    init_proto2(&db2);

    clock_t start, end;

    //Prototype 1

    start = clock();

    for (int i = 0; i < 5000; i++) {

        char artist[50];
        char song[50];

        sprintf(artist, "Artist%d", i);
        sprintf(song, "Song%d", i);

        add_artist(&db1, artist);
        add_song_to_artist(&db1, artist, song);
    }

    end = clock();

    double proto1_time = (double)(end - start) / CLOCKS_PER_SEC;

    //Prototype 2

    start = clock();

    for (int i = 0; i < 5000; i++) {

        char artist[50];
        char song[50];

        sprintf(artist, "Artist%d", i);
        sprintf(song, "Song%d", i);

        add_artist_p2(&db2, artist);
        add_song_p2(&db2, artist, song);
    }

    end = clock();

    double proto2_time = (double)(end - start) / CLOCKS_PER_SEC;

    // results
    printf("\nPERFORMANCE RESULTS : \n");

    printf("Prototype 1 Time: %f seconds\n", proto1_time);

    printf("Prototype 2 Time: %f seconds\n", proto2_time);
}