/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
template<class Rep>
AugmentedLapackUnfactored<Rep>::
AugmentedLapackUnfactored(Subscript nrows, Subscript ncols):
  LapackUnfactored<Rep>(nrows,ncols),
  bp(new Rep::Unfactored(nrows,1)){
}

template<class Rep>
AugmentedLapackUnfactored<Rep>::
AugmentedLapackUnfactored(const ConstArray2d<EltT>& a, const ConstArray2d<EltT>& b) :
  LapackUnfactored<Rep>(a),
  bp(new Rep::Unfactored(b)){
}

template<class Rep>
Array<AugmentedLapackUnfactored<Rep>::EltT>& AugmentedLapackUnfactored<Rep>::solve(Unknowns& x){
  factor().solve(x,*bp);
  return x;
}

template<class Rep>
Array<AugmentedLapackUnfactored<Rep>::EltT>& AugmentedLapackUnfactored<Rep>::solve(Array1d<EltT>& x){
  //factor().solve(*bp,x);
  Unknowns x_tmp(x.numElts(),1);
  x_tmp.project(0,1) = x;
  solve(x_tmp);
  return x = x_tmp.project(0,1);  // assumes a 2d Rep, specialize template for 1d reps.
}
