/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
template<class T>
ConcreteFormedArray1d<T>::                       
ConcreteFormedArray1d() :
  ConcreteArray1d<SubscriptorT, T>(SubscriptArray<1>(0), 0) {
}

template<class T>
ConcreteFormedArray1d<T>::                       
ConcreteFormedArray1d(Subscript s0) :
  ConcreteArray1d<SubscriptorT, T>(SubscriptArray<1>(s0), 0) {
  setSizeOnHeap(s0);
}

template<class T>
ConcreteFormedArray1d<T>::                       
ConcreteFormedArray1d(const ConcreteFormedArray1d<T>& a) :
  ConcreteArray1d<SubscriptorT, T>(SubscriptArray<1>(a.shape(0)), 0) {
  setSizeOnHeap(a.numElts());
  concreteCopy(*this, a);
}

template<class T>
ConcreteFormedArray1d<T>::                       
ConcreteFormedArray1d(ConcreteArray1dConstRef<SubscriptorT, T> a) :
  ConcreteArray1d<SubscriptorT, T>(SubscriptArray<1>(a.shape(0)), 0) {
  setSizeOnHeap(a.numElts());
  concreteCopy(*this, a);
}

template<class T>
ConcreteFormedArray1d<T>::                       
ConcreteFormedArray1d(ConcreteArray1dConstRef<ConcreteRowMajorSubscriptor<2>::ProjectionT, T> a) :
  ConcreteArray1d<SubscriptorT, T>(SubscriptArray<1>(a.shape(0)), 0) {
  setSizeOnHeap(a.numElts());
  concreteCopy(*this, a);
}

template<class T>
ConcreteFormedArray1d<T>::~ConcreteFormedArray1d() {
   delete[] datap;
}

template<class T>
ConcreteFormedArray1d<T>& ConcreteFormedArray1d<T>::operator=(const ConcreteFormedArray1d<T>& rhs) {
  concreteCopy(*this, rhs);
  return *this;
}

template<class T>
ConcreteFormedArray1d<T>& ConcreteFormedArray1d<T>::operator=(ConcreteArray1dConstRef<Subscriptor, T> rhs) {
  concreteCopy(*this, rhs);
  return *this;
}

template<class T>
ConcreteFormedArray1d<T>& ConcreteFormedArray1d<T>::operator=(const T& rhs) {
  ConcreteArray1d<ConcreteRowMajorSubscriptor<1>, T>::operator=(rhs);
  return *this;
}
