
#ifndef TCHECKEDSIMPLEARRAYH
#define TCHECKEDSIMPLEARRAYH

#include "examples/ch11/CheckedSimpleArray.h"

template<class T>
float average(SimpleArray<T>& a) {
    double sum = 0.0;
    for (int i = 0; i < a.numElts(); i++) sum += a[i];
    return sum / a.numElts();
}

#endif
