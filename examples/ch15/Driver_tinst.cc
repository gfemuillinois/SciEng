
// Dummy file to create the template instances.

#ifdef NO_IMPLICIT_TEMPLATE

#include "LapackWrap/Lapack.h"
#include "LapackWrap/RectLURep.h"
#include "LapackWrap/SymPosDefPackedLURep.h"

#include "Driver.h"

template class LapackUnfactored< RectLURep<double> >;

template class ConcreteFortranArray2d<double>;

template class LapackUnfactored< SymPosDefPackedLURep<float> >;

template class ConcreteFortranArray2d<float>;

template  LapackUnfactored<RectLURep<double> > 
xForAxEqb<LapackUnfactored<RectLURep<double> >, double>
(LapackUnfactored<RectLURep<double> > &, ConcreteFortranArray2d<double> &);

template LapackUnfactored<RectLURep<float> > 
xForAxEqb<LapackUnfactored<SymPosDefPackedLURep<float> >, float>
(LapackUnfactored<SymPosDefPackedLURep<float> > &, ConcreteFortranArray2d<float> &);

template ostream & operator<< <double> (ostream &, ConstArray2d<double> const &);

template ostream & operator<< <float> (ostream &, ConstArray2d<float> const &);

#endif
