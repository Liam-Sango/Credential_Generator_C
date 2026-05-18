//Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <locale.h>  

#include "file.h"
#include "../random/random.h"


bool check_file_validity (char full_path[512]) {

//Checks for file presence
FILE *fileptr;
fileptr = fopen(full_path, "r");

if (fileptr == NULL) {
    return false;
}

//checks if file has data.
fseek(fileptr, 0, SEEK_END);
long int file_end = ftell(fileptr);

if (file_end <= 0) {
    fclose(fileptr);
    return false;
} else {
    fclose(fileptr);
    return true;
}

}

long int check_file_size (char full_path[512]) {

//Checks for file presence
FILE *fileptr;
fileptr = fopen(full_path, "r");

if (fileptr == NULL) {
    long int err = 0;
    return err;
}

//Finds and return file size.
fseek(fileptr, 0, SEEK_END);
long int file_end = ftell(fileptr);

return file_end;

}

char* get_random_UTF8_file_line (char full_path[512]) {

    FILE *fileptr = fopen(full_path, "r");
    if (fileptr == NULL) return NULL;

    fseek(fileptr, 0, SEEK_END);
    long int file_size = ftell(fileptr);
    if (file_size <= 0) { fclose(fileptr); return NULL; }

    unsigned long long int random_line_num = Generate_random_number(0, file_size);
    fseek(fileptr, random_line_num, SEEK_SET);

    if (random_line_num > 0) {
        int c;
        while ((c = fgetc(fileptr)) != EOF && c != '\n');
        if (c == EOF) fseek(fileptr, 0, SEEK_SET);
    }

    char* output = calloc(2048, 1);
    if (output == NULL) { fclose(fileptr); return NULL; }

    if (fgets(output, 2048, fileptr) == NULL) {
        fseek(fileptr, 0, SEEK_SET);
        if (fgets(output, 2048, fileptr) == NULL) {
            free(output);
            fclose(fileptr);
            return NULL;
        }
    }

    size_t len = strlen(output);
    while (len > 0 && (output[len - 1] == '\n' || output[len - 1] == '\r')) {
        output[--len] = '\0';
    }

    fclose(fileptr);
    return output;
}

