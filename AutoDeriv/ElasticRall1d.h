/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ElasticRall1dH
#define ElasticRall1dH

#include "AutoDeriv/TaylorCoefficient1d.h"
#include "AutoDeriv/Rall1d.h"
#include "Vector/ElasticArithmetic.h"


template<class T>
class ElasticRall1d :   // Rall numbers with ElasticArithmetic1d gradient vectors         
    public Rall1d<T, ElasticArithmetic1d<T> > {
public:
    ElasticRall1d(){ 
    }
    ElasticRall1d(const T& c) : 
        Rall1d<T, ElasticArithmetic1d<T> >(c,1) {
    }
    ElasticRall1d(Subscript nvars, const T& c) : 
        Rall1d<T, ElasticArithmetic1d<T> >(c, nvars) {
    }
    ElasticRall1d(const T& c, Subscript i_th, Subscript nvars) :  
        Rall1d<T, ElasticArithmetic1d<T> >(c, i_th, nvars) {
    }
    ElasticRall1d(const Rall1d<T, ElasticArithmetic1d<T> >& r):  
        Rall1d<T, ElasticArithmetic1d<T> >(r) {
    }

    ElasticRall1d(const ElasticRall1d<T>& e) :  
        Rall1d<T, ElasticArithmetic1d<T> >(e) {
    }

};


template<class T>
ostream& operator<<(ostream& os, const ElasticRall1d<T>& v){ 
  return os << (const Rall1d<T, ElasticArithmetic1d<T> >&) v;
}

#endif
