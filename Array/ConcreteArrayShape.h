/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ConcreteArrayShapeH
#define ConcreteArrayShapeH

#include "Array/SubscriptArray.h"


template<Dimension ndim>
class ConcreteArrayShape {
public:
    ConcreteArrayShape(const SubscriptArray<ndim>&);
    ConcreteArrayShape() {} // Create uninitialized; call setShape to set.


    Dimension            dim()              const { return ndim;         }
    Subscript            shape(Dimension d) const { return the_shape(d); }
    Subscript            numElts()          const;
    void                 setShape(const SubscriptArray<ndim>& a);

protected:
    SubscriptArray<ndim> the_shape;
};

                         
template<Dimension ndim>
class ConcreteColumnMajorProjectionSubscriptor;


template<Dimension ndim>
class ConcreteColumnMajorSubscriptor :      
    public ConcreteArrayShape<ndim> {
public:
    ConcreteColumnMajorSubscriptor(const SubscriptArray<ndim>& s);
    ConcreteColumnMajorSubscriptor() {}

    typedef ConcreteColumnMajorProjectionSubscriptor<ndim-1> ProjectionT;
    ProjectionT projectionSubscriptor(Dimension d, Subscript s) const;

    Subscript   offset(const SubscriptArray<ndim>& s) const;
};



class ConcreteColumnMajorSubscriptor<1> :  
    public ConcreteArrayShape<1> {
public:

    ConcreteColumnMajorSubscriptor(const SubscriptArray<1>& s) : ConcreteArrayShape<1>(s) {}
    ConcreteColumnMajorSubscriptor()                                                      {}


    Subscript offset(const SubscriptArray<1>& s) const;
};


template<Dimension ndim>
class ConcreteRowMajorProjectionSubscriptor;

template<Dimension ndim>
class ConcreteRowMajorSubscriptor :
  public ConcreteArrayShape<ndim> {
public:
  ConcreteRowMajorSubscriptor(const SubscriptArray<ndim>& s);
  ConcreteRowMajorSubscriptor() {}
  typedef ConcreteRowMajorProjectionSubscriptor<ndim-1> ProjectionT;
  Subscript offset(const SubscriptArray<ndim>& s) const;
  ProjectionT projectionSubscriptor(Dimension d, Subscript s) const;
};

class ConcreteRowMajorSubscriptor<1> :
 public ConcreteArrayShape<1> {
public:
  ConcreteRowMajorSubscriptor(const SubscriptArray<1>& s) : ConcreteArrayShape<1>(s) {}
  ConcreteRowMajorSubscriptor() {}
  Subscript offset(const SubscriptArray<1>& s) const;
};


template<Dimension ndim>
class ConcreteStrides {      
public:
    ConcreteStrides(const SubscriptArray<ndim>& s) : the_strides(s) {}


    Subscript stride(Dimension d)                   const;
    Subscript offset(const SubscriptArray<ndim>& s) const;

protected:
    ConcreteStrides() {}
    SubscriptArray<ndim> the_strides;
};



template<Dimension ndim>
class ConcreteColumnMajorProjectionSubscriptor : 
    private ConcreteArrayShape<ndim>,
    private ConcreteStrides<ndim> {
public:
    ConcreteColumnMajorProjectionSubscriptor(
                         const SubscriptArray<ndim>& shape, 
                         const SubscriptArray<ndim>& strides
    );
    ConcreteColumnMajorProjectionSubscriptor() {}

    typedef ConcreteColumnMajorProjectionSubscriptor<ndim-1> ProjectionT;

    ConcreteArrayShape<ndim>::dim;
    ConcreteArrayShape<ndim>::shape;
    ConcreteArrayShape<ndim>::numElts;
    ConcreteArrayShape<ndim>::setShape;
    ConcreteStrides<ndim>::offset;

    ProjectionT projectionSubscriptor(Dimension d, Subscript s) const;
};



class ConcreteColumnMajorProjectionSubscriptor<1> : 
    private ConcreteArrayShape<1>,
    private ConcreteStrides<1> {
public:
    ConcreteColumnMajorProjectionSubscriptor(
                         const SubscriptArray<1>& shape, 
                         const SubscriptArray<1>& strides
    );
    ConcreteColumnMajorProjectionSubscriptor() {}

    ConcreteArrayShape<1>::dim;
    ConcreteArrayShape<1>::shape;
    ConcreteArrayShape<1>::numElts;
    ConcreteArrayShape<1>::setShape;
    ConcreteStrides<1>::offset;
};


template<Dimension ndim>
class ConcreteRowMajorProjectionSubscriptor :
  private ConcreteArrayShape<ndim>,
  private ConcreteStrides<ndim> {
public:
  ConcreteRowMajorProjectionSubscriptor(const SubscriptArray<ndim>& shape, const SubscriptArray<ndim>& strides);
  ConcreteRowMajorProjectionSubscriptor() {}
  
  typedef ConcreteRowMajorProjectionSubscriptor<ndim-1> ProjectionT;

  ConcreteArrayShape<ndim>::dim;
  ConcreteArrayShape<ndim>::shape;
  ConcreteArrayShape<ndim>::numElts;
  ConcreteArrayShape<ndim>::setShape;
  ConcreteStrides<ndim>::offset;
  
  ProjectionT projectionSubscriptor(Dimension d, Subscript s) const;
};

class ConcreteRowMajorProjectionSubscriptor<1> :
  private ConcreteArrayShape<1>,
  private ConcreteStrides<1> {
public:
  ConcreteRowMajorProjectionSubscriptor(const SubscriptArray<1>& shape, const SubscriptArray<1>& strides);
  ConcreteRowMajorProjectionSubscriptor() {}
  
  ConcreteArrayShape<1>::dim;
  ConcreteArrayShape<1>::shape;
  ConcreteArrayShape<1>::numElts;
  ConcreteArrayShape<1>::setShape;
  ConcreteStrides<1>::offset;
};


template<Dimension ndim>
inline
Subscript ConcreteColumnMajorSubscriptor<ndim>::offset(const SubscriptArray<ndim>& s) const {
    Dimension n = ndim;
    Subscript off = 0;
    while (n-- > 0) off = off * shape(n) + s(n);
    return off;
}


template<Dimension ndim>
inline
Subscript ConcreteRowMajorSubscriptor<ndim>::offset(const SubscriptArray<ndim>& s) const {
    Subscript off = s(0);
    for (Dimension i = 1; i < ndim; i++) {
                         off = off * shape(i) + s(i);
    }
    return off;
}


template<Dimension ndim>
inline
Subscript ConcreteStrides<ndim>::offset(const SubscriptArray<ndim>& s) const { 
    Subscript off = 0;
    Dimension d = ndim; 
    while (d-- > 0) off += stride(d) * s(d);
    return off;
}


class Boolean;

template<class LHSArrayShape, class RHSArrayShape>
Boolean hasSameShapeAs(const LHSArrayShape& lhs, const RHSArrayShape& rhs);

#ifdef XLC_QNOTEMPINC
#include "Array/ConcreteArrayShape.c"
#endif

#endif
