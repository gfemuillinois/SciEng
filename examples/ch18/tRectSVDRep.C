/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>
#include <cstdlib>
#include "LapackWrap/Lapack.h"
#include "LapackWrap/RectSVDRep.h"
#include "SciEng/SciEngErr.h"
#include "SciEng/String.h"

using std::cout;
using std::cin;
using std::endl;

// WARNING: the output of this program is included in the text.  Be careful changing it.

int main() {
  {

    // Example from Aki and Richards, Quantitative Seismology, 
    // Volume 2, Sections 12.3.1 and 12.3.2
    LapackUnfactored< RectSVDRep<float> > a(3, 3);

a(0,0) = 1;   a(0,1) = 1;   a(0,2) = 0;
a(1,0) = 0;   a(1,1) = 0;   a(1,2) = 1;
a(2,0) = 0;   a(2,1) = 0;   a(2,2) = -1;


    LapackFactored< RectSVDRep<float> > fa = a.factor();
    
    ConcreteBlas1d<float> b(3);
    b(0) = 1; b(1) = 2;  b(2) = 1;

    cout << "Expected answer is [0.5, 0.5, 0.5]" << endl;
    cout << "Answer obtained is ";
    cout << fa.solve(b) << endl;

  }

  {
    LapackUnfactored< RectSVDRep<float> > a(2, 2);
    a(0,0) = 2;  a(0,1) = 3;
    a(1,0) = 5;  a(1,1) = 6;
    
    LapackFactored< RectSVDRep<float> > fa = a.factor();
    
    ConcreteBlas2d<float> b(2, 2);
    b(0,0) = 4;  b(0,1) = 8;
    b(1,0) = 7;  b(1,1) = 14;
    
    String answer, expected_answer("[[-0.999999, -2], [2, 4]]");
    answer << fa.solve(b);
    if (answer != expected_answer) {
      cout << "Bad answer for second problem (?)" << endl;
      cout << "Answer obtained is " << answer << endl;
      cout << "Expected answer is " << expected_answer << endl;
      return EXIT_FAILURE;
    }
 }
  return EXIT_SUCCESS;
}
