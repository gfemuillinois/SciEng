/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef AccessedArray1dH
#define AccessedArray1dH

#include "Array/Array1d.h"

template<class T>
class AccessedConstArray1d :
  public ConstArray1d<T> {
public:
  typedef typename ConstArray1d<T>::EltT EltT;

  AccessedConstArray1d(ConstArray1d<T>* newed_t) : the_array(newed_t) {}
  virtual ~AccessedConstArray1d() { delete the_array; }

  virtual Subscript         shape(Dimension d)                const { return the_array->shape(d); }
  virtual Subscript         numElts()                         const { return the_array->numElts(); }
  
  virtual const EltT&       operator()(Subscript i) const { return (*the_array)(i); }
  virtual const EltT&       operator[](Subscript i) const { return (*the_array)[i]; }
  
private:
  ConstArray1d<T>* the_array;
};

template<class T>
class AccessedArray1d :
  public Array1d<T> {
public:

  typedef typename Array1d<T>::EltT EltT;

  AccessedArray1d(Array1d<T>* newed_t) : the_array(newed_t) {}
  ~AccessedArray1d() { delete the_array; }

  virtual Subscript         shape(Dimension d)                const { return the_array->shape(d); }
  virtual Subscript         numElts()                         const { return the_array->numElts(); }
  
  virtual const EltT&       operator()(Subscript i) const { return (*the_array)(i); }
  virtual       EltT&       operator()(Subscript i)       { return (*the_array)(i); }
  
  virtual const EltT&       operator[](Subscript i) const { return (*the_array)[i]; }
  virtual       EltT&       operator[](Subscript i)       { return (*the_array)[i]; }
  
  virtual Array1d<T>& operator=(const ConstArray1d<T>& rhs) { return the_array->operator=(rhs); }
  virtual Array1d<T>& operator=(const T& rhs)               { return the_array->operator=(rhs); }
  
private:
  Array1d<T>* the_array;
};

#endif
