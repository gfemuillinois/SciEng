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


template<class T>
CheckedSimpleArray<T>::CheckedSimpleArray(const int n) {
    if (n < 0) throw ArraySizeError(n);
    num_elts = n;
    ptr_to_data = new T[n];
    for(int i=0; i<num_elts; ++i)
      ptr_to_data[i] = T();
}

template<class T>
T& CheckedSimpleArray<T>::operator[](const int i) {
    if (i < 0 || i >= num_elts) throw SubscriptRangeError(i);
    return ptr_to_data[i];
}

template<class T>
void CheckedSimpleArray<T>::setSize(const int n) {
    if (n != num_elts) {

        if (n < 0) throw ArraySizeError(n);
        delete [] ptr_to_data;    // Delete old elements,
        num_elts = n;             // set new count,
        ptr_to_data = new T[n];   // and allocate new elements

    }
}


template<class T>
CheckedSimpleArray<T>::CheckedSimpleArray() {
    num_elts = 0;
    ptr_to_data = 0;
}

template<class T>
CheckedSimpleArray<T>::CheckedSimpleArray(const CheckedSimpleArray<T>& a) {
    num_elts = a.num_elts;
    ptr_to_data = new T[num_elts];
    copy(a); // Copy a's elements
}

template<class T>
CheckedSimpleArray<T>::~CheckedSimpleArray() {
    delete [] ptr_to_data;
}

template<class T>
int CheckedSimpleArray<T>::numElts() const {
    return num_elts;
}

template<class T>
void CheckedSimpleArray<T>::copy(const CheckedSimpleArray<T>& a) {
    // Copy a's elements into the elements of *this
    T* p = ptr_to_data + num_elts;
    T* q = a.ptr_to_data + num_elts;
    while (p > ptr_to_data) *--p = *--q;
}

template<class T>
CheckedSimpleArray<T>& CheckedSimpleArray<T>::operator=(const CheckedSimpleArray<T>& rhs) {
    if ( ptr_to_data != rhs.ptr_to_data ) {
        setSize( rhs.num_elts );
        copy(rhs);
    }
    return *this;
}

template<class T>
CheckedSimpleArray<T>& CheckedSimpleArray<T>::operator=(const T rhs) {
    T* p = ptr_to_data + num_elts;
    while (p > ptr_to_data) *--p = rhs;
    return *this;
}
