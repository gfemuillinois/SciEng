/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef AccessedArray2dH
#define AccessedArray2dH

#include "Array/Array2d.h"

template<class T>
class AccessedConstArray2d :
  public virtual ConstArray2d<T> {
public:

  AccessedConstArray2d(ConstArray2d<T>* newed_a) : the_array(newed_a) {}
  ~AccessedConstArray2d() { delete the_array; }

  virtual Subscript         shape(Dimension d)   const { return the_array->shape(d); }
  virtual Subscript         numElts()            const { return the_array->numElts();  }
  
  virtual const EltT&       operator()(Subscript i, Subscript j) const { return (*the_array)(i,j); }
  
  virtual ConstProjectionT  project(Subscript i, Dimension d) const { return the_array->project(i,d); }
  
private:
  ConstArray2d<T>* the_array;
  AccessedConstArray2d(const AccessedConstArray2d<T>&);
};


template<class T>
class AccessedArray2d :
    public virtual Array2d<T> {
public:
    AccessedArray2d(Array2d<T>* newed_a) : the_array(newed_a) {}
    ~AccessedArray2d()  { delete the_array; }


    virtual Subscript         shape(Dimension d) const { return the_array->shape(d); }
    virtual Subscript         numElts()          const { return the_array->numElts();  }



    virtual const EltT& operator()(Subscript i, Subscript j) const { return (*the_array)(i, j); }
    virtual       EltT& operator()(Subscript i, Subscript j)       { return (*the_array)(i, j); }


    virtual ConstProjectionT  project(Subscript i, Dimension d) const { 
        const Array2d<T>* const_array = the_array;  // Invoke const version of project
        return const_array->project(i,d); 
    }
    virtual ProjectionT project(Subscript i, Dimension d) { return the_array->project(i, d); }


    virtual Array2d<T>& operator=(const ConstArray2d<T>& rhs) { return *the_array = rhs; }
    virtual Array2d<T>& operator=(const T& rhs)               { return *the_array = rhs; }

private:
    Array2d<T>* the_array;

    AccessedArray2d(const AccessedArray2d<T>&);  // Prohibit copy
};

#endif
