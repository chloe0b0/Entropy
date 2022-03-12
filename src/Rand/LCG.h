#ifndef LCG_H_
#define LCG_H_

#include <stdlib.h>

typedef struct LCG{ unsigned long long modulus, increment, multiplier, state; }LCG;

LCG* ConstructLCG(unsigned long long  modulus, unsigned long long  increment, unsigned long long  multiplier, unsigned long long seed){
    LCG* lcg = (LCG*) malloc( sizeof(LCG) );

    lcg->state = seed;

    lcg->modulus = modulus;
    lcg->increment = increment;
    lcg->multiplier = multiplier;

    return lcg;
}

void seedLCG(LCG* gen, unsigned long long seed){
    gen->state = seed;
}

unsigned long long genLCG(LCG* gen){
    unsigned int nextState = (gen->multiplier * gen->state + gen->increment) % gen->modulus;
    unsigned int currState = gen->state;

    gen->state = nextState;

    return currState;
}

#endif
