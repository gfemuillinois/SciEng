/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
//#include <sstream>   // iso C++
//#include <strstream> // old C++
#include <iostream>

//namespace SciEngLib{

template<class T>
String& operator<<(String& s, const T& obj) {

  // CAD FIXME NOW!!
#if 0
  std::ostringstream os;
  //  ostrstream os;

  os << obj;
  char* p = os.str();      // Get pointer to string and "freeze" buffer
  s += String(p, os.pcount());
  os.rdbuf()->freeze(0);   // "Thaw" buffer so it will be deleted when os is destroyed
#else
  std::cerr << "\n**** String& operator<<(String& s, const T& obj) *****\n"
	    << "is broken..." << std::endl;

#endif

  return s;
}

//}
