/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

class ComplexDouble;

class ComplexFloat {
public:
    // ...
    operator ComplexDouble() const;
    // ...
};

class ComplexDouble {
public:
    // ...
    ComplexDouble(const ComplexFloat&);
    // ...
};

ComplexFloat cf;
// ...
/*
ComplexDouble cd = cf; // WRONG: ambiguous conversion

*/
