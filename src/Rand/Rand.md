# Rand
Implementations of various pseudo-random number generators


## PRNG list
> 16 bit Fibbonaci Linear Feedback Shift Register
>
> Linear Congruential Generator
>
> MT19937 (Mersenne Twister)


## TODO
> Later implement the Diehard tests

## MT19937 usage
```c

#include <stdio.h>
#include <time.h>

#include "MT19937.h"

int main(void){
    MT19937 mt;
    SeedMT(&mt, time(NULL)); // if the seed is not set manually, a pre-determined seed will be used (4357 by default)

    for (int i = 0; i < 10; ++i){
        printf("%5f ", GenMTReal(&mt)); // generate real numbers in the interval [0, 1]
    }
    printf("\n");

    for (int i = 0; i < 10; ++i){
        printf("%lu ", GenMTNat(&mt)); // generate natural numbers in the interval [0, 2^w - 1]
    }
}

```
## Linear Congruential Generator usage
```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "LCG.h"

int main(void){
    unsigned long long mod, inc, mult, seed;
    // Borland C/C++ parameters from https://en.wikipedia.org/wiki/Linear_congruential_generator
    mod = 0x100000000;
    inc = 1;
    mult = 0x15A4E35;

    seed = time(NULL);

    LCG* lcg = ConstructLCG(mod, inc, mult, seed);
    
    for (int i = 0; i < 10; ++i){
        printf("%lu ", GenLCG(lcg));
    }
}

```