#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "src/Core/Credential_Generator/random/random.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <wordlist_path> <phrase_length>\n", argv[0]);
        return 1;
    }

    char* phrase = Generate_Random_Phrase(argv[1], atoi(argv[2]));
    if (!phrase) {
        printf("Failed to generate random phrase.\n");
        return 1;
    }
    printf("%s\n", phrase);
    free(phrase);
    return 0;
}
