/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef PhysicalDataH
#define PhysicalDataH


#include "SciEng/CountedObjPtr.h"
#include "SciEng/Subscript.h"


template<class T>
class PhysicalDataBrowser {  
public:

    virtual T            coordinate()  const = 0;
    virtual T            value()       const = 0;
    virtual T            sigma()       const = 0;

    virtual Boolean      more()        const = 0;
    virtual void         advance()     = 0;
    virtual ~PhysicalDataBrowser() {}

};



template<class T>
class AccessedPhysicalDataBrowser :
  public virtual PhysicalDataBrowser<T> {  
public:
    AccessedPhysicalDataBrowser(PhysicalDataBrowser<T>* just_newed) : the_browser(just_newed) {}


    virtual T        coordinate() const { return the_browser->coordinate(); }
    virtual T        value()      const { return the_browser->value(); }
    virtual T        sigma()      const { return the_browser->sigma(); }

    virtual Boolean  more()       const { return the_browser->more(); }
    virtual void     advance()    { the_browser->advance(); }

private:
    CountedObjPtr< PhysicalDataBrowser<T> > the_browser;
};



template<class T>
class PhysicalData {  
public:

    virtual AccessedPhysicalDataBrowser<T> browser() const = 0;
    virtual Subscript                      numElts() const = 0;

    virtual ~PhysicalData() {}
};




#endif
