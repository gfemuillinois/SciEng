/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef DataModelParametersH
#define DataModelParametersH

#include "Array/FormedArray.h"
#include "SciEng/Ptrs.h"
#include "DataModeling/ModelParameter.h"



template<class RallT, class T>
class DataModelParameters : 
    public virtual Array1d<T> {
public:
    DataModelParameters(Subscript nparms) : parms(nparms) { 
        for(int i = 0; i < nparms; i++) parms(i) = ModelParameter<RallT>(0., i, nparms);
    }

    virtual Subscript    shape(Dimension d)                    const { return parms.shape(d); }
    virtual const T&     operator()(Subscript s)               const { return parms(s).value().value(); }
    virtual       T&     operator()(Subscript s)                     { return parms(s).value().value(); }
    virtual Array1d<T>&  operator=(const ConstArray1d<T>& rhs)       { return Array1d<T>::operator=(rhs); }
    virtual Array1d<T>&  operator=(const T& rhs)                     { return Array1d<T>::operator=(rhs); }



    const Array1d< ModelParameter<RallT> >& parameters() const { return parms; }
          Array1d< ModelParameter<RallT> >& parameters()       { return parms; }


private:
    FormedArray1d< ModelParameter<RallT>  > parms;
};


#endif
