/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
template<class Array, class M>
M DistributingMetricSpace<Array,M>::dot(const Array& rhs) const { 

  // cout << "DistributingMetricSpace<Array,M>::dot" << endl;

    const Array& lhs = (const Array&)(*this);
    if ( ! hasSameShapeAs(lhs, rhs) ) throw ArrayErr::Shape();

    typename Array::BrowserType lhs_i(lhs);
    typename Array::BrowserType rhs_i(rhs);
    M result = M();
    for (; rhs_i.more(); rhs_i.advance(), lhs_i.advance()) { 
        result += ::dot(lhs_i.current(), rhs_i.current());
    }

    return result;
}
