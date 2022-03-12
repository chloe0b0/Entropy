#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "MT19937.h"
#include "LCG.h"

int main(void){
    unsigned long long mod, inc, mult, seed;

    mod = 0x100000000;
    inc = 1;
    mult = 0x15A4E35;

    seed = time(NULL);

    LCG* lcg = ConstructLCG(mod, inc, mult, seed);
    
    for (int i = 0; i < 10; ++i){
        printf("%lu ", genLCG(lcg));
    }
}