/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "SciEng/utils.h"
#include "Array/InterfacedArray2d.h"

template<class Rep>
typename LapackUnfactored<Rep>::Unfactored* LapackUnfactored<Rep>::releaseControl() {
  checkValidity();
  valid = Boolean::IsFalse;
  return ap.releaseControl();
}

template<class Rep>
LapackFactored<Rep> LapackUnfactored<Rep>::factor() {
  checkValidity();
  valid = Boolean::IsFalse;
  typename Rep::Unfactored* fp = ap.releaseControl();
  return LapackFactored<Rep>(new typename Rep::Factored(fp));
}

template<class Rep>
LapackUnfactored<Rep>::LapackUnfactored(Subscript n1, Subscript n2) :
     ap(new typename Rep::Unfactored(n1, n2)), valid(Boolean::IsTrue) {
}

template<class Rep>
LapackUnfactored<Rep>::LapackUnfactored(const LapackUnfactored<Rep>& a):
     ap(new typename Rep::Unfactored(a.rep())), valid(Boolean::IsTrue) {
}

template<class Rep>
LapackUnfactored<Rep>::LapackUnfactored(const ConstArray2d<EltT>& a):
     ap(new typename Rep::Unfactored(a.shape(0), a.shape(1))), valid(Boolean::IsTrue) {
  *this = a;
}

template<class Rep>
LapackUnfactored<Rep>::LapackUnfactored(const ConcreteFortranArray2d<EltT>& a):
     ap(new typename Rep::Unfactored(a.shape(0), a.shape(1))), valid(Boolean::IsTrue) {
  *this = a;
}

template<class Rep>
Subscript LapackUnfactored<Rep>::shape(Dimension d) const { checkValidity(); return ap->shape(d); }

template<class Rep>
Dimension LapackUnfactored<Rep>::dim() const { checkValidity(); return 2; }

template<class Rep>
const typename LapackUnfactored<Rep>::EltT& LapackUnfactored<Rep>::operator()(Subscript s0, Subscript s1) const {
  checkValidity();
  return (*ap)(s0, s1);
}

template<class Rep>
typename LapackUnfactored<Rep>::EltT& LapackUnfactored<Rep>::operator()(Subscript s0, Subscript s1) {
  checkValidity();
  return (*ap)(s0, s1);
}

template<class Rep>
typename Array2d< typename LapackUnfactored<Rep>::EltT >::ConstProjectionT 
LapackUnfactored<Rep>::project(Subscript s, Dimension d) const {
  return new InterfacedConstArrayProjection1d< typename Rep::Unfactored >(rep().project(s, d));
}

template<class Rep>
typename Array2d< typename LapackUnfactored<Rep>::EltT >::ProjectionT 
LapackUnfactored<Rep>::project(Subscript s, Dimension d) {
  return new InterfacedArrayProjection1d< typename Rep::Unfactored >(rep().project(s, d));
}

template<class Rep>
void LapackUnfactored<Rep>::checkValidity() const {
  if (! valid) throw LapackErr::InvalidFactoredMatrixUse();
}

template<class Rep>
Array2d<typename LapackUnfactored<Rep>::EltT>& LapackUnfactored<Rep>::operator=(const EltT& rhs) {
  checkValidity();   //  Must be unfactored; once factored we do not know the size.
  *ap = rhs;
  return *this;
}

template<class Rep>
Array2d<typename LapackUnfactored<Rep>::EltT>& LapackUnfactored<Rep>::operator=(const LapackUnfactored<Rep>& rhs) {
  if (!valid) {  // then we are loading a new unfactored, allocate for it.
    ap = new typename Rep::Unfactored(rhs.rep());
  } else {       // We are over-writing, use assignment rules of Rep.
    *ap = rhs.rep();  // rep() checks validity
  }
  valid = Boolean::IsTrue;
  return *this;
}

template<class Rep>
Array2d<typename LapackUnfactored<Rep>::EltT>& LapackUnfactored<Rep>::operator=(const ConstArray2d<EltT>& rhs) {
  if (!valid) {
    ap = new typename Rep::Unfactored(rhs.shape(0), rhs.shape(1));
  }
  typename Rep::Unfactored& lhs = *ap;
  if (lhs.shape(0) != rhs.shape(0) || lhs.shape(1) != rhs.shape(1)) throw ArrayErr::Shape();
  typename Array2d< EltT >::IteratorType lhs_i(*this);
  typename ConstArray2d<EltT>::BrowserType rhs_i(rhs);
  for (; lhs_i.more(); lhs_i.advance(), rhs_i.advance()) lhs_i.current() = rhs_i.current();
  valid = Boolean::IsTrue;
  return *this;
}

template<class Rep>
Array2d<typename LapackUnfactored<Rep>::EltT>& LapackUnfactored<Rep>::operator=(const ConcreteFortranArray2d<EltT>& rhs) {
  if (!valid) {
    ap = new typename Rep::Unfactored(rhs.shape(0), rhs.shape(1));
  }
  typename Rep::Unfactored& lhs = *ap;
  if (lhs.shape(0) != rhs.shape(0)) throw ArrayErr::Shape();
  for (Subscript i = 0; i < lhs.shape(0); i++) concreteCopy(lhs[i], rhs[i]);
  valid = Boolean::IsTrue;
  return *this;
}

template<class Rep>
typename LapackFactored<Rep>::Unknowns1d& LapackFactored<Rep>::solve(LapackFactored<Rep>::Unknowns1d& b) {
  ap->solve(b);
  return b;
}

template<class Rep>
typename LapackFactored<Rep>::Unknowns1d&
LapackFactored<Rep>::solve(typename LapackFactored<Rep>::Unknowns1d& x,const LapackFactored<Rep>::Knowns1d& b) {
  ap->solve(x,b);
  return x;
}

template<class Rep>
typename LapackFactored<Rep>::Unknowns2d& LapackFactored<Rep>::solve(LapackFactored<Rep>::Unknowns2d& b) {
  ap->solve(b);
  return b;
}

template<class Rep>
typename LapackFactored<Rep>::Unknowns2d&
LapackFactored<Rep>::solve(typename LapackFactored<Rep>::Unknowns2d& x,const LapackFactored<Rep>::Knowns2d& b) {
  ap->solve(x,b);
  return x;
}
