/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
template<class T, class Measure>
Measure ConstLapackVector<T,Measure>::dot(const ConstLapackVector<T,Measure>& rhs) const {
  if (shape(0) != rhs.shape(0)) throw ArrayShape::ShapeErr();
  Measure m = 0.0;
  for(int j = 0; j < shape(0); j++) {
    m += (*this)(j) * rhs(j);
  }
  return m;
}

template<class Rep, class Measure>
Measure dot(const LapackArithmetic<Rep,Measure>& rhs) const {
  // Inner product as sum of dot products rows of "this" with cols of rhs.
  // For Nx1 matrices, this is usual dot product.
  // For NxM matrices with "this" == rhs, this is Frobienus norm squared.
  // Implicit transpose of "this": cols of "this" dotted into cols of rhs.
  if (shape(1) != rhs.shape(1)) throw ArrayShape::ShapeErr();
  Measure m = 0.0;
  for(int i = 0; i < shape(1); i++) {
    for(int j = 0; j < shape(0); j++) {
      m += (*this)(i,j) * rhs(i,j);
    }
  }
  return m;
}
