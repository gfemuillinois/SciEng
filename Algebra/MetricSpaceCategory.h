/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef MetricSpaceCategoryH
#define MetricSpaceCategoryH

template<class V, class M>
class MetricSpaceCategory { 
public:
    // User Must Define: M dot(const V&) const;
    M norm() const;
    M cosAngle(const V& e) const;
    M angle(const V& e) const;
    friend M dot(const V& lhs, const V& rhs) { 
      //  cout << "MetricSpaceCategory::dot [friend]" << endl;
      return lhs.dot(rhs); }

};

#include <math.h>
                 
template<class V, class M>
inline
M MetricSpaceCategory<V,M>::norm() const {
  const V& vr = (const V&)(*this); 
  return sqrt( vr.dot(vr) );
}
  
template<class V, class M>
inline
M MetricSpaceCategory<V,M>::cosAngle(const V& e) const{
  const V& vr = (const V&)(*this); 

  // CAD
  return vr.dot(e) / ( norm() * e.norm() );

  //  return vr.dot( e / (norm() * e.norm()) );
}
  
  
template<class V, class M>
inline
M MetricSpaceCategory<V,M>::angle(const V& e) const {
  return acos(cosAngle(e));
}

#endif
