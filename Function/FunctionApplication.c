/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
template<class T>
void apply(T (*f)(const T&), Array1d<T>& a) {
  for (Array1d<T>::IteratorType a_i(a); a_i.more(); a_i.advance()) {  
    a_i.current() = f(a_i.current());
}
}


template<class T>
void apply(T (*f)(T), Array1d<T>& a) { 
    for (Array1d<T>::IteratorType a_i(a); a_i.more(); a_i.advance()) {  
        a_i.current() = f(a_i.current());
    }
}

template<class T, class Subscriptor>
void apply(T (*f)(T), ConcreteArray1dRef<Subscriptor, T> a) { 
    for (ConcreteArray1dRef<Subscriptor, T>::IteratorType a_i(a); a_i.more(); a_i.advance()) {  
        a_i.current() = f(a_i.current());
    }
}


template<class T,  class Subscriptor>
void apply(T (*f)(const T&), ConcreteArray1dRef<Subscriptor, T> a) {
  for (ConcreteArray1dRef<Subscriptor, T>::IteratorType a_i(a); a_i.more(); a_i.advance()) {
    a_i.current() = f(a_i.current());
  }
}
