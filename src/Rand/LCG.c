#include <stdio.h>
#include <stdlib.h>
#include <math.h> // fmod
#include <time.h> // Unix Time for seed values

// Implementation of the Linear Congruential Generator

/* LCF rand = LCG(m, a, c, X0);
   double random = yield(rand);

   where yield returns the current value, and computes the next X

   X_n+1 = (X_n*a + c) mod m

*/

// Borland C/C++ parameters
// https://en.wikipedia.org/wiki/Linear_congruential_generator
#define MOD 0x100000000 // 2^32
#define A 22695477
#define C 1

typedef struct{ double m, a, c, x; }LCG;

LCG* construct_LCG(double m, double a, double c, double X0){
    LCG *lcg = malloc( sizeof(LCG) );

    lcg->x = X0;
    lcg->m = m;
    lcg->a = a;
    lcg->c = c;

    return lcg;
} 

double yield(LCG* lcg){
    lcg->x = fmod( ( lcg->a * lcg->x + lcg->c ), lcg->m ); // X_n+1 = (aX_n + c) mod m

    return lcg->x;
}

// LARGE => small
// 1 / yield() ==> (0, 1)

 
int main(void){
    LCG *rand = construct_LCG(MOD, A, C, time(NULL));

    for (int i = 0; i < 10; ++i){
        printf("%.17g\n", yield(rand));
    }

}