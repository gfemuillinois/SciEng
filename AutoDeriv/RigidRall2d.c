/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

template<class T, Subscript nvars>
RigidArithmetic2d<T,nvars,nvars> RigidRall2d<T,nvars>::hessian() const {
  RigidArithmetic2d<T,nvars,nvars> result(nvars,nvars);
  for(int i = 0; i < nvars; i++){
    const RigidRall1d<T,nvars>& row_i = (AlgebraicParent::gradient())(i);
    for(int j = 0; j < nvars; j++) {
      result(i,j) = row_i.gradient()(j);
    }
  }
  return result;
}

template<class T, Subscript nvars>
RigidRall2d<T,nvars>::RigidRall2d(int i_th, const T&t) : 
  AlgebraicParent(Values(t, i_th, nvars), Gradients(nvars)) {
  // The gradient of the parent at (i_th) has been set to one, but we also need the gradient in
  // the value component at (i_th) to be set to one:
  gradient()(i_th) = 1.0;
}
