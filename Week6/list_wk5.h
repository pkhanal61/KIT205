#pragma once
#include <string.h>

//TODO: change data type to char*
//String is just an alias for char* — makes the code easier to read
//Hint: use following typedef to make code clearer
typedef char* String;

typedef struct listNode {
	String data;     //before it was int
	struct listNode *next;
} *ListNodePtr;

typedef struct list {
	ListNodePtr head;
} List;


List new_list();

void print_list(List *self);

void insert_at_front(List *self, String data);

void delete_from_list(List *self, String data);

void destroy_list(List *self);


// helper for testing
int front_is(List *self, String value);