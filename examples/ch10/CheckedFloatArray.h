/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef CheckedFloatArrayH
#define CheckedFloatArrayH

#include "examples/ch4/SimpleFloatArray.h"


class CheckedFloatArray :
    public SimpleFloatArray {
public:

    CheckedFloatArray(int n);              // Create array of n elements
    CheckedFloatArray();                   // Create array of 0 elements

    float& operator[](int i);              // Checked subscripting

    CheckedFloatArray& operator=(float);   // Scalar assignment

    class SubscriptRangeError {};          // Exception thrown for bad subscript

};


// Check for negative size left out on purpose, so inserting it
// could be an exercise.
inline

CheckedFloatArray::CheckedFloatArray(int n) : SimpleFloatArray(n) {}


inline

CheckedFloatArray::CheckedFloatArray() {}


inline

float& CheckedFloatArray::operator[](int i) {
    if (i < 0 || i >= numElts()) throw SubscriptRangeError();
    return SimpleFloatArray::operator[](i);
}


inline

CheckedFloatArray& CheckedFloatArray::operator=(float rhs) {
    SimpleFloatArray::operator=(rhs);
    return *this;
}

#endif
