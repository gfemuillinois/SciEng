/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>

#include "LapackWrap/Lapack.h"
#include "LapackWrap/RectSVDRep.h"

using std::cout;
using std::cin;
using std::endl;


// 1 + x + x^2 + x^3 = \sum_{l=0}^{4} a_l P_l(x)
//  P_0(x) = 1                   P_1(x) = x
//  P_2(x) = (1/2)(3x^2 - 1)     P_3(x) = (1/2)(5x^3 - 3 x)
//  P_4 uses x^4 and should have a_4 \approx 0
//
//  (4/3) * P_0 + 1.6 * P_1 + (2/3) * P_2 + 0.4 * P_3 =
//  (4/3) - (2/3)*(1/2) = 1  Check.
//  1.6 x - 0.4(3/2) x = x   Check.
//  (2/3)(3/2) x^2 = x^2     Check
//  (0.4)(5/2) x^3 = x^3     Check.

int main() {
  // Fit 1 + x + x*x + x*x*x, x = 0, 10
  // to fourth order Legendre polynomial


  LapackUnfactored< RectSVDRep<double> >  P(11, 5);
  RectSVDRep<double>::Knowns1d y(11);

  for (int i = 0; i <= 10; i++) {  
    // Set up row i of matrix P_{il} = P_l(x_i)
    int isq = i * i;

    P(i, 0) = 1.0;
    P(i, 1) = i;
    P(i, 2) = 1.5 * isq - .5;
    P(i, 3) = i * (2.5 * isq - 1.5);
    P(i, 4) = .125 * (isq * (35 * isq - 30) + 3);


    // Compute the right-hand side y_i = i^3 + i^2 + i + 1
    y(i) = ((i+1) * i + 1) * i + 1;
}
  
  // Solve
  RectSVDRep<double>::Unknowns1d result(5);
  //  Should give: [4/3, 1.6, 2/3, 0.4, 0.0]
  cout << "Expected answer is [4/3, 1.6, 2/3, 0.4, 0.0]" << endl;
  cout << "Answer obtained is ";
  cout << P.factor().solve(result, y) << endl;


  return 0;
}

