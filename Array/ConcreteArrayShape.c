/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "SciEng/Boolean.h"

//namespace SciEngLib {

template<Dimension ndim>
ConcreteArrayShape<ndim>::ConcreteArrayShape(const SubscriptArray<ndim>& sa) :
    the_shape(sa) {
}


template<Dimension ndim>
ConcreteColumnMajorSubscriptor<ndim>::ConcreteColumnMajorSubscriptor(const SubscriptArray<ndim>& sa) :
    ConcreteArrayShape<ndim>(sa) {
}

template<Dimension ndim>
ConcreteRowMajorSubscriptor<ndim>::ConcreteRowMajorSubscriptor(const SubscriptArray<ndim>& sa) :
    ConcreteArrayShape<ndim>(sa) {
}
                                   
                                   
template<Dimension ndim>
void ConcreteArrayShape<ndim>::setShape(const SubscriptArray<ndim>& a) { 
    the_shape = a;
}

template<Dimension ndim>
Subscript ConcreteArrayShape<ndim>::numElts() const {
    Subscript n = the_shape(0);
    for (Dimension d = 1; d < ndim; d++) n *= the_shape(d);
    return n;
}

template<Dimension ndim>
Subscript ConcreteStrides<ndim>::stride(Dimension d) const {
  return the_strides(d);
}


template<Dimension ndim>
ConcreteColumnMajorProjectionSubscriptor<ndim-1>
ConcreteColumnMajorSubscriptor<ndim>::projectionSubscriptor(Dimension proj_dim, Subscript) const { 

    SubscriptArray<ndim-1> proj_shape;     // Shape of projection
    SubscriptArray<ndim-1> proj_strides;   // Strides of projection
    SubscriptArray<ndim>   step;           // Holds subscripts into array



    Dimension j = 0;    // Dimension in projection
    Dimension k = 0;    // Corresponding dimension in array
    step = 0;           // Will be set to take one "step" in dimension k

    while (j < ndim-1) {

        if (j == proj_dim) ++k;           // Skip over projected dimension
        proj_shape(j) = shape(k);         // Proj shape is array shape without dimension proj_dim

                                          // Compute offset by taking a step in dimension k
        step(k) = 1;
        proj_strides(j) = offset(step);
        step(k) = 0;

        j++; 
        k++;

    }

    return ConcreteColumnMajorProjectionSubscriptor<ndim-1>(proj_shape, proj_strides);
}

ConcreteColumnMajorProjectionSubscriptor<1>
ConcreteColumnMajorSubscriptor<2>::projectionSubscriptor(Dimension proj_dim, Subscript) const { 

    SubscriptArray<1> proj_shape;     // Shape of projection
    SubscriptArray<1> proj_strides;   // Strides of projection
    SubscriptArray<2> step;           // Holds subscripts into array

    Dimension j = 0;    // Dimension in projection
    Dimension k = 0;    // Corresponding dimension in array
    step = 0;           // Will be set to take one "step" in dimension k

    if (j == proj_dim) ++k;           // Skip over projected dimension
    proj_shape(j) = shape(k);         // Proj shape is array shape without dimension proj_dim

                                          // Compute offset by taking a step in dimension k
    step(k) = 1;
    proj_strides(j) = offset(step);

    return ConcreteColumnMajorProjectionSubscriptor<1>(proj_shape, proj_strides);
}

template<Dimension ndim>
ConcreteRowMajorProjectionSubscriptor<ndim-1>
ConcreteRowMajorSubscriptor<ndim>::projectionSubscriptor(Dimension proj_dim, Subscript) const {

  // Looks the same as ColumnMajor, but call to offset() calls different code.
  SubscriptArray<ndim> one_step;
  SubscriptArray<ndim-1> proj_shape;
  SubscriptArray<ndim-1> proj_strides;
  one_step = 0;
  for (Dimension j = 0; j < ndim-1; j++){
    Dimension old_j = j + (j >= proj_dim);  // logical part skips over projected dimension.
    proj_shape(j) = shape(old_j);
    one_step(old_j) = 1;
    proj_strides(j) = offset(one_step);
    one_step(old_j) = 0;
  }
   return ConcreteRowMajorProjectionSubscriptor<ndim-1>(proj_shape, proj_strides);
}

