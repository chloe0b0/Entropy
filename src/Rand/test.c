#include <stdio.h>
#include <time.h>

#include "MT19937.h"

int main(void){
    MT19937 mt;
    seedMT(&mt, time(NULL));

    for (int i = 0; i < 10; ++i){
        printf("%5f ", genMTReal(&mt));
    }
    printf("\n");

    for (int i = 0; i < 10; ++i){
        printf("%lu ", genMTNat(&mt));
    }
}