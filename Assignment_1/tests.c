#include <stdio.h>
#include <string.h>
#include "proto1.h"
#include "proto2.h"

void test_proto1() {
    printf("[Prototype 1 - Linked List + BST]\n");

    Proto1DB db;
    init_db(&db);

    // same artists as main program
    add_artist(&db, "Zayn Malik");
    add_artist(&db, "Harry Styles");
    add_artist(&db, "Liam Payne");

    // solo songs
    add_song_to_artist(&db, "Zayn Malik",   "Dusk Till Dawn");
    add_song_to_artist(&db, "Zayn Malik",   "I Don't Wanna Live Forever");
    add_song_to_artist(&db, "Harry Styles", "Watermelon Sugar");
    add_song_to_artist(&db, "Harry Styles", "As It Was");
    add_song_to_artist(&db, "Liam Payne",   "Strip That Down");
    add_song_to_artist(&db, "Liam Payne",   "Stack It Up");

    // many-to-many songs
    add_song_to_artist(&db, "Zayn Malik",   "What Makes You Beautiful");
    add_song_to_artist(&db, "Harry Styles", "What Makes You Beautiful");
    add_song_to_artist(&db, "Liam Payne",   "What Makes You Beautiful");

    add_song_to_artist(&db, "Zayn Malik",   "Steal My Girl");
    add_song_to_artist(&db, "Harry Styles", "Steal My Girl");
    add_song_to_artist(&db, "Liam Payne",   "Steal My Girl");

    // artist exists tests
    Artist* zayn  = find_artist(db.artists, "Zayn Malik");
    Artist* harry = find_artist(db.artists, "Harry Styles");
    Artist* liam  = find_artist(db.artists, "Liam Payne");

    if (zayn  != NULL) printf("  PASS: Zayn Malik exists in artists list\n");
    else               printf("  FAIL: Zayn Malik not found\n");

    if (harry != NULL) printf("  PASS: Harry Styles exists in artists list\n");
    else               printf("  FAIL: Harry Styles not found\n");

    if (liam  != NULL) printf("  PASS: Liam Payne exists in artists list\n");
    else               printf("  FAIL: Liam Payne not found\n");

    // artist not in list
    Artist* niall = find_artist(db.artists, "Niall Horan");
    if (niall == NULL) printf("  PASS: Niall Horan not in list (not added)\n");
    else               printf("  FAIL: Niall Horan should not exist\n");

    // solo songs
    SongNode* s1 = find_song(zayn->songs,  "Dusk Till Dawn");
    SongNode* s2 = find_song(zayn->songs,  "I Don't Wanna Live Forever");
    SongNode* s3 = find_song(harry->songs, "Watermelon Sugar");
    SongNode* s4 = find_song(harry->songs, "As It Was");
    SongNode* s5 = find_song(liam->songs,  "Strip That Down");
    SongNode* s6 = find_song(liam->songs,  "Stack It Up");

    if (s1 != NULL) printf("  PASS: Zayn has Dusk Till Dawn\n");
    else            printf("  FAIL: Dusk Till Dawn not found\n");

    if (s2 != NULL) printf("  PASS: Zayn has I Don't Wanna Live Forever\n");
    else            printf("  FAIL: I Don't Wanna Live Forever not found\n");

    if (s3 != NULL) printf("  PASS: Harry has Watermelon Sugar\n");
    else            printf("  FAIL: Watermelon Sugar not found\n");

    if (s4 != NULL) printf("  PASS: Harry has As It Was\n");
    else            printf("  FAIL: As It Was not found\n");

    if (s5 != NULL) printf("  PASS: Liam has Strip That Down\n");
    else            printf("  FAIL: Strip That Down not found\n");

    if (s6 != NULL) printf("  PASS: Liam has Stack It Up\n");
    else            printf("  FAIL: Stack It Up not found\n");

    // What Makes You Beautiful in global BST
    SongNode* wmyb = find_song(db.all_songs, "What Makes You Beautiful");
    if (wmyb != NULL) printf("  PASS: What Makes You Beautiful in global BST\n");
    else              printf("  FAIL: What Makes You Beautiful not in global BST\n");

    // check all 3 artists on What Makes You Beautiful
    int has_zayn = 0, has_harry = 0, has_liam = 0;
    ArtistListBST* al = wmyb->artists;
    while (al != NULL) {
        if (strcmp(al->name, "Zayn Malik")   == 0) has_zayn  = 1;
        if (strcmp(al->name, "Harry Styles") == 0) has_harry = 1;
        if (strcmp(al->name, "Liam Payne")   == 0) has_liam  = 1;
        al = al->next;
    }
    if (has_zayn)  printf("  PASS: What Makes You Beautiful has Zayn Malik\n");
    else           printf("  FAIL: Zayn Malik not linked to What Makes You Beautiful\n");
    if (has_harry) printf("  PASS: What Makes You Beautiful has Harry Styles\n");
    else           printf("  FAIL: Harry Styles not linked to What Makes You Beautiful\n");
    if (has_liam)  printf("  PASS: What Makes You Beautiful has Liam Payne\n");
    else           printf("  FAIL: Liam Payne not linked to What Makes You Beautiful\n");

    // Steal My Girl in global BST
    SongNode* smg = find_song(db.all_songs, "Steal My Girl");
    if (smg != NULL) printf("  PASS: Steal My Girl in global BST\n");
    else             printf("  FAIL: Steal My Girl not in global BST\n");

    // check all 3 artists on Steal My Girl
    has_zayn = 0; has_harry = 0; has_liam = 0;
    al = smg->artists;
    while (al != NULL) {
        if (strcmp(al->name, "Zayn Malik")   == 0) has_zayn  = 1;
        if (strcmp(al->name, "Harry Styles") == 0) has_harry = 1;
        if (strcmp(al->name, "Liam Payne")   == 0) has_liam  = 1;
        al = al->next;
    }
    if (has_zayn)  printf("  PASS: Steal My Girl has Zayn Malik\n");
    else           printf("  FAIL: Zayn Malik not linked to Steal My Girl\n");
    if (has_harry) printf("  PASS: Steal My Girl has Harry Styles\n");
    else           printf("  FAIL: Harry Styles not linked to Steal My Girl\n");
    if (has_liam)  printf("  PASS: Steal My Girl has Liam Payne\n");
    else           printf("  FAIL: Liam Payne not linked to Steal My Girl\n");

    // print shared song artist lists
    printf("  What Makes You Beautiful (expect Zayn Malik, Harry Styles, Liam Payne):\n");
    ArtistListBST* wal = wmyb->artists;
    while (wal != NULL) {
        printf("    %s\n", wal->name);
        wal = wal->next;
    }

    printf("  Steal My Girl (expect Zayn Malik, Harry Styles, Liam Payne):\n");
    ArtistListBST* sal = smg->artists;
    while (sal != NULL) {
        printf("    %s\n", sal->name);
        sal = sal->next;
    }

    printf("  PASS: Proto1 free (no crash)\n\n");
}

