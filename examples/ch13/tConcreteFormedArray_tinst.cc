
// Dummy file to create the template instances.

#ifdef NO_IMPLICIT_TEMPLATE

#include "Array/ConcreteFortranArray1d.h"
#include "Array/ConcreteFortranArray2d.h"
#include "Array/ConcreteFortranArray3d.h"
#include "Array/ConcreteFormedArray1d.h"
#include "Array/ConcreteFormedArray3d.h"
#include "Array/ConcreteArray1d.h"

#include "Array/ConcreteArrayShape.h"

//template class SubscriptArray<1>;

//template class ConcreteArrayShape<1>;

//template class ConcreteRowMajorSubscriptor<1>;

template class ConcreteFortranArray1d<float>;

template class ConcreteFormedArray1d<double>;

template class ConcreteFormedArray3d<float>;

//template class ConcreteArray1d<ConcreteRowMajorSubscriptor<1>, double>;

template void ConcreteArray1d<ConcreteRowMajorSubscriptor<1>, double>::swap(ConcreteArray1d<ConcreteRowMajorSubscriptor<1>, double> &);

template class ConcreteFortranArray2d<float>;

template class ConcreteFortranArray3d<float>;

template std::ostream & operator<<<ConcreteColumnMajorSubscriptor<3>, float>
(std::ostream &, ConcreteArray3dConstRef<ConcreteColumnMajorSubscriptor<3>, float> const &);

template std::ostream & operator<<<ConcreteColumnMajorSubscriptor<2>, float>
(std::ostream &, ConcreteArray2dConstRef<ConcreteColumnMajorSubscriptor<2>, float> const &);

template std::ostream & operator<<<ConcreteColumnMajorSubscriptor<1>, float>
(std::ostream &, ConcreteArray1dConstRef<ConcreteColumnMajorSubscriptor<1>, float> const &);

template std::ostream & operator<<<ConcreteRowMajorSubscriptor<1>, double>(std::ostream &, ConcreteArray1dConstRef<ConcreteRowMajorSubscriptor<1>, double> const &);


template std::ostream & operator<<<ConcreteRowMajorSubscriptor<3>, float>(std::ostream &, ConcreteArray3dConstRef<ConcreteRowMajorSubscriptor<3>, float> const &);

template class ConcreteArray2dRef<ConcreteColumnMajorSubscriptor<2>, float>;

template class ConcreteArray3dRef<ConcreteColumnMajorSubscriptor<3>, float>;

template class ConcreteArrayProjection1d<ConcreteColumnMajorSubscriptor<2>, float>;

//template Subscript ConcreteRowMajorSubscriptor<1>::offset( const SubscriptArray<1>& s ) const;

//template class ConcreteArrayShape<1>;


#endif
