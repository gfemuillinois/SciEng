/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef FormedRall1dH
#define FormedRall1dH

#include "AutoDeriv/Rall1d.h"
#include "Vector/FormedArithmetic.h"

/* FormedRall1ds are Rall numbers with FormedArithmetic1d gradient vectors */
template<class T>
class FormedRall1d :
  public Rall1d<T, FormedArithmetic1d<T> > {
public:
  FormedRall1d(){}
  FormedRall1d(const T& c, Subscript i_th, Subscript nvars) :
    Rall1d<T, FormedArithmetic1d<T> >(c, i_th, nvars) {
  }
  FormedRall1d(const Rall1d<T, FormedArithmetic1d<T> >& r):
        Rall1d<T, FormedArithmetic1d<T> >(r) {
  }
  void reshape(Subscript nvars) { gradient().reshape(0,nvars); }

};

#endif
