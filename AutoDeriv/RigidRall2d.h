/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef RigidRall2dH
#define RigidRall2dH

#include "AutoDeriv/RigidRall1d.h"

// RigidRall2d is a Rall1d with a value component of a Rall1d and a gradient
// component of a vector of Rall1ds.  The value component holds the function value
// and gradient vector; the gradient component holds a vector, each component of
// the vector hold an element of the gradient and a vector forming one row of the Hessian.
// This format means the gradient is duplicated, but all of Rall1d is reused.
// The value and gradient member functions here return the appropriate objects, but
// the value and gradient operator on the base class return Rall1d and vectors of Rall1d's
// respectively.  In short, this second derivative is computed by placing Rall1d numbers
// into a Rall1d arthimetic.


template<class T, Subscript nvars>
class RigidRall2d :
    public Rall1d< 
      RigidRall1d<T, nvars>,
      RigidArithmetic1d< RigidRall1d<T, nvars >, nvars >
    > {
  public:
    typedef RigidRall1d<T, nvars> Values;
    
    typedef RigidArithmetic1d< RigidRall1d<T, nvars>, nvars > Gradients;
       
    typedef Rall1d< Values, Gradients > AlgebraicParent;
    
    RigidRall2d(){} // constant zero
    RigidRall2d(const T& t) : AlgebraicParent(t){} // constant
    RigidRall2d(int i_th, const T&t);  // i_th, t_th unit vector with value t
    RigidRall2d(const AlgebraicParent& r) : AlgebraicParent(r) {}
    
    T&       element_value()          {return AlgebraicParent::value().value();}
    const T& element_value() const    {return AlgebraicParent::value().value();}
    RigidArithmetic2d<T,nvars,nvars> hessian() const;
    
    RigidRall2d<T,nvars>& operator*=(double d){ 
      AlgebraicParent::operator*=( Values(d) ); return *this;
    }
    RigidRall2d<T,nvars>& operator/=(double d){ 
      AlgebraicParent::operator/=( Values(d) ); return *this;
    }
};

template<class T, Subscript nvars>
inline
ostream& operator<<(ostream& os, const RigidRall2d<T, nvars>& r) {
  const RigidRall2d<T, nvars>::AlgebraicParent& r_super = r;
  return os << r_super;
}

#ifdef XLC_QNOTEMPINC
#include "AutoDeriv/RigidRall2d.c"
#endif

#endif
