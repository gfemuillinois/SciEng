
#ifndef TASGARRAYH
#define TASGARRAYH

#include <iostream>

#include "Algebra/AbelianSemiGroupCategory.h"
#include "Array/ConcreteFormedArray1d.h"


class AdditiveArray :
    public ConcreteFormedArray1d<double>,
    public AbelianSemiGroupCategory<AdditiveArray> {
public:
    AdditiveArray(Subscript n) : ConcreteFormedArray1d<double>(n) {}
    AdditiveArray(const AdditiveArray& a) : ConcreteFormedArray1d<double>(a) {}
    // ... other constructors and assignment operators

    // User must define for Abelian semigroup category
    AdditiveArray& operator+=(const AdditiveArray& rhs);
};

#endif
