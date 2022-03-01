#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
// Implementations of various Linear Feedback Shift Registers


// 16 bit Fibbonaci LFSR
typedef struct { uint16_t state; }Fib16;

Fib16* Construct_Fib16(uint16_t seed){
    Fib16* fib16 = malloc( sizeof(Fib16) );

    fib16->state = seed;

    return fib16;
}

// Extracts the output bit of the LFSR
uint16_t Yield(Fib16* lfsr){
    uint16_t output_bit;

    output_bit = ((lfsr->state >> 0) ^ (lfsr->state >> 2) ^ (lfsr->state >> 3) ^ (lfsr->state >> 5)) & 1u;
    lfsr->state = (lfsr->state >> 1) | (output_bit << 15);
 
    return output_bit;
}

// Generate an unsigned integer with an LSFR
unsigned int GenerateUInt(Fib16* lfsr, int iterations){
    unsigned int x = 0;

    for (int i = 0; i < iterations; ++i){
        uint16_t bit = Yield(lfsr);
        x |= bit << i;
    }

    return x;
}


// Computes the period of a 16 bit fibbonaci LFSR
// Does not modify the state of the lfsr
int Fib16Period(Fib16* lfsr){
    int period = 0;
    uint16_t init_state, state, output_bit;
    init_state = lfsr->state;
    state = init_state;

    do{
        output_bit = ((state >> 0) ^ (state >> 2) ^ (state >> 3) ^ (state >> 5)) & 1u;
        state = (state >> 1) | (output_bit << 15);
        ++period;
    }while(state != init_state);

    return period;
}


int main(void){
    uint16_t seed = 0xACE1u;
    Fib16* lfsr = Construct_Fib16(seed);

    for (int i = 0; i < 100; ++i){
        unsigned int x = GenerateUInt(lfsr, 5);
        printf("%u, ", x);
    }
}