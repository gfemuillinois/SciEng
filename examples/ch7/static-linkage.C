/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <complex>
typedef std::complex<double> Complex;



extern int a;            // Declaration, external linkage
//extern int b = 3;     // Definition,  external linkage, initialized to 3   
int b = 3;           // Definition,  external linkage, initialized to 3  

static int c(1);         // Definition,  internal linkage, initialized to 1   
int d;                   // Definition,  external linkage, initialized to 0   
extern Complex c1;       // Declaration, external linkage                      
Complex c2(1, 2);        // Definition,  external linkage, initialized to (1, 2) 
static Complex c3(3, 4); // Definition,  internal linkage, initialized to (3, 4) 



int main() {
  if (b != 3 || c != 1 || d != 0 || a != 1 || c1 != Complex(0,0)) return 1;
  return 0;
}



int a = 1;     // Definition, initialized to 1;
Complex c1;    // Definition, default constructor.


