/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
/* CAD: Originally we had

  ConcreteArray1d< SubscriptorT, T>(SubscriptArray<1>(s0), 0) {

where SubscriptorT is a member from the base class. The full name for
SubscriptorT is

ConcreteArray1d<ConcreteColumnMajorSubscriptor<1>, T>::SubscriptorT

which is a typedef to ConcreteColumnMajorSubscriptor<1>

Adding typename was not enough for the egcs-2.91.66 compiler.

So, we have the option of instead of using "typename SubscriptorT", we use

typename  ConcreteArray1d<ConcreteColumnMajorSubscriptor<1>, T>::SubscriptorT

or just

ConcreteColumnMajorSubscriptor<1>

I am using the first (long) option bcz it is closer to the original source and
in the hope that we can delete ConcreteArray1d<ConcreteColumnMajorSubscriptor<1>, T>::
in the future (newer version of egcs)

ANOTHER OPTION: in the declaration of the class ConcreteFortranArray1d
we have

typedef ConcreteColumnMajorSubscriptor<1> Subscriptor;

so we can also use, instead of SubscriptorT,

Subscriptor

*/

template<class T>
ConcreteFortranArray1d<T>::                       
ConcreteFortranArray1d(Subscript s0) :
  ConcreteArray1d< typename ConcreteArray1d<ConcreteColumnMajorSubscriptor<1>, T>::SubscriptorT, T>
(SubscriptArray<1>(s0), 0) {
  setSizeOnHeap(s0);
}

template<class T>
ConcreteFortranArray1d<T>::                       
ConcreteFortranArray1d(const ConcreteFortranArray1d<T>& a) :
  ConcreteArray1d< typename ConcreteArray1d<ConcreteColumnMajorSubscriptor<1>, T>::SubscriptorT, T>
(SubscriptArray<1>(a.shape(0)), 0) {
  setSizeOnHeap(a.numElts());
  concreteCopy(*this, a);
}

template<class T>
ConcreteFortranArray1d<T>::                       
ConcreteFortranArray1d(ConcreteArray1dConstRef<Subscriptor, T> a) :
  ConcreteArray1d< typename ConcreteArray1d<ConcreteColumnMajorSubscriptor<1>, T>::SubscriptorT, T>
(SubscriptArray<1>(a.shape(0)), 0) {
  setSizeOnHeap(a.numElts());
  concreteCopy(*this, a);
}

template<class T>
ConcreteFortranArray1d<T>::                       
ConcreteFortranArray1d(ConcreteArray1dConstRef<ConcreteColumnMajorSubscriptor<2>::ProjectionT, T> a) :
  ConcreteArray1d<Subscriptor, T>(SubscriptArray<1>(a.shape(0)), 0) {
  setSizeOnHeap(a.numElts());
  concreteCopy(*this, a);
}

template<class T>
ConcreteFortranArray1d<T>::~ConcreteFortranArray1d() {
   delete[] datap;
}

template<class T>
ConcreteFortranArray1d<T>& ConcreteFortranArray1d<T>::operator=(const ConcreteFortranArray1d<T>& rhs) {
  concreteCopy(*this, rhs);
  return *this;
}

template<class T>
ConcreteFortranArray1d<T>& ConcreteFortranArray1d<T>::operator=(ConcreteArray1dConstRef<Subscriptor, T> rhs) {
  concreteCopy(*this, rhs);
  return *this;
}

template<class T>
ConcreteFortranArray1d<T>& ConcreteFortranArray1d<T>::operator=(const T& rhs) {
  ConcreteArray1d<ConcreteColumnMajorSubscriptor<1>, T>::operator=(rhs);
  return *this;
}
