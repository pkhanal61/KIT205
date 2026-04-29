#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *String;

// function prototypes
void quicksort(String *a, int first, int last);
void swap(String *a, String *b);

int main() {
    int n;

    // it asks user for number of strings
    printf("Enter number of strings: ");
    scanf("%d", &n);

    // it allocates array of strings
    String *strings = malloc(n * sizeof(String));
    char buffer[100];  // holds up to 99 characters

    // read strings
    for (int i = 0; i < n; i++) {
        scanf("%99s", buffer);
        strings[i] = malloc(strlen(buffer) + 1);
        strcpy(strings[i], buffer);
    }

    // it prints before sorting which is the given file
    printf("\nBefore sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    // calling quicksort
    quicksort(strings, 0, n - 1);

    // it prints the actual data after sorting
    printf("\nAfter sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    // free memory
    for (int i = 0; i < n; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}

// swap two strings
void swap(String *a, String *b) {
    String temp = *a;
    *a = *b;
    *b = temp;
}

// applying quicksort function
void quicksort(String *a, int first, int last) {
    if (first < last) {
        int i = first;
        int j = last - 1;

        while (i <= j) {
            while (i < last && strcmp(a[i], a[last]) <= 0) {
                i++;
            }
            while (j >= first && strcmp(a[j], a[last]) > 0) {
                j--;
            }
            if (i < j) {
                swap(&a[i], &a[j]);
            }
        }

        // placing pivot in correct position
        swap(&a[i], &a[last]);

        // recursive calls
        quicksort(a, first, j);
        quicksort(a, i + 1, last);
    }
}