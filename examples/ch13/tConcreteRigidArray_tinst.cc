
// Dummy file to create the template instances.

#ifdef NO_IMPLICIT_TEMPLATE

#include "Array/ConcreteRigidArray1d.h"
#include "Array/ConcreteRigidArray2d.h"
#include "Array/ConcreteRigidArray3d.h"

template class ConcreteRigidArray1d<float, 5>;

template std::ostream & operator<<<float, 5>(std::ostream &, ConcreteRigidArray1d<float, 5> const &);

template class ConcreteRigidArray2d<float, 3, 4>;

template std::ostream & operator<<<float, 3, 4>(std::ostream &, ConcreteRigidArray2d<float, 3, 4> const &);

template class ConcreteRigidArray3d<int, 4, 3, 2>;

template std::ostream & operator<<<int, 4, 3, 2>(std::ostream &, ConcreteRigidArray3d<int, 4, 3, 2> const &);

template class ConcreteRigidArray2d<float, 5, 6>;

template class ConcreteRigidArray3d<int, 5, 6, 2>;


#endif
