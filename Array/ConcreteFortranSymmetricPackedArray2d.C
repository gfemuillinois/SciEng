/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Array/ConcreteFortranSymmetricPackedArray2d.h"
#include "SciEng/ArrayErr.h"

FortranSymmetricPackedSubscriptor::FortranSymmetricPackedSubscriptor(const SubscriptArray<2>& s) : n(s(0)) {
  if (n != s(1)) throw ArrayErr::Symmetry();
}

void FortranSymmetricPackedSubscriptor::setShape(const SubscriptArray<2>& s) {
  n = s(0);
  if (n != s(1)) throw ArrayErr::Symmetry();
}


Subscript 
FortranSymmetricPackedSubscriptor::ProjectionT::
offset(const SubscriptArray<1>& s) const {
    if (d == 1) {  
        // Offset within column; columns stored contiguously
        Subscript i = s(0);
        return (i <= proj_sub) ? i : ( i*(i+1) - proj_sub*(proj_sub-1) ) / 2;
    }
    else {
        // Offset within row
        Subscript j = s(0);
        return (proj_sub <= j) ? ( j*(j+1) - proj_sub*(proj_sub-1) )/2 : j;
    }
}



FortranSymmetricPackedSubscriptor::ProjectionT::

ProjectionT(const FortranSymmetricPackedSubscriptor& shape, 
            Dimension projected_out, 
            Subscript s
           ) :

    proj_sub(s), d(projected_out), n(shape.shape(0)) {
}

