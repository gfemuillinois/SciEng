/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef IsoMemberReducerH
#define IsoMemberReducerH

#include "Function/Functional.h"


template<class Browseable>
class IsoMemberReducer : 
    public virtual Functional<const Browseable&, Browseable::EltT > {
public:
    typedef Browseable::EltT Domain;
    IsoMemberReducer( void (Domain::*f)(Domain), const Domain& initial_value) : 
        the_f(f), 
        the_initial_value(initial_value){
    }

    virtual Domain operator()(const Browseable& b) const;

    // Access to reset initial-value.

    const Domain& operator()() const {return the_initial_value;}
    Domain&       operator()()       {return the_initial_value;}


protected:
    void (Domain::*the_f)(Domain);
    Domain the_initial_value;
};



template<class Browseable>
Browseable::EltT IsoMemberReducer<Browseable>::operator()(const Browseable& b_in) const { 
    Browseable::Browser<Domain> b(b_in);
    for(Domain result = the_initial_value; b.more(); b.next()){ 
        (result.*the_f)(b());
    }
    return result;
}

      
      
#endif
