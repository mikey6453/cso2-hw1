#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "split.h"

int main(int argc, char *argv[]) {
    char sep[256] = " \t"; 
    if (argc > 1) {
        sep[0] = '\0'; 
        for (int i = 1; i < argc; i++) {
            strcat(sep, argv[i]);
        }
    }

    char line[4001];
    while (fgets(line, sizeof(line), stdin)) {
        if (strcmp(line, ".\n") == 0) break;

        line[strcspn(line, "\n")] = '\0'; 

        int size;
        char **result = string_split(line, sep, &size);

        for (int i = 0; i < size; i++) {
            printf("[%s]", result[i]);
            free(result[i]);
        }
        printf("\n");
        free(result);
    }

    return 0;
}