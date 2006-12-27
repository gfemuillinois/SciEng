/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

class A {
public:
    A() { init(); }

  virtual ~A() {}

    virtual void f() = 0;
    void init() { f(); }
};

class B :
    public A {
public:
    B() : A() {}

  virtual ~B() {}

    virtual void f() { }
};

int main() {
    B b;
    return 0;
}