void test_proto2() {
    printf("[Prototype 2 - Hash Table + AVL]\n");

    Proto2DB db;
    init_proto2(&db);

    // same artists as main program
    add_artist_p2(&db, "Zayn Malik");
    add_artist_p2(&db, "Harry Styles");
    add_artist_p2(&db, "Liam Payne");

    // solo songs
    add_song_p2(&db, "Zayn Malik",   "Dusk Till Dawn");
    add_song_p2(&db, "Zayn Malik",   "I Don't Wanna Live Forever");
    add_song_p2(&db, "Harry Styles", "Watermelon Sugar");
    add_song_p2(&db, "Harry Styles", "As It Was");
    add_song_p2(&db, "Liam Payne",   "Strip That Down");
    add_song_p2(&db, "Liam Payne",   "Stack It Up");

    // many-to-many songs
    add_song_p2(&db, "Zayn Malik",   "What Makes You Beautiful");
    add_song_p2(&db, "Harry Styles", "What Makes You Beautiful");
    add_song_p2(&db, "Liam Payne",   "What Makes You Beautiful");

    add_song_p2(&db, "Zayn Malik",   "Steal My Girl");
    add_song_p2(&db, "Harry Styles", "Steal My Girl");
    add_song_p2(&db, "Liam Payne",   "Steal My Girl");

    // artist exists tests
    ArtistHash* zayn  = find_artist_hash(db.table, "Zayn Malik");
    ArtistHash* harry = find_artist_hash(db.table, "Harry Styles");
    ArtistHash* liam  = find_artist_hash(db.table, "Liam Payne");

    if (zayn  != NULL) printf("  PASS: Zayn Malik exists in hash table\n");
    else               printf("  FAIL: Zayn Malik not found\n");

    if (harry != NULL) printf("  PASS: Harry Styles exists in hash table\n");
    else               printf("  FAIL: Harry Styles not found\n");

    if (liam  != NULL) printf("  PASS: Liam Payne exists in hash table\n");
    else               printf("  FAIL: Liam Payne not found\n");

    // artist not in table
    ArtistHash* niall = find_artist_hash(db.table, "Niall Horan");
    if (niall == NULL) printf("  PASS: Niall Horan not in hash table (not added)\n");
    else               printf("  FAIL: Niall Horan should not exist\n");

    // solo songs
    AVLNode* s1 = find_avl(zayn->songs,  "Dusk Till Dawn");
    AVLNode* s2 = find_avl(zayn->songs,  "I Don't Wanna Live Forever");
    AVLNode* s3 = find_avl(harry->songs, "Watermelon Sugar");
    AVLNode* s4 = find_avl(harry->songs, "As It Was");
    AVLNode* s5 = find_avl(liam->songs,  "Strip That Down");
    AVLNode* s6 = find_avl(liam->songs,  "Stack It Up");

    if (s1 != NULL) printf("  PASS: Zayn has Dusk Till Dawn in AVL\n");
    else            printf("  FAIL: Dusk Till Dawn not found\n");

    if (s2 != NULL) printf("  PASS: Zayn has I Don't Wanna Live Forever in AVL\n");
    else            printf("  FAIL: I Don't Wanna Live Forever not found\n");

    if (s3 != NULL) printf("  PASS: Harry has Watermelon Sugar in AVL\n");
    else            printf("  FAIL: Watermelon Sugar not found\n");

    if (s4 != NULL) printf("  PASS: Harry has As It Was in AVL\n");
    else            printf("  FAIL: As It Was not found\n");

    if (s5 != NULL) printf("  PASS: Liam has Strip That Down in AVL\n");
    else            printf("  FAIL: Strip That Down not found\n");

    if (s6 != NULL) printf("  PASS: Liam has Stack It Up in AVL\n");
    else            printf("  FAIL: Stack It Up not found\n");

    // What Makes You Beautiful in global AVL
    AVLNode* wmyb = find_avl(db.all_songs, "What Makes You Beautiful");
    if (wmyb != NULL) printf("  PASS: What Makes You Beautiful in global AVL\n");
    else              printf("  FAIL: What Makes You Beautiful not in global AVL\n");

    // check all 3 artists on What Makes You Beautiful
    int has_zayn = 0, has_harry = 0, has_liam = 0;
    ArtistList* al = wmyb->artists;
    while (al != NULL) {
        if (strcmp(al->name, "Zayn Malik")   == 0) has_zayn  = 1;
        if (strcmp(al->name, "Harry Styles") == 0) has_harry = 1;
        if (strcmp(al->name, "Liam Payne")   == 0) has_liam  = 1;
        al = al->next;
    }
    if (has_zayn)  printf("  PASS: What Makes You Beautiful has Zayn Malik\n");
    else           printf("  FAIL: Zayn Malik not linked to What Makes You Beautiful\n");
    if (has_harry) printf("  PASS: What Makes You Beautiful has Harry Styles\n");
    else           printf("  FAIL: Harry Styles not linked to What Makes You Beautiful\n");
    if (has_liam)  printf("  PASS: What Makes You Beautiful has Liam Payne\n");
    else           printf("  FAIL: Liam Payne not linked to What Makes You Beautiful\n");

    // Steal My Girl in global AVL
    AVLNode* smg = find_avl(db.all_songs, "Steal My Girl");
    if (smg != NULL) printf("  PASS: Steal My Girl in global AVL\n");
    else             printf("  FAIL: Steal My Girl not in global AVL\n");

    // check all 3 artists on Steal My Girl
    has_zayn = 0; has_harry = 0; has_liam = 0;
    al = smg->artists;
    while (al != NULL) {
        if (strcmp(al->name, "Zayn Malik")   == 0) has_zayn  = 1;
        if (strcmp(al->name, "Harry Styles") == 0) has_harry = 1;
        if (strcmp(al->name, "Liam Payne")   == 0) has_liam  = 1;
        al = al->next;
    }
    if (has_zayn)  printf("  PASS: Steal My Girl has Zayn Malik\n");
    else           printf("  FAIL: Zayn Malik not linked to Steal My Girl\n");
    if (has_harry) printf("  PASS: Steal My Girl has Harry Styles\n");
    else           printf("  FAIL: Harry Styles not linked to Steal My Girl\n");
    if (has_liam)  printf("  PASS: Steal My Girl has Liam Payne\n");
    else           printf("  FAIL: Liam Payne not linked to Steal My Girl\n");

    // print shared song artist lists
    printf("  What Makes You Beautiful (expect Zayn Malik, Harry Styles, Liam Payne):\n");
    ArtistList* wal = wmyb->artists;
    while (wal != NULL) {
        printf("    %s\n", wal->name);
        wal = wal->next;
    }

    printf("  Steal My Girl (expect Zayn Malik, Harry Styles, Liam Payne):\n");
    ArtistList* sal = smg->artists;
    while (sal != NULL) {
        printf("    %s\n", sal->name);
        sal = sal->next;
    }

    printf("  PASS: Proto2 free (no crash)\n\n");
}

void run_tests() {
    printf("         UNIT TESTS\n");
    printf("================================\n\n");
    test_proto1();
    test_proto2();
    printf("================================\n\n");
}