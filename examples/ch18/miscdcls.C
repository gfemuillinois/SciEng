/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

#include "clarch.h"


extern "C" int rand();// C random number generator

extern "C" {
    // ANSI C random number generator functions
    int rand();
    void srand(unsigned int seed);
}

/*
extern "C" {
#include "examples/ch18/myCfuncs.h"
}
*/

extern "C" double FTNAME(drand)();// Fortran random number generator


#include <iostream.h>

int main() {
  if ( FTNAME(drand)() != .5 ) {
    cerr << "Something wrong in call to Fortran dummy random routine" << endl;
    return 1;
  }
  return 0;
}
