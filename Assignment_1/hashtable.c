#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "avl.h"

#define TABLE_SIZE 100

// hash function
unsigned int hash(char name[]) {
    unsigned int hash = 0;

    for (int i = 0; name[i] != '\0'; i++) {
        hash = hash * 31 + name[i];
    }

    return hash % TABLE_SIZE;
}

// creates artist
ArtistHash* create_artist_hash(char name[]) {

    ArtistHash* newArtist = (ArtistHash*)malloc(sizeof(ArtistHash));

    strcpy(newArtist->name, name);
    newArtist->songs = NULL;
    newArtist->next = NULL;

    return newArtist;
}

// inserts artist
void insert_artist_hash(ArtistHash* table[], char name[]) {

    unsigned int index = hash(name);

    ArtistHash* newArtist = create_artist_hash(name);

    newArtist->next = table[index];
    table[index] = newArtist;
}

// finding artist
ArtistHash* find_artist_hash(ArtistHash* table[], char name[]) {

    unsigned int index = hash(name);

    ArtistHash* current = table[index];

    while (current != NULL) {

        if (strcmp(current->name, name) == 0) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

// print artists
void print_artists_hash(ArtistHash* table[]) {

    printf("\nArtists:\n");

    for (int i = 0; i < TABLE_SIZE; i++) {

        ArtistHash* current = table[i];

        while (current != NULL) {
            printf("%s\n", current->name);
            current = current->next;
        }
    }
}