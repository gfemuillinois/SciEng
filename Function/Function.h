/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef FunctionH
#define FunctionH

#include "Function/Functional.h"
#include "SciEng/Fallible.h"
#include "SciEng/Ptrs.h"

class UnsetPtrErr : public SciEngErr {
public:
  virtual String message() const;
};


template<class Domain, class Range>
class Function :
    public  virtual  Functional<Domain, Range> {
public:

    Function( Range (*f)(Domain) ) : pf(f)           {}
    Function()                     : pf(unsetPtrErr) {}



    const Function<Domain, Range>& operator=(const Function<Domain, Range>& f) { pf = f.pf; return *this; }
    const Function<Domain, Range>& operator=(Range (*f)(Domain))               { pf = f;    return *this; }


    virtual Range operator()(const Domain& x) const { return pf(x); }

    virtual Function<Domain, Range>* clone() const { return new Function<Domain, Range>(*this); }

    static Range unsetPtrErr(Domain);  // Throws UnsetPtrErr
protected:
    Range (*pf)(Domain);
};



template<class Domain>
class IsoFunction :
    public virtual IsoFunctional<Domain>,
    private Function<Domain, Domain> {
public:
    IsoFunction( Domain(*f)(Domain) ): Function<Domain,Domain>(f) {}
    using Function<Domain, Domain>::operator();
    virtual IsoFunction<Domain>* clone() const { return new IsoFunction<Domain>(*this); }
};


template<class Domain, class Range>
class Function2 :
    public  virtual  Functional2<Domain, Range> {
public:
    Function2 ( Range (*f)(Domain, Domain) ) : pf(f) {}
    virtual Range operator()(const Domain& x1, const Domain& x2) const { return (*pf)(x1, x2); }
protected:
    Range(*pf)(Domain, Domain);
};

template<class Domain>
class IsoFunction2 :
    public virtual IsoFunctional2<Domain>,
    public Function2<Domain, Domain> {
public:
    IsoFunction2( Domain(*f)(Domain, Domain) ): Function2<Domain,Domain>(f) {}
};



template<class Domain, class Range>
class FunctionOfRef :
    public  virtual  Functional<Domain, Range> {
public:
    FunctionOfRef( Range (*f)(const Domain&) ) : pf(f) {}
    FunctionOfRef() : pf(unsetPtrErr) {}

    const FunctionOfRef<Domain, Range>& operator=( Range (*f)(const Domain&) ) { 
    pf = f; 
    return *this;
    }

    const FunctionOfRef<Domain, Range>& operator=( const FunctionOfRef<Domain, Range>& f ) { 
    pf = f.pf; 
    return *this;
    }

    virtual Range operator()(const Domain& x) const { return (*pf)(x); }
    virtual FunctionOfRef<Domain, Range>* clone() const { return new FunctionOfRef<Domain, Range>(*this); }
    static Range unsetPtrErr(const Domain&);  // Throws UnsetPtrErr
protected:
    Range (*pf)(const Domain&);
};


template<class Domain, class Range>
Range FunctionOfRef<Domain, Range>::unsetPtrErr(const Domain&) {
  throw UnsetPtrErr();
  return *(Range*)0;  // gotta fool a compiler...
}

template<class Domain, class Range>
Range Function<Domain, Range>::unsetPtrErr(Domain) {
  throw UnsetPtrErr();
  return *(Range*)0;  // gotta fool a compiler...
}
      
      

template<class Domain, class Range>
class ConversionFunctional :
  public  virtual  Functional<Domain, Range> {
public:
    virtual Range operator()(const Domain& x) const {return Range(x);}
};

template<class D>
  class VoidFunction : public  Function<void,D> {
    public:
      VoidFunction( D(*f)(D) ):Function<D,D>(f){}
      void operator()(const D& x) const { (*pf)(x);}
    protected:
      void (*pf)(D) ;
};

#include "SciEng/Boolean.h"
#include "SciEng/SciEngErr.h"
#include "SciEng/EquivalentCategory.h"


template<class D,class R>
class CheckedFunction : 
    public  virtual  Functional<D,R>,
    public  EquivalentCategory< CheckedFunction<D,R> > {
public:
      typedef R (*FunctionType)(const D&);
      CheckedFunction ( FunctionType f ) :
        pf(f){
        if(f==0) pf.invalidate();
      }
      CheckedFunction () : pf() {}
      void operator=( FunctionType f ){pf=f;}
      
      R operator()(const D& x) const  {
        if (pf.failed()) throw UnsetPtrErr();
        return pf(x);
      }
    virtual CheckedFunction<D, R>* clone() const { return new CheckedFunction<D, R>(*this); }
      
      Boolean equivalentTo(const CheckedFunction<D,R>& rhs) const {
        return (pf.failed() && rhs.pf.failed()) || (FunctionType(pf) == FunctionType(rhs.pf));
      }
    protected:
      Fallible< FunctionType > pf;

};

template<class D>
  class CheckedIsoFunction : public  CheckedFunction<D,D> {
    public:
      CheckedIsoFunction( D(*f)(D) ):CheckedFunction<D,D>(f){}
};

template<class R,class D>
class CheckedBuiltInFunction :
    public  virtual  Functional<R,D>,
    public  EquivalentCategory< CheckedBuiltInFunction<R,D> > {
public:
      typedef R (*FunctionType)(D);
      CheckedBuiltInFunction ( FunctionType f ) :
        pf(f){
        if(f==0)pf.invalidate();
      }
      CheckedBuiltInFunction () : pf(){}
      void operator=( FunctionType f ){pf=f;}
      
      R operator()(const D& x) const {
        if (pf.failed()) throw UnsetPtrErr();
        return pf(x);
      }
     virtual CheckedBuiltInFunction<D, R>* clone() const { return new CheckedBuiltInFunction<D, R>(*this); }
      
      Boolean equivalentTo(const CheckedBuiltInFunction<R,D>& rhs) const {
        return (pf.failed() && rhs.pf.failed()) || (FunctionType(pf) == FunctionType(rhs.pf));
      }
    protected:
      Fallible< FunctionType > pf;

};

template<class D>
class CheckedBuiltInIsoFunction : 
  public  CheckedBuiltInFunction<D,D> {
public:
      CheckedBuiltInIsoFunction( D(*f)(D) ):CheckedBuiltInFunction<D,D>(f){}
     virtual CheckedBuiltInIsoFunction<D>* clone() const { return new CheckedBuiltInIsoFunction<D>(*this); }
};

template<class D>
inline IsoFunction<D> function( D(*f)(const D&) ){
  return IsoFunction<D>(f);
  }
  
template<class R,class D>
inline Function<R,D> function( R(*f)(const D&) ){
  return Function<R,D>(f);
  }

#endif
