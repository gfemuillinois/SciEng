/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>

#include "tmpl1.h"

using std::cout;
using std::cin;
using std::endl;

int main() {

  LapackRect<float> a(10,10);
  // ... fill a ...

  LapackRect<float> b(10, 1);
  // ... fill b ...

  FactoredLapackRect<float> factored_a = a.factor();
  factored_a.solve(b);                              // b now contains the solution

  try { 

    a(1, 2) = 3.1; // Exception thrown

  } 
  catch( ... ) { 
    cout << "Exception caught --> success" << endl;
    return 0;  // Exception caught --> success 
  }
  
  cout << "Exception not thrown --> bad news" << endl;

  return 1;    // Exception not thrown --> bad news
}

