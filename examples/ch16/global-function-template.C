/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

template<class T>
T operator*(const T& lhs, const T& rhs) {
    T temp(lhs);
    return temp *= rhs;
}


struct Foo { 
  Foo& operator*=(const Foo&);
};

void f() {
  Foo a;
  Foo b;
  Foo c = a * b;
}
