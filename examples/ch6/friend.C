/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

class A;
class B {
public:
    double g() const; 
    double g();
    double g(int);
    void h();
};

class C {
public:

    friend int f(double);        // Global function: int f(double)
    friend double B::g() const;  // Member of B: double g() const
                                 // Note: only one of B's g members is a friend
    friend class D;              // All members of D
    friend class A;              // All members of A; A already declared
private:
    friend void B::h();          // Member of B: void h()

};



class X {
public:
    class Y {
    public:
        friend class Z; // Declares X::Z
    };

    class Z { };
};

