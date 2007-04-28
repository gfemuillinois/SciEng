#ifndef LAPACKWRAP
#define LAPACKWRAP

#include "SciEng/Subscript.h"
#include "LapackWrap/LapackSubroutines.h"

template<class T, Subscript n0, Subscript n1> class ConcreteRigidArray2d;
template<class T, Subscript n0> class ConcreteRigidArray1d;


namespace LapackWrap {

  // Factoring and solve general matrices
  template <class T, Subscript n0>
  bool factAndSolve(ConcreteRigidArray2d< T, n0,n0>&  A, 
		    const int prob_dim,
		    ConcreteRigidArray1d< T, n0>& rhs);

  // Eigenvalues and eigenvectors (if eigenVectors = true) of a symmetric matrix
  template <class T, Subscript n0>
  bool eigens(ConcreteRigidArray2d< T, n0,n0>&  A, const int prob_dim,
	      const bool eigenVectors,
	      ConcreteRigidArray1d< T, n0>& eigenValues);


}

#ifdef XLC_QNOTEMPINC
#include "LapackWrap/LapackWrap.c"
#endif

#endif
