/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef FormedPhysicalDataH
#define FormedPhysicalDataH

#include "DataModeling/PhysicalData.h"
#include "Array/ConcreteFormedArray1d.h"
#include "SciEng/String.h"
#include "Array/Array1d.h"


class FormedPhysicalDataBrowser :            
    public virtual PhysicalDataBrowser<double> {
public:

    virtual double  coordinate() const { return x_i.current();    }
    virtual double  value()      const { return y_i.current();    }
    virtual double  sigma()      const { return sigma_i.current();}

    virtual Boolean more()       const { return x_i.more();       }
    virtual void    advance()    { x_i.advance(); y_i.advance(); sigma_i.advance(); }


    FormedPhysicalDataBrowser( 
            const ConcreteFormedArray1d<double>& x,
            const ConcreteFormedArray1d<double>& y,
            const ConcreteFormedArray1d<double>& sigma
        ) :
        x_i(x), y_i(y), sigma_i(sigma) {
    }

private:
    typedef ConcreteFormedArray1d<double> ArrayImpl;
    ArrayImpl::BrowserType x_i;
    ArrayImpl::BrowserType y_i;
    ArrayImpl::BrowserType sigma_i;
};



class FormedPhysicalData :            
    public virtual PhysicalData<double> {
public:
    virtual AccessedPhysicalDataBrowser<double> browser() const { 
        return new FormedPhysicalDataBrowser(x, y, sigma);
    }
    virtual Subscript numElts() const { return x.numElts(); }

    class TooLittleDataInput :
        public SciEngErr {
    public:
        TooLittleDataInput();
        virtual String message() const;
    };

    FormedPhysicalData(std::istream& stream_in, unsigned int n_data_pts);
    FormedPhysicalData(    
        const ConstArray1d<double>& x_in,
        const ConstArray1d<double>& y_in,
        const ConstArray1d<double>& sigma_in
    );
    // ...
private:
    typedef ConcreteFormedArray1d<double> ArrayImpl;
    ArrayImpl x;                   
    ArrayImpl y;                   
    ArrayImpl sigma;
};



#endif
