#ifndef __MT__H
#define __MT__H

#include <stdio.h>

#define N       624 

typedef struct{
    unsigned long state[N];
    unsigned int index;
}MT19937;

// Seeds an MT19937 struct with an unsigned long
void SeedMT(MT19937* mt, unsigned long seed);
// Generates a natural number in the interval [0, 2^w - 1]
unsigned long GenMTNat(MT19937*);
// Generates a real number in the interval [0, 1]
double GenMTReal(MT19937*);

#endif