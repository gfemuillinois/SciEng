/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
template<class T>
ConcreteFortranSymmetricPackedArray2d<T>::
ConcreteFortranSymmetricPackedArray2d(Subscript s0, Subscript s1) :
   ConcreteArray2d<SubscriptorT, T>(SubscriptArray<2>(s0, s1), 0) {
   setSizeOnHeap((s0 * (s0 + 1)) / 2);
}

template<class T>
ConcreteFortranSymmetricPackedArray2d<T>::
ConcreteFortranSymmetricPackedArray2d(const ConcreteFortranSymmetricPackedArray2d<T>& a) :
  ConcreteArray2d<SubscriptorT, T>(SubscriptArray<2>(a.shape(0), a.shape(1)), 0) {
  Subscript n = a.shape(0);
  setSizeOnHeap((n * (n + 1)) / 2);
  while (n-- > 0) datap[n] = a.datap[n];
}

template<class T>
ConcreteFortranSymmetricPackedArray2d<T>::~ConcreteFortranSymmetricPackedArray2d() {
   delete[] datap;
}

template<class T>
ConcreteFortranSymmetricPackedArray2d<T>& 
ConcreteFortranSymmetricPackedArray2d<T>::operator=(const ConcreteFortranSymmetricPackedArray2d<T>& rhs) {
  Subscript n = rhs.shape(0);
  if (n != rhs.shape(0)) throw ArrayErr::Shape();
  n = (n * (n+1)) / 2;    // Number of elements
  while (n-- > 0) datap[n] = rhs.datap[n];
  return *this;
}  

template<class T>
ConcreteFortranSymmetricPackedArray2d<T>& 
ConcreteFortranSymmetricPackedArray2d<T>::operator=(const T& rhs) {
  Subscript n = shape(0);
  n = (n * (n+1)) / 2;    // Number of elements
  while (n-- > 0) datap[n] = rhs;
  return *this;
}  
