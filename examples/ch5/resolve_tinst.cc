// Dummy file to create the template instances
// This is how we handle templates with g++
// Link the object generated from the compilation of this file with
// any program that uses the instances created here


#ifdef NO_IMPLICIT_TEMPLATE

#include <iostream>

template<class T> extern void f(T) { cout << "f(T)" << endl; }

template void f<int>(int);

template void f<char>(char);

#endif
