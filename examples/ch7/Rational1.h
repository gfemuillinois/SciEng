/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

class Rational {
public:
    Rational();
    Rational(int numerator, int denominator);
    // ...
    static Rational zero;
    static Rational quarter;
    static Rational half;
    // ...
};

class RationalInitializer {
public:
    RationalInitializer();
private:
    static int count;
};

static RationalInitializer riInit;

