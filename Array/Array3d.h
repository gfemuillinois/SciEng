/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef Array3dH
#define Array3dH

#include "Array/ArrayIterator3d.h"
#include "Array/AccessedArray2d.h"
   

template<class T>
class ConstArray3d :
  public ArrayShape {  
public:
    typedef T EltT;
    typedef AccessedConstArray2d<T> ConstProjectionT;
    typedef ArrayBrowser3d<ConstArray3d<T> > BrowserType;


    virtual const T&         operator()(Subscript i, Subscript j, Subscript k) const = 0;

    virtual ConstProjectionT project(Subscript i, Dimension d = 0)             const = 0;
    virtual ConstProjectionT operator[](Subscript i)                           const { return project(i, 0); }


    virtual Dimension dim() const { return 3; }


    virtual ConstProjectionT row(Subscript i)    const { return project(i, 0); }
    virtual ConstProjectionT column(Subscript i) const { return project(i, 1); }
    virtual ConstProjectionT plane(Subscript i)  const { return project(i, 2); }


private:
    void operator=(const ConstArray3d<T>&); // Prohibit
};


template<class T>
class Array3d :
    public ConstArray3d<T> {
public:
  virtual       T& operator()(Subscript i, Subscript j, Subscript k)       = 0;
  virtual const T& operator()(Subscript i, Subscript j, Subscript k) const = 0;

  typedef AccessedArray2d<T> ProjectionT;
  typedef ArrayIterator3d<Array3d<T> > IteratorType;
  
  virtual ProjectionT      project(Subscript i, Dimension d = 0) = 0;
  virtual ConstProjectionT project(Subscript i, Dimension d = 0) const = 0;
  virtual ConstProjectionT operator[](Subscript i)               const { return project(i,0); }
  virtual ProjectionT      operator[](Subscript i)                     { return project(i,0); }

  virtual ConstProjectionT row(Subscript i)    const { return project(i, 0); }
  virtual      ProjectionT row(Subscript i)          { return project(i, 0); }
  virtual ConstProjectionT column(Subscript i) const { return project(i, 1); }
  virtual      ProjectionT column(Subscript i)       { return project(i, 1); }
  virtual ConstProjectionT plane(Subscript i)  const { return project(i, 2); }
  virtual      ProjectionT plane(Subscript i)        { return project(i, 2); }

  virtual Array3d<T>& operator=(const ConstArray3d<T>& rhs);
  virtual Array3d<T>& operator=(const T& rhs);
};


template<class T>
istream& operator>>(istream& is, Array3d<T>& a);

template<class T>
ostream& operator<<(ostream& os, const ConstArray3d<T>& a);

#ifdef XLC_QNOTEMPINC
#include "Array/Array3d.c"
#endif

#endif

