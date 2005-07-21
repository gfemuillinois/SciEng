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

#ifdef SCIENG_CHECK_SUBSCRIPTS
#include <assert.h>
#include <iostream>
#endif

#include "Array/SubscriptArray.h"

//namespace SciEngLib {

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

template<>
class ConcreteArrayShape<1> {
public:
  inline explicit  ConcreteArrayShape(const SubscriptArray<1>&);
  inline explicit  ConcreteArrayShape(const Subscript);
  ConcreteArrayShape() {} // Create uninitialized; call setShape to set.

  Dimension            dim()              const { return 1;         }
  Subscript            shape(Dimension d) const { return the_shape; }
  Subscript            numElts()          const { return the_shape; }
  void                 setShape(const Subscript a) { the_shape = a; }

protected:
  Subscript the_shape;
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
// ***************************************************

template<>
class ConcreteColumnMajorSubscriptor<1> :  
    public ConcreteArrayShape<1> {
public:

    ConcreteColumnMajorSubscriptor(const SubscriptArray<1>& s) : 
      ConcreteArrayShape<1>(s) {}
    ConcreteColumnMajorSubscriptor() {}

  //    Subscript offset(const SubscriptArray<1>& s) const { return s(0); }
    Subscript offset(const Subscript s) const { 
#ifdef SCIENG_CHECK_SUBSCRIPTS
      if ( s<0 || s >= shape(0) ) {
	std::cerr << "ConcreteColumnMajorSubscriptor<1>::offset: Invalid arg: " << s
	     << "\nshape(0) = " << shape(0) << std::endl;
	assert(0);
      }
#endif
    return s; }

};
// ***************************************************

template<>
class ConcreteColumnMajorSubscriptor<2> :  
  public ConcreteArrayShape<2> {
public:

  ConcreteColumnMajorSubscriptor(const SubscriptArray<2>& s) : 
    ConcreteArrayShape<2>(s) {}
  ConcreteColumnMajorSubscriptor() {}

  typedef ConcreteColumnMajorProjectionSubscriptor<1> ProjectionT;
  inline ProjectionT projectionSubscriptor(Dimension d, Subscript s) const;

  Subscript offset(const SubscriptArray<2>& s) const { // TBremoved
#ifdef SCIENG_CHECK_SUBSCRIPTS
    if ( s(0)<0 || s(0)>= shape(0) || s(1)<0 || s(1)>= shape(1) ) {
      std::cerr << "ConcreteColumnMajorSubscriptor<2>::offset: Invalid args: " 
	   << s(0) << "  " << s(1) << "\nshape(0) = " << shape(0) 
	   << " shape(1) = " << shape(1) << std::endl;
      assert(0);
    }
#endif    
    return shape(0) * s(1) + s(0); }

  Subscript offset(const Subscript s0, const Subscript s1) const { 
#ifdef SCIENG_CHECK_SUBSCRIPTS
    if ( s0<0 || s0>= shape(0) || s1<0 || s1 >= shape(1) ) {
      std::cerr << "ConcreteColumnMajorSubscriptor<2>::offset: Invalid args: " 
	   << s0 << "  " << s1 << "\nshape(0) = " << shape(0) 
	   << " shape(1) = " << shape(1) << std::endl;
      assert(0);
    }
#endif
    return shape(0) * s1 + s0; }

};
// ***************************************************

template<>
class ConcreteColumnMajorSubscriptor<3> :  
  public ConcreteArrayShape<3> {
public:

  ConcreteColumnMajorSubscriptor(const SubscriptArray<3>& s) : 
    ConcreteArrayShape<3>(s) {}
  ConcreteColumnMajorSubscriptor() {}

  typedef ConcreteColumnMajorProjectionSubscriptor<2> ProjectionT;
  inline ProjectionT projectionSubscriptor(Dimension d, Subscript s) const;

  Subscript offset(const SubscriptArray<3>& s) const { // TBremoved
#ifdef SCIENG_CHECK_SUBSCRIPTS
    if ( s(0)<0 || s(0)>= shape(0) || s(1)<0 || s(1)>= shape(1) ||
	 s(2)<0 || s(2)>= shape(2) ) {
      std::cerr << "ConcreteColumnMajorSubscriptor<3>::offset: Invalid args: " 
		<< s(0) << "  " << s(1) << "  " << s(2) 
		<< "\nshape(0) = " << shape(0) << " shape(1) = " << shape(1)
		<< " shape(2) = " << shape(2) << std::endl;
      assert(0);
    }
#endif    
    return shape(0)*(shape(1)*s(2) + s(1)) + s(0); }

  Subscript offset(const Subscript s0, const Subscript s1, const Subscript s2)
    const { 
#ifdef SCIENG_CHECK_SUBSCRIPTS
    if ( s0<0 || s0>= shape(0) || s1<0 || s1 >= shape(1) || 
	 s2<0 || s2 >= shape(2)) {
      std::cerr << "ConcreteColumnMajorSubscriptor<3>::offset: Invalid args: " 
		<< s0 << "  " << s1 << "  " << s2 
		<< "\nshape(0) = " << shape(0) << " shape(1) = " << shape(1)
		<< " shape(2) = " << shape(2) << std::endl;
      assert(0);
    }
#endif
    return shape(0)*(shape(1)*s2 + s1) + s0; }

};
// ***************************************************

template<Dimension ndim>
class ConcreteRowMajorProjectionSubscriptor;

template<Dimension ndim>
class ConcreteRowMajorSubscriptor :
  public ConcreteArrayShape<ndim> {
public:
  ConcreteRowMajorSubscriptor(const SubscriptArray<ndim>& s);
  ConcreteRowMajorSubscriptor() {}

  typedef ConcreteRowMajorProjectionSubscriptor<ndim-1> ProjectionT;
  ProjectionT projectionSubscriptor(Dimension d, Subscript s) const;

  Subscript offset(const SubscriptArray<ndim>& s) const;
};
// ***************************************************

template<>
class ConcreteRowMajorSubscriptor<1> :
 public ConcreteArrayShape<1> {
public:
  ConcreteRowMajorSubscriptor(const SubscriptArray<1>& s) : 
    ConcreteArrayShape<1>(s) {}
  ConcreteRowMajorSubscriptor() {}

  //  Subscript offset(const SubscriptArray<1>& s) const { return s(0);  }
  Subscript offset(const Subscript s) const {
#ifdef SCIENG_CHECK_SUBSCRIPTS
    if ( s<0 || s >= shape(0) ) {
      std::cerr << "ConcreteRowMajorSubscriptor<1>::offset: Invalid arg: " << s
	   << "\nshape(0) = " << shape(0) << std::endl;
      assert(0);
    }
#endif
    return s;  }

};
// ***************************************************

template<>
class ConcreteRowMajorSubscriptor<2> :  
  public ConcreteArrayShape<2> {
public:

  ConcreteRowMajorSubscriptor(const SubscriptArray<2>& s) : 
    ConcreteArrayShape<2>(s) {}
  ConcreteRowMajorSubscriptor() {}

  typedef ConcreteRowMajorProjectionSubscriptor<1> ProjectionT;
  inline ProjectionT projectionSubscriptor(Dimension d, Subscript s) const;

  Subscript offset(const SubscriptArray<2>& s) const { // TBremoved
#ifdef SCIENG_CHECK_SUBSCRIPTS
    if ( s(0)<0 || s(0) >= shape(0) || s(1)<0 || s(1) >= shape(1) ) {
      std::cerr << "ConcreteRowMajorSubscriptor<2>::offset: Invalid args: " 
	   << s(0) << "  " << s(1) << "\nshape(0) = " << shape(0) 
	   << " shape(1) = " << shape(1) << std::endl;
      assert(0);
    }
#endif    
    return shape(1) * s(0) + s(1); }

  Subscript offset(const Subscript s0, const Subscript s1) const {
#ifdef SCIENG_CHECK_SUBSCRIPTS
    if ( s0<0 || s0>= shape(0) || s1<0 || s1 >= shape(1) ) {
      std::cerr << "ConcreteRowMajorSubscriptor<2>::offset: Invalid args: " 
	   << s0 << "  " << s1 << "\nshape(0) = " << shape(0) 
	   << " shape(1) = " << shape(1) << std::endl;
      assert(0);
    }
#endif
    return shape(1) * s0 + s1; }
};
// ***************************************************

template<>
class ConcreteRowMajorSubscriptor<3> :  
  public ConcreteArrayShape<3> {
public:
  ConcreteRowMajorSubscriptor(const SubscriptArray<3>& s) : 
    ConcreteArrayShape<3>(s) {}
  ConcreteRowMajorSubscriptor() {}

  typedef ConcreteRowMajorProjectionSubscriptor<2> ProjectionT;
  inline ProjectionT projectionSubscriptor(Dimension d, Subscript s) const;

  Subscript offset(const SubscriptArray<3>& s) const { // TBremoved
#ifdef SCIENG_CHECK_SUBSCRIPTS
    if ( s(0)<0 || s(0) >= shape(0) || s(1)<0 || s(1) >= shape(1) ||
	 s(2)<0 || s(2) >= shape(2) ) {
      std::cerr << "ConcreteRowMajorSubscriptor<3>::offset: Invalid args: " 
		<< s(0) << "  " << s(1) << "  " << s(2) 
		<< "\nshape(0) = " << shape(0) << " shape(1) = " << shape(1)
		<< " shape(2) = " << shape(2) << std::endl;
      assert(0);
    }
#endif    
    return shape(2)*(shape(1)*s(0) + s(1)) + s(2); }

  Subscript offset(const Subscript s0, const Subscript s1, const Subscript s2)
 const {
#ifdef SCIENG_CHECK_SUBSCRIPTS
    if ( s0<0 || s0>= shape(0) || s1<0 || s1 >= shape(1) ||
	 s2<0 || s2 >= shape(2) ) {
      std::cerr << "ConcreteRowMajorSubscriptor<3>::offset: Invalid args: " 
		<< s0 << "  " << s1 << "  " << s2 
		<< "\nshape(0) = " << shape(0) << " shape(1) = " << shape(1)
		<< " shape(2) = " << shape(2) << std::endl;
      assert(0);
    }
#endif
    //    return shape(2)*(shape(1)*s0 + s1) + s2; }
    return shape(2)*shape(1)*s0 + shape(2)*s1 + s2; }
};
// ***************************************************


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

template<>
class ConcreteStrides<1> {      
public:
  ConcreteStrides(const SubscriptArray<1>& s) : the_stride( s(0) ) {}

