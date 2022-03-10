#include <stdio.h>
#include <stdlib.h>

// Implementation of the Mersenne Twister

/*
    Description:
        The Mersenne Twister algorithm is based on a matrix linear recurrence over a finite binary field F2. 
        The algorithm is a twisted generalised feedback shift register (twisted GFSR, or TGFSR) of rational normal form (TGFSR(R)), 
       with state bit reflection and tempering.

    Definitions:
        linear reccurence:
            A linear recurrence relation is an equation that relates a term in a sequence or a multidimensional array to previous terms using recursion.
            The use of the word linear refers to the fact that previous terms are arranged as a 1st degree polynomial in the recurrence relation.

            (from: https://brilliant.org/wiki/linear-recurrence-relations/?irclickid=whkU4swndxyIW6y0QtRW7X41UkGxCySqBTjMxk0&utm_medium=affiliates&utm_campaign=Linkbux&utm_source=Network&utm_content=1636940537968_ONLINE_TRACKING_LINK_Online%20Tracking%20Link&utm_term=&irgwc=1#:~:text=A%20linear%20recurrence%20relation%20is,polynomial%20in%20the%20recurrence%20relation.)

        Binary Field F2:
            In mathematics, a field is a set on which addition, subtraction, multiplication, and division are defined and behave as the corresponding operations on rational and real numbers do. 
            (from: https://en.wikipedia.org/wiki/Field_(mathematics))
        
        Linear Feedback Shift Register:
            a shift register whose input bit is a linear function of its previous state.
            (from: https://en.wikipedia.org/wiki/Linear-feedback_shift_register)

            example Python implementation of a Linear Feedback Shift Register:
                '''
                state = 1 << 15 | 1
                while True:
                    print( state & 1, end='')
                    newbit = (state ^ (state >> 3) ^ (state >> 12) ^ (state >> 14) ^ (state >> 15)) & 1
                    state = (state >> 1) | (newbit << 15) 
                '''

        Important Papers:

            GFSR: http://www.math.sci.hiroshima-u.ac.jp/m-mat/MT/ARTICLES/tgfsr3.pdf
            Merssene Twister: http://www.math.sci.hiroshima-u.ac.jp/m-mat/MT/ARTICLES/mt.pdf



        The Algorithm:


            The State of the generator is a vector (an array of longs)
            

*/

#define N 624 
#define M 397
#define F 69069

#define A 0x9908b0df // constant coefficients of the twist matrix

#define U_MASK 0x80000000 // upper w-r bits 
#define L_MASK 0x7fffffff // lower r bits

/* Tempering */
#define T_MASK_B 0x9d2c5680
#define T_MASK_C 0xefc60000

// If the MT struct is not seeded, this seed will be used (taken from the original paper C implementation)
#define CONSTANT_SEED 4357

typedef struct MT{
    unsigned long state[N];
    unsigned int index;
}MT19937;

// Seeds an MT19937 struct with an unsigned long
void seedMT(MT19937* mt, unsigned long seed){
    mt->state[0] = seed & 0xffffffff;
    for (mt->index = 1; mt->index < N; mt->index++){
        mt->state[mt->index] = (F * mt->state[mt->index - 1]) & 0xffffffff;
    }
}

// Generates a natural number in the interval [0, 2^w - 1]
unsigned long genMTNat(MT19937* mt){
    unsigned long y;
    unsigned long mag[2] = {0x0, A};
    
    if (mt->index >= N){
        // Check for seed
        // If not seeded, seed with some constant (The original paper uses the seed: 4357)
        if (mt->index == N + 1){ seedMT(mt, CONSTANT_SEED); }
        
        int kk = 0;
        
        for (; kk < N - M; kk++){
            y = (mt->state[kk] & U_MASK) | (mt->state[kk + 1] & L_MASK);
            mt->state[kk] = mt->state[kk + M] ^ (y >> 1) ^ mag[y & 0x1];
        }

        for (; kk < N - 1; kk++){
            y = (mt->state[kk] & U_MASK) | (mt->state[kk + 1] & L_MASK);
            mt->state[kk] = mt->state[kk + (M - N)] ^ (y >> 1) ^ mag[y & 0x1];
        }

        y = (mt->state[N - 1] & U_MASK) | (mt->state[0] & L_MASK);
        mt->state[N - 1] = mt->state[M - 1] ^ (y >> 1) ^ mag[y & 0x1];

        mt->index = 0;
    }

    y = mt->state[mt->index++];
    y ^= (y >> 11);
    y ^= (y << 7) & T_MASK_B;
    y ^= (y >> 15) & T_MASK_C;
    y ^= (y << 18);

    return y;
}

// Generates a real number in the interval [0, 1]
double genMTReal(MT19937* mt){
    return (double)(genMTNat(mt)) / (unsigned long)0xffffffff;
}

int main(void){
    MT19937 mt;
    seedMT(&mt, CONSTANT_SEED);

    int x;
    for (x = 0; x < 1000; ++x){
        printf("%5f ", genMTReal(&mt));
        if (x % 8 == 0){ printf("\n"); }
    }
}