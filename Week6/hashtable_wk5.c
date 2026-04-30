#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable_wk5.h"

// here create a hash table with n buckets, each bucket being an empty list
HashTable create_hashtable(int n){
	HashTable newtable;
    newtable.size = n;

	// TODO: allocate memory for array and init lists
    newtable.table = malloc(n * sizeof(List));
    // Now, initialising every bucket to an empty list
    for (int i = 0; i < n; i++) {
        newtable.table[i] = new_list();
    }

	return newtable;
}
//
int hash(String key, int size){
	unsigned long h = 0; // unsigned long, so that when it wraps it's still positive
	int n = strlen(key);

	for (int i = 0; i < n; i++){
		// multiply by 32 (<<5) and add ascii value
		h = (h << 5) + (int)(key[i]);
	}
	return h%size;
}

void hash_insert(HashTable *self, String key){

	// 1. find the list to insert into using hash
     int index = hash(key, self->size);
	// 2. call list function to insert into that list
    insert_at_front(&(self->table[index]), key);
}
//it removes key
void hash_remove(HashTable *self, String key){
    int index = hash(key, self->size);
    delete_from_list(&(self->table[index]), key);
}
// it prints every bucket with its index
void hash_print(HashTable *self){
	for (int i = 0; i < self->size; i++){
		printf("%d: ", i);
		print_list(&(self->table[i]));
	}
}
// it destroys every bucket's list, then free the table array
void hash_destroy(HashTable *self){

    for (int i = 0; i < self->size; i++) {
        destroy_list(&(self->table[i]));
    }
    free(self->table);
    self->table = NULL;
    self->size  = 0;
}

void hash_adhoc_test(){
	int command = 1;
	HashTable table = create_hashtable(11);
	char buffer[100];

	printf("Commands:  1 <word> = insert   2 <word> = remove   3 = print   0 = quit\n\n");

	while (command){
		scanf("%d", &command);
		switch (command){
		case 1:
			scanf("%99s", buffer);
			hash_insert(&table, buffer);
			break;
		case 2: // TODO: remove
			scanf("%99s", buffer);
    		hash_remove(&table, buffer);
            break;
		case 3: // TODO: print
			hash_print(&table);
			break;
		}
		printf("\n");
	}
	hash_destroy(&table);
}