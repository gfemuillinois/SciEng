/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef RigidRallEquationsH
#define RigidRallEquationsH

#include "AutoDeriv/DifferentiableEquations.h"
#include "AutoDeriv/RigidRall1dFunction.h"

/* RigidRallEquations represent simultaneous equations as an array of functions */

template<class T, Subscript nvars>
class RigidRallEquations :
  public virtual DifferentiableEquations<T>,
  public FormedArray1d< RigidRall1dFunction<T,nvars> > {
public:
  RigidRallEquations(int n_eqns)
     : FormedArray1d< RigidRall1dFunction<T,nvars> > (n_eqns){}
public:
  virtual void evaluateAt(const Array1d<T>& vars);
  virtual const Array2d<T>& jacobian() const{ return j; }
  virtual const Array1d<T>& value() const  { return v; }
  virtual Boolean converged_to(const T&) const;
private:
  RigidArray2d<T,nvars,nvars> j;
  RigidArray1d<T,nvars> v;
};
  

#ifdef XLC_QNOTEMPINC
#include "AutoDeriv/RigidRallEquations.c"
#endif

#endif
