#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <openssl/rand.h>
#include <openssl/err.h>

#include "../../include/Modules/random.h" 

int Generate_raw_random_bytes(int Gen_amt, unsigned char rand_buffer[Gen_amt]) {
    //Ensures cryptographic algorithms and error strings are available.
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();

    // Check if RNG is properly seeded
    if (RAND_poll() != 1) {
        return 1;
    }

    //Generates random bytes
    int result = RAND_bytes(rand_buffer, Gen_amt);
    return 0;
};

int Generate_random_number() {
    //Assigns variables
    unsigned char raw_buffer[4];
    unsigned int rand_num_arr[4];
    bool invalid_nums_present;
    int final_num;
    int status;

    // Loop until we generate a set of numbers with no zeros
    do {
        invalid_nums_present = false;
        
        // Generates random bytes
        status = Generate_raw_random_bytes(4, raw_buffer);

        // Check for generation failure
        if (status == 1) {
            return 1; 
        }

        // Converts the random bytes to an int array and checks for zeros
        for (int x = 0; x < 4; x++) {
            rand_num_arr[x] = raw_buffer[x];
            
            if (rand_num_arr[x] == 0) {
                invalid_nums_present = true;
                break; 
            }
        }
    } while (invalid_nums_present); 

    // Calculates the final number
    final_num = rand_num_arr[0] * rand_num_arr[1] * rand_num_arr[2] * rand_num_arr[3];

    return final_num;
}

//Generates a random number between a predefined range
int generate_random_number_range(int lower_limit, int upper_limit) {

};