/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef CheckedSimpleArrayH
#define CheckedSimpleArrayH

#include "examples/ch4/SimpleArray.h"


template<class T>
class CheckedSimpleArray :
    public SimpleArray<T> {
public:

    CheckedSimpleArray(int n);                    // Create array of n elements
    CheckedSimpleArray();                         // Create array of 0 elements

    T& operator[](int i);                         // Checked subscripting

    CheckedSimpleArray<T>& operator=(const T&);   // Scalar assignment

    class SubscriptRangeError {};

};


// Check for negative size left out on purpose, so inserting it
// could be an exercise.

template<class T>
inline
CheckedSimpleArray<T>::CheckedSimpleArray(int n) : SimpleArray<T>(n) {}

template<class T>
inline
CheckedSimpleArray<T>::CheckedSimpleArray() {}

template<class T>
inline
T& CheckedSimpleArray<T>::operator[](int i) {
    if (i < 0 || i >= numElts()) throw SubscriptRangeError();
    return SimpleArray<T>::operator[](i);
}

template<class T>
inline
CheckedSimpleArray<T>& CheckedSimpleArray<T>::operator=(const T& rhs) {
    SimpleArray<T>::operator=(rhs);
    return *this;
}

#endif
