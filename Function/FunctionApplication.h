/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef FunctionApplicationH
#define FunctionApplicationH

template<class T>
void apply(T (*f)(const T&), Array1d<T>& a);

template<class T>
void apply(T (*f)(T), Array1d<T>& a);

template<class T, class Subscriptor>
void apply(T (*f)(T), ConcreteArray1dRef<Subscriptor, T> a);

template<class T,  class Subscriptor>
void apply(T (*f)(const T&), ConcreteArray1dRef<Subscriptor, T> a);
           
#ifdef XLC_QNOTEMPINC
#include "Function/FunctionApplication.c"
#endif

#endif
