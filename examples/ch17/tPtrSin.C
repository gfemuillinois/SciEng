/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "SciEng/utils.h"
#include <math.h>
#include <iostream.h>



extern double sin(double);
extern float  sin(float);



float sin(float x) { return sin( double(x) ); }

main(){
{

double (*my_trig)(double);

}


typedef double (*TrigFncPtr)(double);



typedef float (*FltTrigFncPtr)(float);
FltTrigFncPtr your_trig = sin;



typedef float (*IntTrigFncPtr)(int);

#if 0 
IntTrigFncPtr int_trig     = sin;   // WRONG: No exact match on argument types
#endif 
typedef double (*MixedTrigFncPtr)(float);
#if 0 
MixedTrigFncPtr mixed_trig = sin;   // WRONG: Mismatch on return type


#endif


TrigFncPtr my_trig = sin;



double trig_val;

trig_val = (*my_trig)(1.0);   // Call using indirection operator
if (trig_val != sin(1.0)) return 1;
trig_val = my_trig(2.0);      // Call without using indirection operator
if (trig_val != sin(2.0)) return 1;





    TrigFncPtr sqr_as_trig = sqr;        // Expands double sqr(double).
    your_trig = sqr;                     // Expands float sqr(float).



  return 0;
}

