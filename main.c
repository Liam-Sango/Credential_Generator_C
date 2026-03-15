#include <stdio.h>
#include <stdlib.h>

#include <openssl/rand.h>
#include <openssl/err.h>
#include <openssl/evp.h>

#include "include/Modules/random.h"


int main() {
    int amount_to_generate = 16; 

    unsigned char my_random_buffer[amount_to_generate];

    printf("Generating %d random bytes...\n", amount_to_generate);
    int status = Generate_raw_random_bytes(amount_to_generate, my_random_buffer);

    if (status == 0) {
        printf("Success! Here are your random bytes in hexadecimal format:\n");
        
        for (int i = 0; i < amount_to_generate; i++) {
            printf("%02x ", my_random_buffer[i]);
        }
        printf("\n");
    } else {
        printf("Error: Failed to generate random bytes.\n");
    }

    return 0;
}