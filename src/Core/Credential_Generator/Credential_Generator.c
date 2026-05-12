#include "../../../include/Core/Credential_Generator/Credential_Generator.h"
#include "random/random.h"
#include "file/file.h"
#include <stdlib.h>
#include<stdio.h>
#include <ctype.h>

//Generates random phrase

char* Generate_Random_Phrase(char file_path[512], int phrase_length) {

char phrase = calloc(phrase_length, 2048);

int current_word_size;
for (int x = 0; x < phrase_length; x++) {
    
    //Allocates space for our phrase buffer
    char phrase_buffer = get_random_UTF8_file_line(file_path);


    int whitespace_counter = 0;
    //Looks for the end of the line in our phrase buffer
    for (int y = 0; y < 2048; y++) {

        if (isspace(phrase_buffer[&y])) {
            whitespace_counter++;
        } else {
            whitespace_counter = 0;
        }

        if (whitespace_counter > 10) {
            current_word_size = y;
        }
    }
    //Trims our phrase buffer to size

    //Appends our phrase buffer to our finished phrase

    //Frees memory.
}

//Trims our finished phrase to size

//returns our finished phrase

}


