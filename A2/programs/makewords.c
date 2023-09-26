#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* makewords(const char* input) {
    // calculate the maximum possible len of the result
    size_t maxLen = strlen(input) + 1;

    char* result = (char*)malloc(maxLen); // allocate memory for the result
    if (result == NULL) {
        fprintf(stderr, "ERROR: memory allocation failed in makewords.\n");
        exit(1);
    }

    result[0] = 'C';
    result[1] = 'h';
    result[2] = 'a';
    result[3] = 'n';
    result[4] = 'g';
    result[5] = 'e';
    result[6] = '\n';
    result[7] = 'M';
    result[8] = 'e';
    result[9] = '\n';

    // null-terminate the final spot in the result
    result[10] = '\0';

    return result;
}

int main() {
    // creates a 1024 byte buffer to store data, will this be enough memory to store data?
    char buffer[1024];

    // Read data from stdin and write it to stdout (standard output)
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        // pass data from the buffer to a function convert spaces to linebreaks
        char* result = makewords(buffer);
        fputs(result, stdout);
        free(result); // releases the memory allocated
    }

    return 0;
}