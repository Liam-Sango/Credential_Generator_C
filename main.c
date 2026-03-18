#include <stdio.h>
#include <stdlib.h>

#include <openssl/rand.h>
#include <openssl/err.h>
#include <openssl/evp.h>

#include "include/Modules/random.h"



int main() {  

    for (int i = 0; i < 10; i++) {
        int random_number = Generate_random_number();
         printf("%d\n", random_number);
    }
    
}