/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
// WARNING:  Don't add a default constructor to this example, since the
// text talks about the implications of not having one.

class Rational {
public:
    Rational(int numerator, int denominator);
    // ...
    static const Rational zero;
    static const Rational quarter;
    static const Rational half;
    // ...
};