ConcreteRowMajorProjectionSubscriptor<1>
ConcreteRowMajorSubscriptor<2>::projectionSubscriptor(Dimension proj_dim, Subscript) const {

  // Looks the same as ColumnMajor, but call to offset() calls different code.

  SubscriptArray<2> one_step;
  SubscriptArray<1> proj_shape;
  SubscriptArray<1> proj_strides;

  one_step = 0;
  Dimension j = 0;

  Dimension old_j = j + (j >= proj_dim);  // logical part skips over projected dimension.
  proj_shape(j) = shape(old_j);
  one_step(old_j) = 1;
  proj_strides(j) = offset(one_step);

  return ConcreteRowMajorProjectionSubscriptor<1>(proj_shape, proj_strides);
}


template<Dimension ndim>
ConcreteColumnMajorProjectionSubscriptor<ndim-1>
ConcreteColumnMajorProjectionSubscriptor<ndim>::projectionSubscriptor(Dimension proj_dim, Subscript) const {
  SubscriptArray<ndim-1> proj_shape;
  SubscriptArray<ndim-1> proj_strides;
  SubscriptArray<ndim> first;   // Offset of first may be non-zero for a projection.
  first = 0;
  SubscriptArray<ndim> second;
  second = 0;
  for (Dimension j = 0; j < ndim-1; j++){
    Dimension old_j = j + (j >= proj_dim);  // logical part skips over projected dimension.
    proj_shape(j) = shape(old_j);
    second(old_j) = 1;
    proj_strides(j) = offset(second) - offset(first);
    second(old_j) = 0;
  }
  return ConcreteColumnMajorProjectionSubscriptor<ndim-1>(proj_shape, proj_strides);
}

template<Dimension ndim>
ConcreteRowMajorProjectionSubscriptor<ndim-1>
ConcreteRowMajorProjectionSubscriptor<ndim>::projectionSubscriptor(Dimension proj_dim, Subscript) const {
  SubscriptArray<ndim-1> proj_shape;
  SubscriptArray<ndim-1> proj_strides;
  SubscriptArray<ndim> first;   // Offset of first may be non-zero for a projection.
  first = 0;
  SubscriptArray<ndim> second;
  second = 0;
  for (Dimension j = 0; j < ndim-1; j++){
    Dimension old_j = j + (j >= proj_dim);  // logical part skips over projected dimension.
    proj_shape(j) = shape(old_j);
    second(old_j) = 1;
    proj_strides(j) = offset(second) - offset(first);
    second(old_j) = 0;
  }
  return ConcreteRowMajorProjectionSubscriptor<ndim-1>(proj_shape, proj_strides);
}


template<Dimension ndim>
ConcreteColumnMajorProjectionSubscriptor<ndim>::
ConcreteColumnMajorProjectionSubscriptor( 
        const SubscriptArray<ndim>& the_shape, 
        const SubscriptArray<ndim>& the_strides
    ): 
    ConcreteArrayShape<ndim>(the_shape),
    ConcreteStrides<ndim>(the_strides) {
}


template<Dimension ndim>
ConcreteRowMajorProjectionSubscriptor<ndim>::
ConcreteRowMajorProjectionSubscriptor(const SubscriptArray<ndim>& the_shape, const SubscriptArray<ndim>& the_strides) :
  ConcreteArrayShape<ndim>(the_shape),
  ConcreteStrides<ndim>(the_strides) {
}

//#include "SciEng/Boolean.h"

template<class LHSArrayShape, class RHSArrayShape>
Boolean hasSameShapeAs(const LHSArrayShape& lhs, const RHSArrayShape& rhs) {
  if (lhs.dim() != rhs.dim()) return Boolean::IsFalse;
  for (Subscript n = lhs.dim() - 1; n < 0; n--) {
    if (lhs.shape(n) != rhs.shape(n)) return Boolean::IsFalse;
  }
  return Boolean::IsTrue;
}

//}
