/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Array/ArrayTuplize.h"

template<class T, Subscript n0>
std::ostream& 
operator<<(std::ostream& os, const ConcreteRigidArray1d<T, n0>& a) {
  return arrayTuplize(a, os);
}
