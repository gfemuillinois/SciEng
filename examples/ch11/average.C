/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

#include "Array/ArrayShape.h"

#include <iostream.h>
#include <strstream.h>
#include <float.h>

// /////////////////////////////////////////////////////////////////
// This part looks like Array2d in the book, but has the typedef added.

template<class T>
class Array2d :
    public virtual ArrayShape {
public:
    typedef T EltT;
    // ...

    virtual Array2d<T>& operator=(const Array2d<T>& rhs)           = 0;
    virtual Array2d<T>& operator=(const T& rhs)                    = 0;

    virtual const T&    operator()(Subscript i, Subscript j) const = 0;
    virtual T&          operator()(Subscript i, Subscript j)       = 0;

};

/* cad
// Force compilation of template so it gets checked
int sum(const Array2d<int>&) { return 0; }
void f(const Array2d<int>& a) {
  average(a);
}
cad */
//cad #undef Array2d
///////////////////////////////////////////////////////////////////


template<class T> T sum(const Array2d<T>&);


template<class T>
T average(const Array2d<T>& a) {
    Array2d::EltT  s = sum(a);
    return s / a.numElts();
}

double average(const Array2d<float>& a) {
    double sum = 0;
    cerr << "explicit average called instead of template" << endl;
    for (Subscript i = a.shape(0) - 1; i >= 0; i--) {
        for (Subscript j = a.shape(1) - 1; j >= 0; j--) sum += a(i, j);
    }
    return sum / a.numElts();
}


int main() {

/* cad

FormedArray2d<double> a(2,3); // FormedArray2d<T> is in Array2d<T> category
                              // EltT set to double.
// ... set elements of a ...
istrstream in("[[1 2 3] [4 5 6]]");
in >> a;
double avg = average(a);      // average() returns double


  if (avg != 21.0 / 6.0) { cerr << "Bad average (" << avg << ")" << endl; return 1; }

  // Demonstrate danger of global function template: template gets expanded in preference
  // to reference conversion.  Should not print "explicit average" message above.

  FormedArray2d<float> b(10, 20);
  // ... set elements of b ...
  b = 0;
  average(b);

cad */
  return 0;

}

template<class T>
T sum(const Array2d<T>& a) {
  T s = 0;
  for (Subscript i = 0; i < a.shape(0); i++)
    for (Subscript j = 0; j < a.shape(1); j++) s += a(i,j);
  return s;
}



