/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "SciEng/utils.h"

template<class T, class V>
Rall1d<T,V>::
Rall1d(const T& c, Subscript nvars) : t(c), grad(nvars) {
   grad = T(0.);
}

template<class T, class V>
Rall1d<T,V>::
Rall1d(const Rall1d<T, V >& r): t(r.value()), grad(r.gradient()) { 
}

template<class T, class V>
Rall1d<T,V>::
Rall1d(const T& tn, const V& vn): t(tn), grad(vn) { 
}

template<class T, class V>
Rall1d<T,V>& Rall1d<T,V>::
operator=(const T& c){ 
   t = c;
   grad = T(0.0);
   return *this;
}

template<class T, class V>
Rall1d<T,V>& Rall1d<T,V>::
operator=(const Rall1d<T,V>& r){ 
  t = r.t; 
  grad = r.grad; 
  return *this;
}

  

template<class T, class V>
Rall1d<T,V>::Rall1d(const T& v, Subscript i_th, Subscript nvars) : 
    t(v), grad(nvars) {
    make_unit(i_th);
}

template<class T, class V>
void Rall1d<T,V>::make_unit(Subscript i_th) { 
    if (i_th < grad.shape(0)) {  
        grad = T(0.0);  // T() forces op=(const T&), not copy of V(Subscript);
        grad(i_th) = 1.0;
    }
    else throw RallInvalidUnitErr();
}


  
template<class T, class V>
Rall1d<T,V>& Rall1d<T,V>::
operator*=(const Rall1d<T,V>& rhs){
    // f(x,y,z) = g(x,y,z)*h(x,y,z); df/dx = h*dg/dx+g*dh/dx
    grad = grad * rhs.value() +
                          value() * rhs.grad;
    value() *= rhs.value();
    return *this;
}

template<class T, class V>
Rall1d<T,V>& Rall1d<T,V>::
setToOne(){
    value() = 1.0;
    grad.setToZero();
    return *this;
}


template<class T, class V>
Rall1d<T,V>& Rall1d<T,V>::
operator/=(const Rall1d<T,V>& rhs) {   
    T rhs_val = rhs.value();
    if (rhs_val == T(0.)) throw  RallDivideZeroErr();

    grad  = (grad * rhs_val - value() * rhs.grad) / sqr(rhs_val);
    t    /= rhs_val;

    return *this;
}


template<class T, class V>
Rall1d<T,V>& Rall1d<T,V>::
operator+=(const Rall1d<T,V>& rhs){
    grad += rhs.grad;
    value() += rhs.value();
    return *this;
}

template<class T, class V>
Rall1d<T,V>& Rall1d<T,V>::
operator-=(const Rall1d<T,V>& rhs){
    grad -= rhs.grad;
    value() -= rhs.value();
    return *this;
}

template<class T, class V>
Rall1d<T,V>& Rall1d<T,V>::
setToZero(){
    grad.setToZero();
    value() = 0;
    return *this;
}

template<class T, class V>
Rall1d<T,V>& Rall1d<T,V>::operator*=(const T& s) {
       grad *= s;
       value() *= s;
       return *this;
}

template<class T, class V>
Rall1d<T,V>& Rall1d<T,V>::operator/=(const T& s) {
       grad/=(s);
       value() /= s;
       return *this;
}

template<class T, class V>
Rall1d<T,V> exp(const Rall1d<T,V>& rhs){
    Rall1d<T,V> tmp(::exp(rhs.value()), rhs.grad);
    tmp.grad *= tmp.value();
    return tmp;
}

template<class T, class V>
Rall1d<T,V> sin(const Rall1d<T,V>& rhs){
    Rall1d<T,V> tmp(::sin(rhs.value()), rhs.grad);
    tmp.grad  *= ::cos( rhs.value() );
    return tmp;
}

template<class T, class V>
Rall1d<T,V> cos(const Rall1d<T,V>& rhs){
    Rall1d<T,V> tmp(::cos(rhs.value()), rhs.grad);
    tmp.grad  *= (-1.0)*::sin( rhs.value() );
    return tmp;
}


template<class T, class V>
Rall1d<T,V> asin(const Rall1d<T,V>& rhs) {
    T val = rhs.value();
    Rall1d<T,V> tmp(::asin(val), rhs.grad);
    tmp.grad *= T(1)/(::sqrt(T(1.0) - sqr(val)));
    return tmp;
}

template<class T, class V>
Rall1d<T,V> acos(const Rall1d<T,V>& rhs){
    T val = rhs.value();
    Rall1d<T,V> tmp(::acos(val), rhs.grad);
    tmp.grad *= -T(1)/(::sqrt(T(1.0) - sqr(val)));
    return tmp;
}

template<class T, class V>
Rall1d<T,V> sqrt(const Rall1d<T,V>& rhs){
    Rall1d<T,V> tmp(::sqrt(rhs.value()), rhs.grad);
    tmp.grad /= T(2.0)*tmp.value();
    return tmp;
}
template<class T, class V>
Rall1d<T,V> log(const Rall1d<T,V>& rhs){
    Rall1d<T,V> tmp(::log(rhs.value()), rhs.grad);
    tmp.grad /= rhs.value();
    return tmp;
}
template<class T, class V>
Rall1d<T,V> log10(const Rall1d<T,V>& rhs){
    Rall1d<T,V> tmp(::log10(rhs.value()), rhs.grad);
    tmp.grad /= rhs.value();
    return tmp;
}

template<class T, class V>
ostream& operator<<(ostream& os, const Rall1d<T,V>& r){
   const T& v = r.value();
   return os << "(" << v << "," << r.gradient() << ")";
}

template<class T, class V>
Boolean Rall1d<T,V>::equivalentTo(const Rall1d<T,V>& rhs) const {
  return ( value() == rhs.value() ) && ( gradient() == rhs.gradient() );
  }

#include "AutoDeriv/TaylorCoefficient1d.h"

template<class T, class V>
TaylorCoefficient1d<T> reform(const Rall1d<T,V>& r) { 
    Subscript n = r.gradient().numElts();
    TaylorCoefficient1d<T> tmp(r.value(), n);
    while(n--) tmp(n) = r.gradient()(n);
    return tmp;
}

  
