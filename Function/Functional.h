/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef FunctionalH
#define FunctionalH


template<class Domain, class Range>
class Functional {   
public:
    virtual Range operator()(const Domain&) const = 0;
    virtual Functional<Domain, Range>* clone() const = 0; // Must be overridden!
    virtual ~Functional(){};
};



template<class Domain>
class IsoFunctional :
    public virtual Functional<Domain, Domain> {
public:
    virtual IsoFunctional<Domain>* clone() const = 0; // Must be overridden!
};


template<class Domain, class Range>
class Functional2 {   
public:
    virtual Range operator()(const Domain&, const Domain&) const = 0;
    virtual ~Functional2(){};
};

template<class Domain>
class IsoFunctional2 :
   public virtual Functional2<Domain, Domain> {
};

#endif
