/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

template<class Domain, class Range>
class ArrayMapper :
  public virtual Functional<const Array1d<Domain>&, FormedArray1d<Range> > {
public:
  ArrayMapper(const Function<Domain,Range>& fin);
  FormedArray1d<Range> operator()(const Array1d<Domain>& a){
    return MappedArray1d<Domain,Range>(a, f);
    }
};

