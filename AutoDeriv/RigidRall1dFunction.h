/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef RigidRall1dFunctionH
#define RigidRall1dFunctionH

#include "AutoDeriv/RigidRall1d.h"
#include "Vector/FormedArithmetic.h"
#include "SciEng/SciEngErr.h"
#include "Function/Function.h"

/* RigidRall1dFunction maps a vector of RigidRall1ds eg (x,y,z) to a */
/* RigidRall1d result, eg f(x,y,z) */

template<class T, Subscript nvars>
class RigidRall1dFunction :
   public CheckedFunction<Array1d< RigidRall1d<T,nvars> >, RigidRall1d<T,nvars> > {
public:
  RigidRall1dFunction( RigidRall1d<T,nvars> (*f)(const Array1d< RigidRall1d<T,nvars> >&) ) :
      CheckedFunction<Array1d< RigidRall1d<T,nvars> >, RigidRall1d<T,nvars> >(f){}
      
  RigidRall1dFunction(){}
  
  void operator=( RigidRall1d<T,nvars> (*f)(const Array1d< RigidRall1d<T,nvars> >&) ){
    CheckedFunction< Array1d< RigidRall1d<T,nvars> >, RigidRall1d<T,nvars> >::operator=(f);
  }
};

#endif
