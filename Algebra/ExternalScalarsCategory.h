/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ExternalScalarsCategoryH
#define ExternalScalarsCategoryH


template<class V, class S>
class ExternalScalarsCategory {
public:
    // User Must Define: V& operator*=(const S&);
    friend V operator*(const S& s, const V& v) { V temp(v); return temp *= s; }
    friend V operator*(const V& v, const S& s) { V temp(v); return temp *= s; }
};

#endif
