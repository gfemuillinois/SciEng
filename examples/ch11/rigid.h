/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

#ifndef RIGIDHPP
#define RIGIDHPP

template<class T, int n0, int n1>
class RigidArray2d {

public:

    virtual int dim()                              const { return 2; }
    virtual int shape(int d)                   const { return (d == 0) ? n0 : n1; }
    virtual const T&  operator()(int i, int j) const { return data[i][j]; }
    virtual T&        operator()(int i, int j)       { return data[i][j]; }


  //    virtual Array2d<T>& operator=(const Array2d<T>&);
  //    virtual Array2d<T>& operator=(const T&);

private:
    T data[n0][n1];
};


#endif
