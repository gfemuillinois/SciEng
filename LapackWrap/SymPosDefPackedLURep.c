/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "SciEng/utils.h"
#include "LapackWrap/LapackSubroutines.h"

template<class T>
SymPosDefPackedLURep<T>::Factored::Factored(SymPosDefPackedLURep<T>::Unfactored* mp) : facmat_p(mp) {
  int info;  // info return from LAPACK factor routine.
  LapackSubroutines::xpptrf("Upper", mp->shape(0), &(*mp)(0,0), info);
  if (info != 0) throw LapackErr::NotPositiveDefinite(info);
}

template<class T>
void SymPosDefPackedLURep<T>::Factored::solve(ConcreteFortranArray2d<T>& b) {
  int info;  // info return from LAPACK solve routine.
  LapackSubroutines::xpptrs("Upper", facmat_p->shape(0), b.shape(1), &(*facmat_p)(0,0),
	 b.firstDatum(), b.shape(0), info);
  if (info != 0) throw LapackErr::UnableToSolve(info);
}

template<class T>
void SymPosDefPackedLURep<T>::Factored::solve(ConcreteFortranArray2d<T>& x, const ConcreteFortranArray2d<T>& b) {
  x = b;  // LAPACK overwrites for LU decompositions.
  solve(x);
}

template<class T>
void SymPosDefPackedLURep<T>::Factored::solve(ConcreteFortranArray1d<T>& b) {
  int info;  // info return from LAPACK solve routine.
  LapackSubroutines::xpptrs("Upper", facmat_p->shape(0), b.shape(1), &(*facmat_p)(0,0),
	 b.firstDatum(), b.shape(0), info);
  if (info != 0) throw LapackErr::UnableToSolve(info);
}

template<class T>
void SymPosDefPackedLURep<T>::Factored::solve(ConcreteFortranArray1d<T>& x, const ConcreteFortranArray1d<T>& b) {
  x = b;  // LAPACK overwrites for LU decompositions.
  solve(x);
}
