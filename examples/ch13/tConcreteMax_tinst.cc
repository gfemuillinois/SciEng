
// Dummy file to create the template instances.

#ifdef NO_IMPLICIT_TEMPLATE


#include "Array/ConcreteFormedArray1d.h"
#include "Array/ConcreteFormedArray2d.h"
#include "Array/ConcreteFormedArray3d.h"
#include "Array/ConcreteRigidArray1d.h"
#include "Array/ConcreteRigidArray2d.h"
#include "Array/ConcreteFortranArray2d.h"

#include "SciEng/utils.h"

#include "tConcreteMax.h"

template class ConcreteRigidArray2d<float, 5, 6>;

template class ConcreteFortranArray2d<double>;

template class ConcreteFormedArray1d<float>;

template class ConcreteFormedArray2d<int>;

template class ConcreteFormedArray3d<int>;

template ConcreteFormedArray2d<int>::EltT 
maxArray2dElement<ConcreteFormedArray2d<int> >(ConcreteFormedArray2d<int> const &);

template ConcreteRigidArray2d<float, 5, 6>::EltT 
maxArray2dElement<ConcreteRigidArray2d<float, 5, 6> >(ConcreteRigidArray2d<float, 5, 6> const &);

template ConcreteFortranArray2d<double>::EltT 
maxArray2dElement<ConcreteFortranArray2d<double> >(ConcreteFortranArray2d<double> const &);

template int maxArray3dPlane<ConcreteFormedArray3d<int> >(ConcreteFormedArray3d<int> &);

template std::ostream & operator<< < ConcreteRowMajorSubscriptor<3>, int >
(std::ostream &, ConcreteArray3dConstRef<ConcreteRowMajorSubscriptor<3>, int> const &);

template std::ostream & operator<< <ConcreteRowMajorProjectionSubscriptor<1>, int>
(std::ostream &, ConcreteArray1dConstRef<ConcreteRowMajorProjectionSubscriptor<1>, int> const &);



template class ConcreteArrayProjection1d<ConcreteRowMajorSubscriptor<2>, int>;

template class ConcreteArray1dRef<ConcreteRowMajorProjectionSubscriptor<1>, int>;

template class ConcreteArray2dRef<ConcreteRowMajorSubscriptor<2>, int>;

template class ConcreteArray3dRef<ConcreteRowMajorSubscriptor<3>, int>;

#endif
