/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef MisMatchedSizeErrH
#define MisMatchedSizeErrH

#include "SciEng/SciEngErr.h"

class MisMatchedSizeErr :
  public SciEngErr {
public:
  MisMatchedSizeErr(int lhs_size, int rhs_size) :
    the_lhs_size(lhs_size),
    the_rhs_size(rhs_size) {
  }
  virtual String message() const;
private:
  int the_lhs_size;
  int the_rhs_size;
};

#endif
