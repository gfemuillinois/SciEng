/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
// WARNING:
//  This is an altered copy of the same class from classes.  Be sure to 
//  keep them in sync.

#ifndef CHECKEDSIMPLEARRAYH
#define CHECKEDSIMPLEARRAYH

#include "SciEng/SciEngErr.h"
#include "SciEng/String.h"


class SubscriptRangeError :
    public SciEngErr {
public:
    SubscriptRangeError(int i, int n) : subscript(i), array_size(n) {}
    virtual String message() const {
        String msg;
        msg << "Subscript (" << subscript << ") out of range; ";
        msg << "must be between 0 and " << array_size - 1;
        return msg;
    }
private:
    const int subscript;
    const int array_size;
};

class ArraySizeError :
    public SciEngErr {
public:
    ArraySizeError(int n) : size(n) {}
    virtual String message() const {
        String msg;
        msg << "Array size " << size << " specified; must be non-negative";
        return msg;
    }
private:
    int size;
};


template<class T>
class CheckedSimpleArray {
public:

    CheckedSimpleArray(int n);                                        // Create array of n elements
    CheckedSimpleArray();                                             // Create empty array
    CheckedSimpleArray(const CheckedSimpleArray<T>&);                 // Copy array
    ~CheckedSimpleArray();                                            // Destroy array
    T& operator[](int i);                                             // Subscripting
    int numElts();                                                    // Number of elements
    CheckedSimpleArray<T>& operator=(const CheckedSimpleArray<T>&);   // Array assignment
    CheckedSimpleArray<T>& operator=(T);                              // Scalar assignment 
    void setSize(int n);                                              // Change size
private:
    int num_elts;
    T* ptr_to_data;

    void copy(const CheckedSimpleArray<T>& a);                        // Copy in elements of a

};

#ifdef XLC_QNOTEMPINC
#include "examples/ch9/CheckedSimpleArray.c"
#endif

#endif
