/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Vector/MisMatchedSizeErr.h"
#include "SciEng/String.h"

String MisMatchedSizeErr::message() const {
  String s;
  s << " MisMatchedSizeErr, left hand size is: " << the_lhs_size << "\n"; // endl;
  s << "                    right hand size is:" << the_rhs_size << "\n"; // endl;
  return s;
}
