/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
template<class T>
ConcreteFormedArray2d<T>::ConcreteFormedArray2d() :
  ConcreteArray2d< typename ConcreteArray2d< ConcreteRowMajorSubscriptor<2>, T >::SubscriptorT, T>(SubscriptArray<2>(0, 0), 0) {
}

template<class T>
ConcreteFormedArray2d<T>::ConcreteFormedArray2d(Subscript s0, Subscript s1) :
  ConcreteArray2d< typename ConcreteArray2d< ConcreteRowMajorSubscriptor<2>, T >::SubscriptorT, T>(SubscriptArray<2>(s0, s1), 0) {
   setSizeOnHeap(s0 * s1);
}

template<class T>
ConcreteFormedArray2d<T>::
ConcreteFormedArray2d(const ConcreteFormedArray2d<T>& a) :
  ConcreteArray2d< typename ConcreteArray2d< ConcreteRowMajorSubscriptor<2>, T >::SubscriptorT, T>(SubscriptArray<2>(a.shape(0), a.shape(1)), 0) {
  setSizeOnHeap(a.numElts());
  concreteCopy(*this, a);
}

template<class T>
ConcreteFormedArray2d<T>::
ConcreteFormedArray2d(const ConcreteArray2dConstRef<ConcreteRowMajorSubscriptor<2>, T>& a) :
  ConcreteArray2d< typename ConcreteArray2d< ConcreteRowMajorSubscriptor<2>, T >::SubscriptorT, T>(SubscriptArray<2>(a.shape(0), a.shape(1)), 0) {
  setSizeOnHeap(a.numElts());
  concreteCopy(*this, a);
}

template<class T>
ConcreteFormedArray2d<T>::
ConcreteFormedArray2d(const ConcreteArray2dConstRef<ConcreteRowMajorSubscriptor<3>::ProjectionT, T>& a) :
   ConcreteArray2d< typename ConcreteArray2d< ConcreteRowMajorSubscriptor<2>, T >::SubscriptorT, T> (SubscriptArray<2>(a.shape(0), a.shape(1)), 0) {
   setSizeOnHeap(a.numElts());
   concreteCopy(*this, a);
}

template<class T>
ConcreteFormedArray2d<T>::~ConcreteFormedArray2d() {
   delete[] datap;
}

template<class T>
ConcreteFormedArray2d<T>& ConcreteFormedArray2d<T>::operator=(const ConcreteFormedArray2d<T>& rhs) {
  concreteCopy(*this, rhs);
  return *this;
}

template<class T>
ConcreteFormedArray2d<T>& ConcreteFormedArray2d<T>::operator=(const ConcreteArray2dConstRef< typename ConcreteArray2d<ConcreteRowMajorSubscriptor<2>, T >::SubscriptorT, T>& rhs) {
  concreteCopy(*this, rhs);
  return *this;
}

template<class T>
ConcreteFormedArray2d<T>& ConcreteFormedArray2d<T>::operator=(const T& rhs) {
  ConcreteArray2d<ConcreteRowMajorSubscriptor<2>, T>::operator=(rhs);
  return *this;
}

/* CAD: already defined in ConcreteFormedArray2d.h:34 
template<class T>
void ConcreteFormedArray2d<T>::reshape(const SubscriptArray<2>& s) {
  ConcreteArray2d< typename ConcreteArray2d<ConcreteRowMajorSubscriptor<2>, T >::SubscriptorT, T>::reshapeOnHeap(s);
}
*/

