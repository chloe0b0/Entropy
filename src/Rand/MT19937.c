#include <stdio.h>
#include <stdlib.h>
#include <math.h>



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


typedef struct MT{
    unsigned long long state;
}MT19937;