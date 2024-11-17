#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1024

int main(int argc, char *argv[]) {
    FILE *fp;
    int occ = 0;      // Number of occurrences of the search string
    int count = 0;    // Line counter
    char *newline;    // Pointer to newline character in the string
    char fline[MAX];  // Buffer for each line in the file

    if (argc != 3) {
        printf("Usage: %s <filename> <search_string>\n", argv[0]);
        exit(1);
    }

    if (!(fp = fopen(argv[1], "r"))) {
        printf("Could not open file: %s\n", argv[1]);
        exit(1);
    }

    while (fgets(fline, MAX, fp) != NULL) {
        count++;
        if ((newline = strchr(fline, '\n'))) {
            *newline = '\0'; // Remove the newline character from the line
        }
        if (strstr(fline, argv[2]) != NULL) { // Check if search string is in the line
            printf("File: %s, Line: %d\n", argv[1], count);
            occ++;
        }
    }

    fclose(fp); // Close the file
    printf("Total occurrences: %d\n", occ);

    return 0;
}
