/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>


void f(int i) {
    cout << i << endl;
}

int main() {
  // wrong2.C:19: warning: `double' used for argument 1 of `f(int)'
  // wrong2.C:19: warning: overflow in implicit constant conversion

  // f(1.0e15);
    return 0;
}

