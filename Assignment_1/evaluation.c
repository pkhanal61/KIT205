#include <stdio.h>
#include <time.h>

#include "proto1.h"
#include "proto2.h"
#include "evaluation.h"

void run_evaluation() {

    // test with different sizes to see how performance scales
    int sizes[] = {1000, 2000, 3000, 4000, 5000};
    int num_sizes = 5;

    printf("\nPERFORMANCE RESULTS:\n");
    printf("%-10s %-20s %-20s\n", "Size", "Prototype1 (s)", "Prototype2 (s)");
    printf("------------------------------------------------------\n");

    for (int s = 0; s < num_sizes; s++) {

        int n = sizes[s];

        // fresh database for each test
        Proto1DB db1;
        Proto2DB db2;

        init_db(&db1);
        init_proto2(&db2);

        clock_t start, end;

// For prototype 1
        start = clock();

        for (int i = 0; i < n; i++) {
            char artist[50];
            char song[50];
            sprintf(artist, "Artist%d", i);
            sprintf(song, "Song%d", i);
            add_artist(&db1, artist);
            add_song_to_artist(&db1, artist, song);
        }

        end = clock();
        double proto1_time = (double)(end - start) / CLOCKS_PER_SEC;

// For prototype 2
        start = clock();

        for (int i = 0; i < n; i++) {
            char artist[50];
            char song[50];
            sprintf(artist, "Artist%d", i);
            sprintf(song, "Song%d", i);
            add_artist_p2(&db2, artist);
            add_song_p2(&db2, artist, song);
        }

        end = clock();
        double proto2_time = (double)(end - start) / CLOCKS_PER_SEC;

// print result for this size
        printf("%-10d %-20f %-20f\n", n, proto1_time, proto2_time);
    }
}