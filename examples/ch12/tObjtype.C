/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Array/RigidArray.h"

int main() {

const int nrows = 3;
RigidArray2d<int, nrows, 2*nrows> b;
RigidArray2d<int, 3, 6> b_too;

return 0;
}
