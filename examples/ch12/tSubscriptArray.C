/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Array/SubscriptArray.h"


template<Dimension ndim>
class UsesSA {
public:
    // ...
private:
    SubscriptArray<ndim> a;
};


void f() {
  UsesSA<1> a1;
  UsesSA<2> a2;
}
