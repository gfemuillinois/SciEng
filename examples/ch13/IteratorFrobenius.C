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
#include "Array/ConcreteFormedArray1d.h"
#include "Array/ConcreteFormedArray2d.h"


template<class Array>
Array::EltT FrobeniusNorm(const Array& a) {
    Array::EltT sumsq = 0;
    Array::EltT scale = 1;
    for (Array::BrowserType i(a); i.more(); i.advance()) {
        Array::EltT absx = abs(i.current());
        if (absx > scale) {
            sumsq = sqr(scale / absx) * sumsq + 1;
            scale = absx;
        }
        else sumsq += sqr(absx / scale);
    }
    return scale * sqrt(sumsq);
}


int main() {
  ConcreteFormedArray1d<double> a1(3);
  a1(0) = 2; a1(1) = 3; a1(2) = 4;
  if (float(FrobeniusNorm(a1)) != float(sqrt(29.0))) {
    cerr << "Bad result for 1d case, result = " << FrobeniusNorm(a1) << endl;
    return 1;
  }
  ConcreteFormedArray2d<double> a2(2, 2);
  a2(0,0) = 2; a2(0,1) = 3; a2(1,0) = 4; a2(1,1) = 1;
  if (float(FrobeniusNorm(a2)) != float(sqrt(30.0))) {
    cerr << "Bad result for 2d case, result = " << FrobeniusNorm(a2) << endl;
    return 1;
  }
  return 0;
}
