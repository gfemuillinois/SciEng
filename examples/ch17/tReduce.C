/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include<complex.h>


#include "Function/reduce.h"
#include "Function/IsoMemberReducer.h"
#include "Vector/FormedArithmetic.h"

//complex reduce( void (complex::*)(complex), const FormedArithmetic1d<complex>&);

main(){

  FormedArithmetic1d<complex> pa(40);
  pa=complex(1.0,1.0);
  complex sum = reduce(pa, complex::operator+=);

  if (sum != complex(40.0) * complex(1.0,1.0)) {
    cerr << "The sum of " << pa << " is NOT" << sum  << endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
