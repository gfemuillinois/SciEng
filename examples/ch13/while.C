/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <math.h>
#include "SciEng/utils.h"


double FrobeniusNorm(double* array, int n) {
    double sumsq = 0.0;
    double scale = 1.0;
    double* end = array + n;
    for (double* cur = array; cur < end; cur++) {
        double absx = fabs(*cur);
        if (absx > scale) {
            sumsq = sqr(scale / absx) * sumsq + 1;
            	scale = absx;
        }
        else sumsq += sqr(absx / scale);
    }
    return scale * sqrt(sumsq);
}


#include <iostream.h>
int
main() {
  double m[2][3] = { {1, 2, 3}, 
		     {4, 5, 6} };
  cout << FrobeniusNorm(&m[0][0], 6) << endl;
  return 0;
}
