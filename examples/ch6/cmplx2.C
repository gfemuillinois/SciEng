/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
class Complex {
public:
    Complex(float = 0.0);
    Complex(float, float);
    Complex& operator*=(const Complex&);
    // ...
private:
    float real_part;
    float imag_part;
};


Complex& Complex::operator*=(const Complex& rhs) {
    float original_real_part = real_part;

    real_part  = real_part * rhs.real_part - imag_part * rhs.imag_part;
    imag_part  = imag_part * rhs.real_part + original_real_part * rhs.imag_part;

    return *this;
}



Complex operator*(const Complex& lhs, const Complex& rhs) {
    Complex result(lhs);
    return result *= rhs;
}


void f() {

Complex a(1,1);
Complex b(2,3);
a *= b;


a.operator*=(b);

}
