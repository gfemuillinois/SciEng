/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
template<class M, class V, class S>
M VectorUnderMatrix<M,V,S>::outer_product(const VectorUnderMatrix<M,V,S>& rhs){
  Array1d<S>& lhs = *this;
  M m(lhs.numElts(), rhs.numElts());
  for(int i = 0; i < lhs.numElts(); i++){
    for(int j = 0; j < rhs.numElts(); j++){
      m(i,j) = lhs(i) * rhs(j);
    }
  }
}
