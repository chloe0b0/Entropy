#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
// Implementations of various Linear Feedback Shift Registers


// 16 bit Fibbonaci LFSR
typedef struct { uint16_t state, outputBit; }Fib16;

Fib16* Construct_Fib16(uint16_t seed){
    Fib16* fib16 = malloc( sizeof(Fib16) );

    fib16->state = seed;

    return fib16;
}


// Computes the period of a 16 bit fibbonaci LFSR
int Fib16Period(Fib16* lfsr){
    
}


int main(void){}