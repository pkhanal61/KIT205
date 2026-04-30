#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_wk5.h"

//TODO: change data type to char*

List new_list() {
	List temp;
	temp.head = NULL;
	return temp;
}

// after changing to char*:
// Used %s instead of %d
void print_list(List *self) {
	ListNodePtr current = self->head;
	while (current != NULL) {
		printf("%s", current->data);  // before it was printf("%d", ...)
		current = current->next;

		if (current != NULL)
			printf(", ");
	}
	printf("\n");
}

// after changing to char*:
// -- check how long data parameter is (strlen)
void insert_at_front(List *self, char *data) {
	ListNodePtr new_node = malloc(sizeof *new_node);
 // allocating and copying the string (was: new_node->data = data)
	new_node->data = malloc(strlen(data) + 1);
    strcpy(new_node->data, data);

	new_node->next = self->head;
	self->head = new_node;
}

// after changing to char*:
// -- change test in if statement to string compare (strcmp)
// -- free current->data (memory allocated for string) before freeing current
void delete_from_list(List *self, char *data) {
	ListNodePtr current = self->head;
	ListNodePtr prev = NULL;

	while (current != NULL) {
		if (strcmp(current->data, data) == 0)  { // before it was current->data == data
			if (prev == NULL) {        // front of list
				self->head = current->next;
                free(current->data);      // free the string first
				free(current);
				current = self->head;
			} else {                    // middle of list
				prev->next = current->next;
                free(current->data);      // free the string first
				free(current);
				current = prev->next;
			}
		} else {
			prev = current;
			current = current->next;
		}
	}
}

// after changing to char*:
// -- need to free memory allocated for string before freeing node
void destroy_list(List *self) {
	ListNodePtr current = self->head;
	while (current != NULL) {
		ListNodePtr to_free = current;

		current = current->next;
        free(to_free->data);   // free the string first (was missing)
		free(to_free);
	}
	self->head = NULL;
}

// helper function
int front_is(List *self, String value) {
    if (self->head == NULL) return 0;
    return strcmp(self->head->data, value) == 0;
}