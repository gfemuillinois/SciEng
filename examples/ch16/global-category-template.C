/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
template<class T>
class SemiGroupCategory {};


template<class T>
T operator*(const SemiGroupCategory<T>& lhs, const SemiGroupCategory<T>& rhs) {
    T temp((const T&) lhs);
    return temp *= (const T&) rhs;
}



struct Foo : public SemiGroupCategory<Foo> {
  Foo();
  Foo(int);
  Foo(const Foo&);
  Foo& operator*=(const Foo&);
};

void f() {
  Foo a;
  Foo b;
  Foo c = a * b;
//  Foo d = 2 * b;  // Shouldn't compile if uncommented
}
