/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef DifferentiableEquationsH
#define DifferentiableEquationsH

#include "Array/Array1d.h"
#include "Array/Array2d.h"
#include "SciEng/Boolean.h"

template<class T>
class DifferentiableEquations {
public:
  virtual void  evaluateAt(const Array1d<T>&) = 0;
  virtual const Array2d<T>& jacobian() const =0;
  virtual const Array1d<T>& value() const =0;
  virtual Boolean converged_to(const T& limit) const = 0;
};

#endif
