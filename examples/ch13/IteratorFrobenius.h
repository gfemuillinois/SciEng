
#ifndef ITERATORFROBENIUSH
#define  ITERATORFROBENIUSH

#include <math.h>

template<class Array>
typename Array::EltT FrobeniusNorm(const Array& a) {
    typename Array::EltT sumsq = 0;
    typename Array::EltT scale = 1;
    for (typename Array::BrowserType i(a); i.more(); i.advance()) {
        typename Array::EltT absx = abs(i.current());
        if (absx > scale) {
            sumsq = sqr(scale / absx) * sumsq + 1;
            scale = absx;
        }
        else sumsq += sqr(absx / scale);
    }
    return scale * sqrt(sumsq);
}

#endif