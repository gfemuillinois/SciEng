/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "SciEng/Boolean.h"
#include <cstring>
#include <iostream>

//namespace SciEngLib{

ostream& operator<<(ostream& s, Boolean b) {
  return s << (b ? "IsTrue" : "IsFalse");
}

istream& operator>>(istream& s, Boolean& b) {
  const size_t bufsize = 1 + sizeof("IsFalse");
  char inbuf[bufsize];
  s.width(int(bufsize));     // Set maximum # of characters to be read
  s >> inbuf;		      // Read character string (also resets width)
  if (strcmp(inbuf, "IsTrue") == 0)       b = Boolean::IsTrue;
  else if (strcmp(inbuf, "IsFalse") == 0) b = Boolean::IsFalse;
  else s.clear(ios::failbit);    // Indicate extraction failed
  return s;
}

//}
