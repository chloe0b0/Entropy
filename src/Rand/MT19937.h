#ifndef __MT19937_H_
#define __MT19937_H

#define N 624 
#define M 397

typedef struct MT{
    unsigned long state[N];
    unsigned int index;
}MT19937;

void seedMT(MT19937* mt, unsigned long seed);
unsigned long genMTNat(MT19937* mt);
double genMTReal(MT19937* mt);

#endif