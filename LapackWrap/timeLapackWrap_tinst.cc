// Dummy file to create the template instances.

#ifdef NO_IMPLICIT_TEMPLATE

#include "LapackWrap/LapackWrap.h"
#include "Array/ConcreteRigidArray1d.h"
#include "Array/ConcreteRigidArray2d.h"


#define MAT_DIM 10

template std::ostream & 
operator<<<double, MAT_DIM>(std::ostream &, ConcreteRigidArray1d<double, MAT_DIM> const &);

template class ConcreteRigidArray1d< double, MAT_DIM>;

template class ConcreteRigidArray2d< double, MAT_DIM,MAT_DIM>;

namespace LapackWrap {

template bool factAndSolve<double, MAT_DIM>
(ConcreteRigidArray2d<double, MAT_DIM, MAT_DIM> &, int, ConcreteRigidArray1d<double, MAT_DIM> &);

}


#endif