  Subscript stride(Dimension )                 const { return the_stride; }

  // Subscript offset(const SubscriptArray<1>& s) const { return stride(0)*s(0); }
  Subscript offset(const Subscript s) const { return stride(0)*s; };

protected:
    ConcreteStrides() {}
    Subscript the_stride;
};

template<>
class ConcreteStrides<2> {      
public:
  ConcreteStrides(const SubscriptArray<2>& s) : the_strides(s) {}

  Subscript stride(Dimension d)   const { return the_strides(d); }

  Subscript offset(const SubscriptArray<2>& s) const {
    return stride(0) * s(0) + stride(1) * s(1); }
  Subscript offset(const Subscript s0, const Subscript s1) const {
    return stride(0) * s0 + stride(1) * s1; }

protected:
    ConcreteStrides() {}
    SubscriptArray<2> the_strides;
};

template<>
class ConcreteStrides<3> {      
public:
  ConcreteStrides(const SubscriptArray<3>& s) : the_strides(s) {}

  Subscript stride(Dimension d)   const { return the_strides(d); }

  Subscript offset(const SubscriptArray<3>& s) const {
    return stride(0) * s(0) + stride(1) * s(1) + stride(2) * s(2); }
  Subscript offset(const Subscript s0, const Subscript s1, const Subscript s2) 
    const {  return stride(0) * s0 + stride(1) * s1 + stride(2) * s2; }

protected:
    ConcreteStrides() {}
    SubscriptArray<3> the_strides;
};
// ***************************************************

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
// ***************************************************

template<>
class ConcreteColumnMajorProjectionSubscriptor<1> : 
    private ConcreteArrayShape<1>,
    private ConcreteStrides<1> {
public:
  ConcreteColumnMajorProjectionSubscriptor( const SubscriptArray<1>& shape, 
					    const SubscriptArray<1>& strides )
    : ConcreteArrayShape<1>(shape), ConcreteStrides<1>(strides) { }


    ConcreteColumnMajorProjectionSubscriptor() {}

    ConcreteArrayShape<1>::dim;
    ConcreteArrayShape<1>::shape;
    ConcreteArrayShape<1>::numElts;
    ConcreteArrayShape<1>::setShape;

    ConcreteStrides<1>::offset;
};
// ***************************************************

template<>
class ConcreteColumnMajorProjectionSubscriptor<2> : 
    private ConcreteArrayShape<2>,
    private ConcreteStrides<2> {
public:
    ConcreteColumnMajorProjectionSubscriptor(const SubscriptArray<2>& shape, 
					     const SubscriptArray<2>& strides)
      : ConcreteArrayShape<2>(shape), ConcreteStrides<2>(strides) {}

    ConcreteColumnMajorProjectionSubscriptor() {}

    typedef ConcreteColumnMajorProjectionSubscriptor<1> ProjectionT;

    ConcreteArrayShape<2>::dim;
    ConcreteArrayShape<2>::shape;
    ConcreteArrayShape<2>::numElts;
    ConcreteArrayShape<2>::setShape;
    ConcreteStrides<2>::offset;

    inline ProjectionT projectionSubscriptor(Dimension d, Subscript s) const;
};
// ***************************************************

template<Dimension ndim>
class ConcreteRowMajorProjectionSubscriptor :
  private ConcreteArrayShape<ndim>,
  private ConcreteStrides<ndim> {
public:
  ConcreteRowMajorProjectionSubscriptor(const SubscriptArray<ndim>& shape, 
					const SubscriptArray<ndim>& strides);
  ConcreteRowMajorProjectionSubscriptor() {}
  
  typedef ConcreteRowMajorProjectionSubscriptor<ndim-1> ProjectionT;

  ConcreteArrayShape<ndim>::dim;
  ConcreteArrayShape<ndim>::shape;
  ConcreteArrayShape<ndim>::numElts;
  ConcreteArrayShape<ndim>::setShape;
  ConcreteStrides<ndim>::offset;
  
  ProjectionT projectionSubscriptor(Dimension d, Subscript s) const;
};
// ***************************************************

template<>
class ConcreteRowMajorProjectionSubscriptor<1> :
  private ConcreteArrayShape<1>,
  private ConcreteStrides<1> {
public:
  ConcreteRowMajorProjectionSubscriptor(const SubscriptArray<1>& shape, 
					const SubscriptArray<1>& strides)
    : ConcreteArrayShape<1>(shape), ConcreteStrides<1>(strides) { }

  ConcreteRowMajorProjectionSubscriptor() {}
  
  ConcreteArrayShape<1>::dim;
  ConcreteArrayShape<1>::shape;
  ConcreteArrayShape<1>::numElts;
  ConcreteArrayShape<1>::setShape;

  ConcreteStrides<1>::offset;
};
// ***************************************************

template<>
class ConcreteRowMajorProjectionSubscriptor<2> :
  private ConcreteArrayShape<2>,
  private ConcreteStrides<2> {
public:
  ConcreteRowMajorProjectionSubscriptor(const SubscriptArray<2>& shape, 
					const SubscriptArray<2>& strides)
    : ConcreteArrayShape<2>(shape), ConcreteStrides<2>(strides) { }
  ConcreteRowMajorProjectionSubscriptor() {}
  
  typedef ConcreteRowMajorProjectionSubscriptor<1> ProjectionT;

  ConcreteArrayShape<2>::dim;
  ConcreteArrayShape<2>::shape;
  ConcreteArrayShape<2>::numElts;
  ConcreteArrayShape<2>::setShape;
  ConcreteStrides<2>::offset;

  inline ProjectionT projectionSubscriptor(Dimension d, Subscript s) const;
};

// ***************************************************
// ***************************************************

template<Dimension ndim>
inline
Subscript ConcreteColumnMajorSubscriptor<ndim>::
offset(const SubscriptArray<ndim>& s) const {
  Dimension n = ndim;
  Subscript off = 0;

  while (n-- > 0) { 
#ifdef SCIENG_CHECK_SUBSCRIPTS
    if ( s(n)<0 || s(n)>= shape(n) ) {
      std::cerr << "ConcreteColumnMajorSubscriptor<ndim>::offset: Invalid arg:"
		<< "\nn = " << n
		<< " s(n) = " << s(n) << "  shape(n) = " << shape(n)
		<< std::endl;
      assert(0);
    }
#endif
    off = off * shape(n) + s(n); 
  }
  return off;
}
// ***************************************************

template<Dimension ndim>
inline
Subscript ConcreteRowMajorSubscriptor<ndim>::
offset(const SubscriptArray<ndim>& s) const {

  Subscript off = s(0);
#ifdef SCIENG_CHECK_SUBSCRIPTS
  if ( s(0)<0 || s(0)>= shape(0) ) {
    std::cerr << "ConcreteRowMajorSubscriptor<ndim>::offset: Invalid arg:"
	 << "\ns(0) = " << s(0) << "  shape(0) = " << shape(0) << std::endl;
    assert(0);
  }
#endif

  for (Dimension i = 1; i < ndim; i++) {
#ifdef SCIENG_CHECK_SUBSCRIPTS
    if ( s(i)<0 || s(i)>= shape(i) ) {
      std::cerr << "ConcreteRowMajorSubscriptor<ndim>::offset: Invalid arg:\n"
	   << "i = " << i
	   << " s(i) = " << s(i) << "  shape(i) = " << shape(i) << std::endl;
      assert(0);
    }
#endif

    off = off * shape(i) + s(i);
  }
  return off;
}
// ***************************************************

template<Dimension ndim>
inline
Subscript ConcreteStrides<ndim>::offset(const SubscriptArray<ndim>& s) const { 
    Subscript off = 0;
    Dimension d = ndim; 
    while (d-- > 0) off += stride(d) * s(d);
    return off;
}
// ***************************************************

class Boolean;

template<class LHSArrayShape, class RHSArrayShape>
Boolean hasSameShapeAs(const LHSArrayShape& lhs, const RHSArrayShape& rhs);

//}

#ifdef XLC_QNOTEMPINC
#include "Array/ConcreteArrayShape.c"
#endif

#endif
