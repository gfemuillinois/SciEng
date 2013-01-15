/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef SimpleArrayH
#define SimpleArrayH

// Solution to exercise extending SimpleArray<T> by adding const members

template<class T> class SimpleArray;

template<class T>
class SimpleArray {
public:

    SimpleArray(int n);                                 // Create array of n elements
    SimpleArray();                                      // Create array of 0 elements
    SimpleArray(const SimpleArray<T>&);                 // Copy array
    ~SimpleArray();                                     // Destroy array
    T& operator[](int i);                               // Subscripting
    const T& operator[](int i) const;
    int numElts() const;                                // Number of elements
    SimpleArray<T>& operator=(const SimpleArray<T>&);   // Array assignment
    SimpleArray<T>& operator=(const T&);                // Scalar assignment 
    void setSize(int n);                                // Change size
private:
    int num_elts;                                       // Number of elements
    T* ptr_to_data;                                     // Pointer to built-in array of elements

    void copy(const SimpleArray<T>& a);                 // Copy in elements of a

};

#ifdef XLC_QNOTEMPINC
#include "examples/ch6/SimpleArray.cxx"
#endif

#endif
