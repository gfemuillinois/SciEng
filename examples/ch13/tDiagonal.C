/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>
#include "Array/FormedArray2d.h"

#include "Array/Array2d.h"
#include "Array/Array1d.h"
#include "SciEng/utils.h"

template<class T>
class DiagonalOfArray2d :
  public Array1d<T>       {
public:
  DiagonalOfArray2d(Array2d<T>& a) : the_array(a) {}
  virtual Subscript shape(Dimension) const { return min(the_array.shape(0), the_array.shape(1)); }
  virtual const T&  operator()(Subscript i) const { return the_array(i,i); }
  virtual       T&  operator()(Subscript i)       { return the_array(i,i); }
  DiagonalOfArray2d<T>& operator=(const T& rhs)                    { Array1d<T>::operator=(rhs); return *this; }
  DiagonalOfArray2d<T>& operator=(const ConstArray1d<T>& rhs)      { Array1d<T>::operator=(rhs); return *this; }
  DiagonalOfArray2d<T>& operator=(const DiagonalOfArray2d<T>& rhs) { Array1d<T>::operator=(rhs); return *this; }
private:
  Array2d<T>& the_array;
};


template<class T>
void set_to_identity(Array2d<T>& a) {
    a = T(0);
    DiagonalOfArray2d<T> d(a);
    d = T(1);
}


int
main() {
  FormedArray2d<int> a(5, 4);
  a = 3;
  DiagonalOfArray2d<int> d(a);
  d = 1;
  cout << "Diagonal is " << d << endl << "Matrix is " << a << endl;
  set_to_identity(a);
  cout << "Identity is " << a << endl;
  return 0;
}
