/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch11/ArrayxD.h"


template<class T, Subscript n0, Subscript n1>
class RigidArray2d :
    public virtual Array2d<T> {
public:

    virtual Dimension dim()                                const { return 2; }
    virtual Subscript shape(Dimension d)                   const { return (d == 0) ? n0 : n1; }
    virtual const T&  operator()(Subscript i, Subscript j) const { return data[i][j]; }
    virtual T&        operator()(Subscript i, Subscript j)       { return data[i][j]; }


    virtual Array2d<T>& operator=(const Array2d<T>&);
    virtual Array2d<T>& operator=(const T&);

private:
    T data[n0][n1];
};


void f() {

  RigidArray2d<int, 3, 4> a;


  const int nrows = 3;
  RigidArray2d<int, nrows, 2 * nrows> b;

}
