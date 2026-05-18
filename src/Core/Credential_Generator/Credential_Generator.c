#include "../../../include/Core/Credential_Generator/Credential_Generator.h"
#include "random/random.h"
#include "file/file.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<stdio.h>

//Generates random phrase
char* Generate_Random_Phrase(char file_path[512], int phrase_length) {
    char* phrase = calloc(phrase_length, 2048);

    for (int x = 0; x < phrase_length; x++) {
        char* phrase_buffer = get_random_UTF8_file_line(file_path);

        int current_word_size = 2047;
        int whitespace_counter = 0;
        for (int y = 0; y < 2048; y++) {
            if (isspace((unsigned char)phrase_buffer[y])) {
                whitespace_counter++;
            } else {
                whitespace_counter = 0;
            }

            if (whitespace_counter > 10) {
                current_word_size = y;
                break;
            }
        }
        phrase_buffer[current_word_size] = '\0';

        strcat(phrase, " ");
        strcat(phrase, phrase_buffer);
        free(phrase_buffer);
    }

    int current_phrase_size = 0;
    int phrase_strlen = strlen(phrase);
    int whitespace_counter = 0;
    for (int z = 0; z < phrase_strlen; z++) {
        if (isspace((unsigned char)phrase[z])) {
            whitespace_counter++;
        } else {
            whitespace_counter = 0;
        }

        if (whitespace_counter > 20) {
            current_phrase_size = z - 20;
            break;
        }
    }

    if (current_phrase_size == 0) {
        current_phrase_size = phrase_strlen;
    }

    phrase = realloc(phrase, current_phrase_size + 1);
    phrase[current_phrase_size] = '\0';
    return phrase;
}




