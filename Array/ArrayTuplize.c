/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>

template<class Array>
std::ostream& arrayTuplize(const Array& a, std::ostream& os) {
  os << std::endl << '[';
  Subscript last = a.shape(0) - 1;
  for (Subscript i = 0; i < last; i++) os << a[i] << ", ";
  return os << a[last] << ']';;
}
