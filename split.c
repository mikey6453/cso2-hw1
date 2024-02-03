#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "split.h"

char **string_split(const char *input, const char *sep, int *num_words) {
    int capacity = 10; 
    char **words = malloc(capacity * sizeof(char *));
    *num_words = 0;
    const char *current = input;
    size_t len;
    char *word;

    while (*current) {
        current += strspn(current, sep); 
        if (!*current) break;

        len = strcspn(current, sep); 
        if (len > 0) {
            word = malloc(len + 1);
            strncpy(word, current, len);
            word[len] = '\0'; 

            if (*num_words >= capacity) {
                capacity *= 2;
                words = realloc(words, capacity * sizeof(char *));
            }
            words[*num_words] = word;
            (*num_words)++;
        }
        current += len;
    }

    if (*num_words == 0) { 
        free(words);
        return NULL;
    }

    words = realloc(words, *num_words * sizeof(char *));
    return words;
}