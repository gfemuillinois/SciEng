// Dummy file to create the template instance

#ifdef NO_IMPLICIT_TEMPLATE

#include "Array/Array1d.h"
#include "Array/Array2d.h"
#include "Array/Array3d.h"
#include "Array/FormedArray2d.h"

#include "average.h"


template class FormedArray2d<float>;

template class FormedArray2d<double>;

template class ConcreteFormedArray2d<double>;

template class ConcreteFormedArray2d<float>;

template  FormedArray2d<float>::EltT 
average< FormedArray2d<float> >( const FormedArray2d<float> &);

template float sum<float>( Array2d<float> const &);

template FormedArray2d<double>::EltT  
average< FormedArray2d<double> >( const FormedArray2d<double> &);

template double sum<double>( Array2d<double> const &);

template Array2dWithTypedef<int>::EltT 
average< Array2dWithTypedef<int> >( const Array2dWithTypedef<int> &);

template istream & operator>><double>(istream &, Array2d<double> &);

#endif
