//Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <unicode/ustring.h>
#include <unicode/uchar.h>
#include <unicode/ustdio.h>

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

UChar* get_random_UTF8_file_line (char full_path[512]) {

    //Assigns the output variable
    UChar* file_line[2048] = calloc(2048, sizeof(UChar));

    if (file_line == NULL) {
        free(file_line);
        return NULL;
    }

    //opens the file
    UFILE *U_FILE_PTR = u_fopen(full_path, "r", NULL, "UTF8");
    if (U_FILE_PTR == NULL) {
        return NULL;
    }

    // Get the size of the target file
    FILE *fileptr = u_fgetfile(U_FILE_PTR);
    fseek(fileptr, 0, SEEK_END);
    long int file_size = ftell(fileptr);
    fseek(fileptr, 0, SEEK_SET);

     if (file_size <= 0) {
        u_fclose(U_FILE_PTR);
        return NULL;
    }
    
    // Generate random number
    unsigned long long int random_line_num = Generate_random_number(0, file_size);

    //Navigate to that part of the file
    u_fseek(U_FILE_PTR, (unsigned long long int)random_line_num, SEEK_SET);
    
    //opens the file
    u_fgets(*file_line, sizeof(file_line), U_FILE_PTR);


    //Converts the  line output to UTF8 FORMATTING
     UChar* output[2048] = calloc(2048, sizeof(UChar));
     int UTF_8_error_code;

     if (output == NULL) {
        fclose(U_FILE_PTR);
        free(file_line);
        free(output);
        return NULL;
    }

    u_strToUTF8 (output, 2048, NULL, file_line, -1, &UTF_8_error_code);

    fclose(U_FILE_PTR);
    free(file_line);
    return output;
}

