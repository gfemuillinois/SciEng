/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef PhysicalH
#define PhysicalH

#include "Algebra/LinearSpaceCategory.h"
class ostream;


template<class T, int m, int l, int t, int q, int k, int i, int a>
class Physical :
    public LinearSpaceCategory< Physical<T, m, l, t, q, k, i, a>, T > {
public:
    Physical(const T& v) : val(v) {}
    T& value() { return val; }
    const T& value() const { return val; }
private:
    typedef Physical<T, m, l, t, q, k, i, a> Phys; // Shorthand
public:
    Phys convertTo(const Phys& dest_unit) const { return val / dest_unit.val; }

    // LinearSpaceCategory "user must define" functions

    Phys& operator+=(const Phys& rhs) { val += rhs.val; return *this; }
    Phys& operator-=(const Phys& rhs) { val -= rhs.val; return *this; }
    Phys& setToZero()                 { val = T(0); return *this;     }
    Phys& operator*=(T s)             { val *= s; return *this;       }
    Phys& operator/=(T s)             { val /= s; return *this;       }

private:
    T val;
};




template<class T, int m1, int l1, int t1, int q1, int k1, int i1, int a1,
                  int m2, int l2, int t2, int q2, int k2, int i2, int a2>

Physical<T, m1+m2, l1+l2, t1+t2, q1+q2, k1+k2, i1+i2, a1+a2>

operator*(const Physical<T, m1, l1, t1, q1, k1, i1, a1>& lhs, 
          const Physical<T, m2, l2, t2, q2, k2, i2, a2>& rhs
         ) {

    return lhs.value() * rhs.value();
}


template<class T, int m1, int l1, int t1, int q1, int k1, int i1, int a1,
                  int m2, int l2, int t2, int q2, int k2, int i2, int a2>

Physical<T, m1-m2, l1-l2, t1-t2, q1-q2, k1-k2, i1-i2, a1-a2>

operator/(const Physical<T, m1, l1, t1, q1, k1, i1, a1>& lhs, 
          const Physical<T, m2, l2, t2, q2, k2, i2, a2>& rhs
         ) {

    return lhs.value() / rhs.value();
}


template<class T, int m, int l, int t, int q, int k, int i, int a>
ostream& operator<<(ostream& os, const Physical<T, m, l, t, q, k, i, a>& p);

extern ostream& powerPrinter(ostream&, int[7]);  

#ifdef XLC_QNOTEMPINC
#include "Units/Physical.c"
#endif

#endif


