
#ifndef TDIAGONALH
#define TDIAGONALH

template<class T>
class DiagonalOfArray2d :
  public Array1d<T>       {
public:
  DiagonalOfArray2d( Array2d<T>& a) : the_array(a) {}
  virtual Subscript shape(Dimension) const { 
    return sce::min(the_array.shape(0), the_array.shape(1)); 
  }
  virtual const T&  operator()(Subscript i) const { 
    return the_array(i,i); 
  }
  virtual       T&  operator()(Subscript i)       { 
    return the_array(i,i); 
  }
  DiagonalOfArray2d<T>& operator=(const T& rhs)                    { 
    Array1d<T>::operator=(rhs); return *this; 
  }
  DiagonalOfArray2d<T>& operator=(const ConstArray1d<T>& rhs)      { 
    Array1d<T>::operator=(rhs); return *this; 
  }
  DiagonalOfArray2d<T>& operator=(const DiagonalOfArray2d<T>& rhs) { 
    Array1d<T>::operator=(rhs); return *this; 
  }
private:
  Array2d<T>& the_array;
};


template<class T>
void set_to_identity(Array2d<T>& a) {
    a = T(0);
    DiagonalOfArray2d<T> d(a);
    d = T(1);
}

#endif
