#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

Artist* create_artist(char name[]) {

    Artist* newArtist = (Artist*)malloc(sizeof(Artist)); // allocating memory

    strcpy(newArtist->name, name);

    newArtist->songs = NULL;
    newArtist->next = NULL;
    
    return newArtist;
}

void insert_artist(Artist** head, char name[]) {

    Artist* newArtist = create_artist(name); // creating node

    if (*head == NULL) {
        *head = newArtist; // fist artist in list
        return;
    }

    Artist* current = *head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newArtist; // attach new artist
}

Artist* find_artist(Artist* head, char name[]) {

    Artist* current = head;

    while (current != NULL) {

        if (strcmp(current->name, name) == 0) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

void print_artists(Artist* head) {

    Artist* current = head;

    printf("\nArtists List:\n");

    while (current != NULL) {

        printf("%s\n", current->name); //it prints each artist

        current = current->next;
    }
}