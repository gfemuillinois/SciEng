/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef TranscendentalFunctionCategoryH
#define TranscendentalFunctionCategoryH

#include <math.h>

template<class T>
class LogarithmicFunctionCategory {
public:

    // User Must Define: T& exp();
    // User Must Define: T& sqrt();
    // User Must Define: T& log();    // logarithm base e
    // User Must Define: T& log10();    // logarithm base 10
  
  friend T exp(const T& n) { T temp(n); return temp.exp(); }
  friend T sqrt(const T& n) { T temp(n); return temp.sqrt(); }
  friend T log(const T& n) { T temp(n); return temp.log(); }
  friend T log10(const T& n) { T temp(n); return temp.log10(); }
};

template<class T>
class TrigonometricFunctionCategory {
public:
    // User Must Define:  T& sin();
    // User Must Define:  T& cos();
  
  friend T sin(const T& n) { T temp(n); return temp.sin(); }
  friend T cos(const T& n) { T temp(n); return temp.cos(); }
};
        
template<class T>
class InverseTrigonometricFunctionCategory {
public:
    // User Must Define:  T& asin();
    // User Must Define:  T& acos();
  // others!
  friend T asin(const T& n) { T temp(n); return temp.asin(); }
  friend T acos(const T& n) { T temp(n); return temp.acos(); }
};

template< class T >
class TranscendentalFunctionCategory :
   public LogarithmicFunctionCategory<T>,
   public InverseTrigonometricFunctionCategory<T>,
   public TrigonometricFunctionCategory<T> {
   // HyperbolicFunctionCategory
    public:

};

#endif
