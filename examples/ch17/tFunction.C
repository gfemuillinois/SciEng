/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <math.h>
#include <iostream.h>
#include "Function/Function.h"
#include "SciEng/String.h"

extern void aFunction(const IsoFunctional<double>& f) {
  double val = f(3.14);      
  cout << "tFunction gets " << val
       << " for sin(3.14)=" << sin(3.14) << endl;
}

int main() {
  {

  Function<double,double> aSin(sin);        // Capture sin.
  Functional<double,double>& aTrigF = aSin;
  // later in the same program ...
  double val = aTrigF(3.14);                // Call sin() through base class reference.

  }
  {


  IsoFunction<double> aSin(sin);        // Capture sin;
  IsoFunctional<double>& aTrigF=aSin;   // Ok    

  extern void aFunction(const IsoFunctional<double>&);
  aFunction(aSin);                      // Will call sin() through base class.


  CheckedBuiltInIsoFunction<double> cSin(sin);
  cout << "tFunction gets " << cSin(3.14)
       << " for checked sin(3.14)=" << sin(3.14) << endl;
  }

  try {
    CheckedBuiltInIsoFunction<double> cZero(0);
    cout << "Zero checked " << endl;
    cout.flush();
    cout << "tFunction gets " << cZero(3.14)
      << " for checked sin(3.14)=" << sin(3.14) << endl;
  } catch(const SciEngErr& e) {
    cerr << e.message() << endl;
  }
  return 0;
}

