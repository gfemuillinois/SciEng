/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef SubscriptArrayH
#define SubscriptArrayH

#include "SciEng/Subscript.h"


template<Dimension ndim> 
class SubscriptArray {
    // Empty template -- supply a specialization for each
    // value of ndim.
};

                       

class SubscriptArray<1> {
public:
    SubscriptArray() {}
    SubscriptArray(Subscript s0) : sub0(s0) {}
    SubscriptArray<1>& operator=(Subscript rhs) {
        sub0 = rhs;
        return *this;
    }

    Subscript& operator()(Subscript)       { return sub0; }
    Subscript  operator()(Subscript) const { return sub0; }

private:
    Subscript sub0;
};

class SubscriptArray<2> {
public:
    SubscriptArray() {}
    SubscriptArray(Subscript s0, Subscript s1) {
        sub[0] = s0;
        sub[1] = s1;
    }
    SubscriptArray<2>& operator=(Subscript rhs) {
        sub[0] = sub[1] = rhs;
        return *this;
    }

    Subscript& operator()(Subscript i)       { return sub[i]; }
    Subscript  operator()(Subscript i) const { return sub[i]; }

private:
    Subscript sub[2];
};


class SubscriptArray<3> { 
public:
    SubscriptArray() {}
    SubscriptArray(Subscript s0, Subscript s1, Subscript s2) {
        sub[0] = s0;
        sub[1] = s1;
        sub[2] = s2;
    }
    SubscriptArray<3>& operator=(Subscript rhs) {
        sub[0] = sub[1] = sub[2] = rhs;
        return *this;
    }
    Subscript operator()(Subscript i) const { return sub[i]; }
    Subscript& operator()(Subscript i) { return sub[i]; }
private:
    Subscript sub[3];
};

class SubscriptArray<4> { 
public:
    SubscriptArray() {}
    SubscriptArray(Subscript s0, Subscript s1, Subscript s2, Subscript s3) {
        sub[0] = s0;
        sub[1] = s1;
        sub[2] = s2;
        sub[3] = s3;
    }
    SubscriptArray<4>& operator=(Subscript rhs) {
        sub[0] = sub[1] = sub[2] = sub[3] = rhs;
        return *this;
    }
    Subscript operator()(Subscript i) const { return sub[i]; }
    Subscript& operator()(Subscript i) { return sub[i]; }
private:
    Subscript sub[4];
};

#endif
