
#ifndef AVERAGEH
#define AVERAGEH

template<class T> T sum(const Array1d<T>&);
template<class T> T sum(const Array2d<T>&);
template<class T> T sum(const Array3d<T>&);



#if 0
template<class Array>
??? average(const Array& a) {
    ??? s = sum(a);
    return s / a.numElts();
}

template<class Array, class T>
T average(const Array& a) { // WRONG code
    T s = sum(a);
    return s / a.numElts();
}
#endif


template<class AnArray>
typename AnArray::EltT average(const AnArray& a) {
    typename AnArray::EltT s = sum(a);
    return s / a.numElts();
}

template<class T>
T sum(const Array2d<T>& a) {
  T s = 0;
  for (Subscript i = 0; i < a.shape(0); i++)
    for (Subscript j = 0; j < a.shape(1); j++) s += a(i,j);
  return s;
}

// ----------------------

///////////////////////////////////////////////////////////////////
// This part looks like Array2d in the book, but has the typedef added.
// WARNING: Keep this definition consistent with ArrayxD.C

template<class T>
class Array2dWithTypedef :
    public virtual ArrayShape {
public:
    typedef T EltT;
    // ...

    virtual Array2dWithTypedef<T>& operator=(const Array2dWithTypedef<T>& rhs)  = 0;
    virtual Array2dWithTypedef<T>& operator=(const T& rhs)                    = 0;

    virtual const T&    operator()(Subscript i, Subscript j) const = 0;
    virtual T&          operator()(Subscript i, Subscript j)       = 0;

};

int sum(const Array2dWithTypedef<int>&);

///////////////////////////////////////////////////////////////////

#endif
