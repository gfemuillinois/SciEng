/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ComplexFloatH
#define ComplexFloatH
#include "Algebra/FieldCategory.h"

#include <complex.h>

class ZeroDivideErr {
};


class ComplexFloat : 
    public FieldCategory< ComplexFloat > {
public:
    ComplexFloat(float r, float i = 0.) : real_part(r), imag_part(i) {}
    ComplexFloat() {}

    // Convert to complex numbers from <complex.h>
    operator complex() const { return complex(real_part, imag_part); }


    float  real()  const { return real_part;}
    float& real()        { return real_part;}
    float  imag()  const { return imag_part;}
    float& imag()        { return imag_part;}


    ComplexFloat& conj() { imag_part = -imag_part; return *this; }

    // Field "user must provide"
    inline ComplexFloat& operator*=(const ComplexFloat& rhs);
    ComplexFloat& operator/=(const ComplexFloat& rhs);
    inline ComplexFloat& setToOne();

    inline ComplexFloat& operator+=(const ComplexFloat& rhs);
    inline ComplexFloat& operator-=(const ComplexFloat& rhs);
    inline ComplexFloat& setToZero();
private:
    float real_part;
    float imag_part;
};


class ostream;
extern ostream& operator<<(ostream&, ComplexFloat);


inline ComplexFloat& ComplexFloat::operator*=(const ComplexFloat& rhs) {
    float t = real_part * rhs.real_part - imag_part * rhs.imag_part;
    imag_part = real_part * rhs.imag_part + imag_part * rhs.real_part;
    real_part = t;
    return *this;
}


inline ComplexFloat& ComplexFloat::setToOne() {
  real_part = 1.; 
  imag_part = 0.; 
  return *this;
}
inline ComplexFloat& ComplexFloat::operator+=(const ComplexFloat& rhs) {
    real_part += rhs.real_part;
    imag_part += rhs.imag_part;
    return *this;
}
inline ComplexFloat& ComplexFloat::operator-=(const ComplexFloat& rhs){
  real_part -= rhs.real_part;
  imag_part -= rhs.imag_part;
  return *this;
}

inline ComplexFloat& ComplexFloat::setToZero() {
  real_part = 0.; 
  imag_part = 0.; 
  return *this;
}

#endif

