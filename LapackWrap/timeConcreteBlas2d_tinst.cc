// Dummy file to create the template instances.

#ifdef NO_IMPLICIT_TEMPLATE

#include "LapackWrap/ConcreteBlas2d.h"
#include "LapackWrap/TransposedConcreteBlas2d.h"

template class ConcreteBlas2d<double>;

template class TransposedConcreteBlas2d<double>;

template class DistributingEquivalentCategory<ConcreteBlas2d<double> >;

template class ConcreteFortranArray2d<double>;

template class ConcreteFortranArray1d<double>;

template class ConcreteArrayShape<2>;

template void mult<double>
(ConcreteBlas2d<double> const &, ConcreteBlas2d<double> const &, ConcreteBlas2d<double> &);

template void mult<double>
(TransposedConcreteBlas2d<double> const &, TransposedConcreteBlas2d<double> const &, ConcreteBlas2d<double> &);

template void mult<double>
(ConcreteBlas2d<double> const &, TransposedConcreteBlas2d<double> const &, ConcreteBlas2d<double> &);

template void mult<double>
(ConcreteBlas2d<double> const &, ConcreteBlas1d<double> const &, ConcreteBlas1d<double> &);

template ConcreteBlas2d<double> operator*<double>
(TransposedConcreteBlas2d<double> const &, TransposedConcreteBlas2d<double> const &);

template ConcreteBlas2d<double> operator*<double>
(ConcreteBlas2d<double> const &, TransposedConcreteBlas2d<double> const &);

template ConcreteBlas1d<double> operator*<double>
(ConcreteBlas2d<double> const &, ConcreteBlas1d<double> const &);

#endif
