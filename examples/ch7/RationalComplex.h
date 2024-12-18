/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

class RationalComplex {
public:
    RationalComplex(const Rational& real, const Rational& imag);
    // ...
    static const RationalComplex realHalf;
    static const RationalComplex imagHalf;
    // ...
};

