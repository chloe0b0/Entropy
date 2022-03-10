# Rand
Implementations of various pseudo-random number generators


## PRNG list
> 16 bit Fibbonaci Linear Feedback Shift Register
>
> Linear Congruential Generator
>
> MT19937 (Mersenne Twister)


## TODO
> Implement LFSR with arbitrary state size and taps
>
> Later implement the Diehard tests

## MT19937 usage
```c

#include <stdio.h>
#include <time.h>

#include "MT19937.h"

int main(void){
    MT19937 mt;
    seedMT(&mt, time(NULL)); // if the seed is not set manually, a pre-determined seed will be used (4357 by default)

    for (int i = 0; i < 10; ++i){
        printf("%5f ", genMTReal(&mt)); // generate real numbers in the interval [0, 1]
    }
    printf("\n");

    for (int i = 0; i < 10; ++i){
        printf("%lu ", genMTNat(&mt)); // generate natural numbers in the interval [0, 2^w - 1]
    }
}

```
