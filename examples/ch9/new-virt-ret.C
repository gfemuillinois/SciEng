/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

class C1 {};
class C2 : public C1 {};

class B {
public:
    virtual C1& f();
};

class D :
    public B {
public:
    virtual C2& f();// Formerly illegal
};

