/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
template<class T>
ConcreteFortranArray3d<T>::ConcreteFortranArray3d(Subscript s0, Subscript s1, Subscript s2) :
   ConcreteArray3d<SubscriptorType, T>(SubscriptArray<3>(s0, s1, s2), 0) {
   setSizeOnHeap(s0 * s1 * s2);
}

template<class T>
ConcreteFortranArray3d<T>::
ConcreteFortranArray3d(const ConcreteFortranArray3d<T>& a) :
  ConcreteArray3d<SubscriptorType, T>(SubscriptArray<3>(a.shape(0), a.shape(1), a.shape(2)), 0) {
  setSizeOnHeap(a.numElts());
  concreteCopy(*this, a);
}

template<class T>
ConcreteFortranArray3d<T>::
ConcreteFortranArray3d(const ConcreteArray3dConstRef<SubscriptorType, T>& a) :
  ConcreteArray3d<SubscriptorType, T>(SubscriptArray<3>(a.shape(0), a.shape(1), a.shape(2)), 0) {
  setSizeOnHeap(a.numElts());
  concreteCopy(*this, a);
}

template<class T>
ConcreteFortranArray3d<T>::
ConcreteFortranArray3d(const ConcreteArray3dConstRef<ConcreteColumnMajorSubscriptor<4>::ProjectionT, T>& a) :
   ConcreteArray3d<SubscriptorType, T>(SubscriptArray<3>(a.shape(0), a.shape(1), a.shape(2)), 0) {
   setSizeOnHeap(a.numElts());
   concreteCopy(*this, a);
}

template<class T>
ConcreteFortranArray3d<T>::~ConcreteFortranArray3d() {
   delete[] datap;
}

template<class T>
ConcreteFortranArray3d<T>& ConcreteFortranArray3d<T>::operator=(const ConcreteFortranArray3d<T>& rhs) {
  concreteCopy(*this, rhs);
  return *this;
}

template<class T>
ConcreteFortranArray3d<T>& ConcreteFortranArray3d<T>::operator=(
const ConcreteArray3dConstRef<SubscriptorType, T>& rhs) {
  concreteCopy(*this, rhs);
  return *this;
}

template<class T>
ConcreteFortranArray3d<T>& ConcreteFortranArray3d<T>::operator=(const T& rhs) {
  ConcreteArray3d<ConcreteColumnMajorSubscriptor<3>, T>::operator=(rhs);
  return *this;
}

