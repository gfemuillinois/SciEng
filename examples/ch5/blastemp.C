/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
class ComplexFloat;
class complex;
template<class T> class Vector;



void axpy(float        alpha, const Vector<float>&        x, Vector<float>&        y);
void axpy(double       alpha, const Vector<double>&       x, Vector<double>&       y);
void axpy(ComplexFloat alpha, const Vector<ComplexFloat>& x, Vector<ComplexFloat>& y);
void axpy(complex      alpha, const Vector<complex>&      x, Vector<complex>&      y);




void axpy(float        alpha, const Vector<double>&       x, Vector<double>&       y);


