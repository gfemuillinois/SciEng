
// Dummy file to create the template instances.

#ifdef NO_IMPLICIT_TEMPLATE

#include "LapackWrap/Lapack.h"
#include "LapackWrap/RectLURep.h"
#include "LapackWrap/SymPosDefPackedLURep.h"
#include "Array/ConcreteFormedArray2d.h"
#include "Array/ConcreteFortranArray3d.h"
#include "Array/ConcreteFormedArray3d.h"

#include "Driver.h"

template class ConcreteFortranArray1d<double>;
template class ConcreteFormedArray2d<double>;

template class LapackUnfactored< RectLURep<double> >;
template class LapackUnfactored< SymPosDefPackedLURep<float> >;

template class ConcreteFortranArray2d<double>;
template class ConcreteFortranArray2d<float>;
template class ConcreteFortranArray3d<double>;
template class ConcreteFormedArray3d<double>;


template  LapackUnfactored<RectLURep<double> > 
xForAxEqb<LapackUnfactored<RectLURep<double> >, double>
(LapackUnfactored<RectLURep<double> > &, ConcreteFortranArray2d<double> &);

template LapackUnfactored<RectLURep<float> > 
xForAxEqb<LapackUnfactored<SymPosDefPackedLURep<float> >, float>
(LapackUnfactored<SymPosDefPackedLURep<float> > &, ConcreteFortranArray2d<float> &);

template std::ostream & operator<< <double> (std::ostream &, ConstArray2d<double> const &);

template std::ostream & operator<< <float> (std::ostream &, ConstArray2d<float> const &);

template std::ostream & operator<<<ConcreteColumnMajorSubscriptor<2>, double>(std::ostream &, ConcreteArray2dConstRef<ConcreteColumnMajorSubscriptor<2>, double> const &);

template std::ostream & operator<<<ConcreteColumnMajorSubscriptor<2>, float>(std::ostream &, ConcreteArray2dConstRef<ConcreteColumnMajorSubscriptor<2>, float> const &);


template std::ostream & operator<<<ConcreteColumnMajorSubscriptor<1>, double>(std::ostream &, ConcreteArray1dConstRef<ConcreteColumnMajorSubscriptor<1>, double> const &);

template std::ostream & operator<<<ConcreteRowMajorSubscriptor<2>, double>(std::ostream &, ConcreteArray2dConstRef<ConcreteRowMajorSubscriptor<2>, double> const &);

template std::ostream & operator<<<ConcreteColumnMajorSubscriptor<3>, double>(std::ostream &, ConcreteArray3dConstRef<ConcreteColumnMajorSubscriptor<3>, double> const &);

template std::ostream & operator<<<ConcreteRowMajorSubscriptor<3>, double>(std::ostream &, ConcreteArray3dConstRef<ConcreteRowMajorSubscriptor<3>, double> const &);

#endif
