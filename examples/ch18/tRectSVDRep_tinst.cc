
// Dummy file to create the template instances 

#ifdef NO_IMPLICIT_TEMPLATE

#include "LapackWrap/Lapack.h"
#include "LapackWrap/RectSVDRep.h"
#include "SciEng/SciEngErr.h"
#include "SciEng/String.h"

template class LapackUnfactored< RectSVDRep<float> >;

template class LapackFactored< RectSVDRep<float> >;

template String & operator<< <ConcreteBlas2d<float> >
(String &, ConcreteBlas2d<float> const &);

template std::ostream & operator<< <ConcreteColumnMajorSubscriptor<1>, float>
(std::ostream &, ConcreteArray1dConstRef<ConcreteColumnMajorSubscriptor<1>, float> const &);

template class ConcreteFortranArray1d<float>;

template class ConcreteFortranArray2d<float>;
#endif
