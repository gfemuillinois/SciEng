/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

class Dangle {// WARNING: Incorrect code 
public:

    Dangle()  { p = new int(0); }
    ~Dangle() { delete p;       }

private:
    int* p;
};


void f() {      
    Dangle a;
    Dangle b = a;
}


class NoDangle { 
public:

    NoDangle()  { p = new int(0); }
    ~NoDangle() { delete p;       }

    NoDangle(const NoDangle& x) : p(new int(*x.p)) {}
    NoDangle& operator=(const NoDangle& rhs) {
        if (rhs.p != p) {
            delete p;
            p = new int(*rhs.p);
        }
        return *this;
    }
private:
    int* p;
};

