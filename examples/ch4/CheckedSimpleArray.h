/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
// WARNING:
//  An altered copy of this class is used in intrcat.  Be sure to 
//  keep them in sync.


class SubscriptRangeError {
public:
    SubscriptRangeError(int i);
    int badSubscript();
private:
    int subscript;
};

class ArraySizeError {
public:
    ArraySizeError(int n);
    int badSize();
private:
    int size;
};

inline 
SubscriptRangeError::SubscriptRangeError(int i) :
  subscript(i) {}

inline
int SubscriptRangeError::badSubscript() {
  return subscript;
}

inline
ArraySizeError::ArraySizeError(int n) :
  size(n) {}

inline
int ArraySizeError::badSize() {
  return size;
}


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
#include "examples/ch4/CheckedSimpleArray.c"
#endif
