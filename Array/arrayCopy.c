/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

template<class Subscriptor, class T>
void arrayCopy(const ConcreteArray1dRef<Subscriptor, T>& lhs, const ConstArray1d<T>& rhs) {
  Subscript i = lhs.shape(0);
  if (i != rhs.shape(0)) throw ArrayErr::Shape();
  while (i-- > 0) lhs(i) = rhs(i);
}



template<class AnArray, class T>
void arrayCopy(Array1d<T>& lhs, const AnArray& rhs) {
  Subscript i = lhs.shape(0);
  if (i != rhs.shape(0)) throw ArrayErr::Shape();
  while (i-- > 0) lhs(i) = rhs(i);
}
/*
template<class AnArray, class T>
void arrayCopy(AnArray& lhs, const ConstArray1d<T>& rhs) {
  Subscript i = lhs.shape(0);
  if (i != rhs.shape(0)) throw ArrayErr::Shape();
  while (i-- > 0) lhs(i) = rhs(i);
}
*/
