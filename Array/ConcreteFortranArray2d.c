/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

template<class T>
ConcreteFortranArray2d<T>::ConcreteFortranArray2d(Subscript s0, Subscript s1) : 
    ConcreteArray2d<SubscriptorT, T>(SubscriptArray<2>(s0, s1), 0) {
    setSizeOnHeap(s0 * s1);
}



template<class T>
ConcreteFortranArray2d<T>::
ConcreteFortranArray2d(const ConcreteFortranArray2d<T>& a) : 
    ConcreteArray2d<SubscriptorT, T>(SubscriptArray<2>(a.shape(0), a.shape(1)), 0) {
    setSizeOnHeap(a.numElts());
    concreteCopy(*this, a);
}


template<class T>
ConcreteFortranArray2d<T>::
ConcreteFortranArray2d(const ConcreteArray2dConstRef<ConcreteFortranArray2d<T>::SubscriptorT, T>& a) :
  ConcreteArray2d<SubscriptorT, T>(SubscriptArray<2>(a.shape(0), a.shape(1)), 0) {
  setSizeOnHeap(a.numElts());
  concreteCopy(*this, a);
}

template<class T>
ConcreteFortranArray2d<T>::
ConcreteFortranArray2d(const ConcreteArray2dConstRef<ConcreteColumnMajorSubscriptor<3>::ProjectionT, T>& a) :
   ConcreteArray2d<SubscriptorT, T>(SubscriptArray<2>(a.shape(0), a.shape(1)), 0) {
   setSizeOnHeap(a.numElts());
   concreteCopy(*this, a);
}

template<class T>
ConcreteFortranArray2d<T>::~ConcreteFortranArray2d() {
   delete[] datap;
}

template<class T>
ConcreteFortranArray2d<T>& ConcreteFortranArray2d<T>::operator=(const ConcreteFortranArray2d<T>& rhs) {
  concreteCopy(*this, rhs);
  return *this;
}

template<class T>
ConcreteFortranArray2d<T>& ConcreteFortranArray2d<T>::operator=(const ConcreteArray2dConstRef<SubscriptorT, T>& rhs) {
  concreteCopy(*this, rhs);
  return *this;
}

template<class T>
ConcreteFortranArray2d<T>& ConcreteFortranArray2d<T>::operator=(const T& rhs) {
  ConcreteArray2d<ConcreteColumnMajorSubscriptor<2>, T>::operator=(rhs);
  return *this;
}

