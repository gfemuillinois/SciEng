/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <strstream>

//namespace SciEngLib{

template<class T>
String& operator<<(String& s, const T& obj) {
  ostrstream os;
  os << obj;
  char* p = os.str();      // Get pointer to string and "freeze" buffer
  s += String(p, os.pcount());
  os.rdbuf()->freeze(0);   // "Thaw" buffer so it will be deleted when os is destroyed
  return s;
}

//}
