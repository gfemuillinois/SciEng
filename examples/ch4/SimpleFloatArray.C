/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch4/SimpleFloatArray.h"

SimpleFloatArray::SimpleFloatArray(int n) {
    num_elts = n;
    ptr_to_data = new float[n];
}

SimpleFloatArray::SimpleFloatArray() {
    num_elts = 0;
    ptr_to_data = 0;
}


SimpleFloatArray::SimpleFloatArray(const SimpleFloatArray& a) {
    num_elts = a.num_elts;
    ptr_to_data = new float[num_elts];
    copy(a); // Copy a's elements
}

void SimpleFloatArray::copy(const SimpleFloatArray& a) {
    // Copy a's elements into the elements of *this
    float* p = ptr_to_data + num_elts;
    float* q = a.ptr_to_data + num_elts;
    while (p > ptr_to_data) *--p = *--q;
}


SimpleFloatArray::~SimpleFloatArray() {
    delete [] ptr_to_data;
}


float& SimpleFloatArray::operator[](int i) {
    return ptr_to_data[i];
}

int SimpleFloatArray::numElts() {
    return num_elts;
}


SimpleFloatArray& SimpleFloatArray::operator=(const SimpleFloatArray& rhs) {
    if ( ptr_to_data != rhs.ptr_to_data ) {
        setSize( rhs.num_elts );
        copy(rhs);
    }
    return *this;
}


void SimpleFloatArray::setSize(int n) {
    if (n != num_elts) {

        delete [] ptr_to_data;        // Delete old elements,
        num_elts = n;                 // set new count,
        ptr_to_data = new float[n];   // and allocate new elements

    }
}


SimpleFloatArray& SimpleFloatArray::operator=(float rhs) {
    float* p = ptr_to_data + num_elts;
    while (p > ptr_to_data) *--p = rhs;
    return *this;
}

