/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>

template<class T, int m, int l, int t, int q, int k, int i, int a>
ostream& operator<<(ostream& os, const Physical<T, m, l, t, q, k, i, a>& p) {
  int units[7] = { m, l, t, q, k, i, a };
  os << p.value(); 
  return powerPrinter(os, units);
}
