/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef Rall1dH
#define Rall1dH

#include "AutoDeriv/TaylorCoefficient1d.h"

#include "Algebra/DivisionAlgebraCategory.h"
#include "Algebra/MetricSpaceCategory.h"
#include "SciEng/EquivalentCategory.h"
#include "SciEng/ArrayErr.h"
#include "SciEng/String.h"

class RallDivideZeroErr : public SciEngErr {
  public:
  RallDivideZeroErr(){}
  virtual String message() const {
     return "Rall: divide by zero!";
  }
};

class RallInvalidUnitErr : 
  public SciEngErr {
public:
  RallInvalidUnitErr() {}
  virtual String message() const {
     return "Rall Number unit vector invalid...too many variables? Zero is first, nvars-1 is max.";
  }
};


template<class T, class V>  // T element type, V gradient vector type.
class Rall1d :     
    public DivisionAlgebraCategory< Rall1d<T,V> ,T>,
    public EquivalentCategory< Rall1d<T,V> >,
    public MetricSpaceCategory< Rall1d<T,V>, Rall1d<T,V> > {
public:
    typedef T EltT;


    Rall1d(){}                                           // Constant, zero.
    Rall1d(const T& c, Subscript nvars = 1);             // Constant.
    Rall1d(const T& t, Subscript i_th, Subscript nvars); // i_th unit vector, value t.
    Rall1d(const Rall1d<T, V >& r);
    Rall1d(const T& tn, const V& vn);
    Rall1d<T,V>& operator=(const T& c);                  // Change to constant, value c.
    Rall1d<T,V>& operator=(const Rall1d<T,V>& r);




    // Algebra interface
    Rall1d<T,V>& operator*=(const Rall1d<T,V>& rhs);
    Rall1d<T,V>& setToOne();
    Rall1d<T,V>& operator/=(const Rall1d<T,V>& rhs);

    Rall1d<T,V>& operator+=(const Rall1d<T,V>& rhs);
    Rall1d<T,V>& setToZero();
    Rall1d<T,V>& operator-=(const Rall1d<T,V>& rhs);

    Rall1d<T,V>& operator*=(const T& s);
    Rall1d<T,V>& operator/=(const T& s);

    Rall1d<T,V>  dot(const Rall1d<T,V>& rhs) const { return *this * rhs; }

    Boolean equivalentTo(const Rall1d<T,V>& rhs) const;

    // Transcendental Functions
    friend Rall1d<T,V> exp(const Rall1d<T,V>&);
    friend Rall1d<T,V> sqrt(const Rall1d<T,V>&);
    friend Rall1d<T,V> log(const Rall1d<T,V>&);
    friend Rall1d<T,V> log10(const Rall1d<T,V>&);
    friend Rall1d<T,V> cos(const Rall1d<T,V>&);
    friend Rall1d<T,V> sin(const Rall1d<T,V>&);
    friend Rall1d<T,V> acos(const Rall1d<T,V>&);
    friend Rall1d<T,V> asin(const Rall1d<T,V>&);




    T&       value()          { return t; }
    const T& value()    const { return t; }
    V&       gradient()       { return grad; }
    const V& gradient() const { return grad; }


    friend ostream& operator<<(ostream& os, const Rall1d<T,V>& r);
protected:
    T t;
    V grad;
    void make_unit(Subscript i_th);
};


template<class T>
class TaylorCoefficient1d;

template<class T, class V>
TaylorCoefficient1d<T> reform(const Rall1d<T,V>& r);


#ifdef XLC_QNOTEMPINC
#include "AutoDeriv/Rall1d.c"
#endif

#endif
