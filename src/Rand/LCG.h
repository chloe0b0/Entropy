#ifndef LCG_H_
#define LCG_H_

typedef struct { unsigned long long modulus, increment, multiplier, state; }LCG;

LCG* ConstructLCG(unsigned long long, unsigned long long, unsigned long long, unsigned long long);
void SeedLCG(LCG*, unsigned long long);
unsigned long long GenLCG(LCG*);

#endif