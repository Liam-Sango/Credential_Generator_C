#ifndef RANDOM_H
#define RANDOM_H

//Generates securely random raw bytes. (Without any conversion or processing)
int Generate_raw_random_bytes(int Gen_amt, unsigned char rand_buffer[Gen_amt]);

//generates a large random number
int Generate_random_number();

//Generates a random number between a predefined range
int generate_random_number_range(int lower_limit, int upper_limit);

#endif // RANDOM_H