/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Algebra/DivisionAlgebraCategory.h"
#include "Function/Functional.h"
#include "SciEng/Ptrs.h"

template<class D>
class ZeroIsoFunctional :
    public IsoFunctional<D> {
public:
    ZeroIsoFunctional(){ }
    virtual D operator()(D v) const { return 0.0; }
};


template<class D>
class OneIsoFunctional :
    public IsoFunctional<D> {
public:
    OneIsoFunctional(){ }
    virtual D operator()(D v) const { return 1.0; }
};

template<class D>
class XIsoFunctional :
     public IsoFunctional<D> {
public:
    XIsoFunctional(){}
    virtual D operator()(D v) const {return v;}
};

template<class D>
class ConstantIsoFunctional :
    public IsoFunctional<D> {
public:
    ConstantIsoFunctional(const D& r) : r_(r){ }
    virtual D operator()(D v) const { return r_; }
private:
    D r_;
};

template<class D>
class BinaryIsoFunctional {
public:
    BinaryIsoFunctional(const CopiedBasePtr<IsoFunctional<D> >& lhs,
                          const CopiedBasePtr<IsoFunctional<D> >& rhs):
      the_lhs(lhs),
      the_rhs(rhs){
    }
    const IsoFunctional<D>& lhs() const { return *the_lhs;}
    const IsoFunctional<D>& rhs() const { return *the_rhs;}
private:
    CopiedBasePtr<IsoFunctional<D> > the_lhs;
    CopiedBasePtr<IsoFunctional<D> > the_rhs;
};

template<class D>
class AddIsoFunctional :
    public IsoFunctional<D>,
    protected BinaryIsoFunctional<D> {
public:
    AddIsoFunctional(const CopiedBasePtr<IsoFunctional<D> >& lhs, const CopiedBasePtr<IsoFunctional<D> >& rhs):
      BinaryIsoFunctional<D>(lhs,rhs){
    }
    virtual D operator()(D v) const {
       D s = lhs()(v);
       s += rhs()(v);
       return s;
    }
};
    

template<class D>
class SubtractIsoFunctional :
    public IsoFunctional<D>,
    protected BinaryIsoFunctional<D> {
public:
    SubtractIsoFunctional(const CopiedBasePtr<IsoFunctional<D> >& lhs, const CopiedBasePtr<IsoFunctional<D> >& rhs):
      BinaryIsoFunctional<D>(lhs,rhs){
    }
    virtual D operator()(D v) const {
       D s = lhs()(v);
       s -= rhs()(v);
       return s;
    }
};

template<class D>
class MultiplyIsoFunctional :
    public IsoFunctional<D>,
    protected BinaryIsoFunctional<D> {
public:
    MultiplyIsoFunctional(const CopiedBasePtr<IsoFunctional<D> >& lhs, const CopiedBasePtr<IsoFunctional<D> >& rhs):
      BinaryIsoFunctional<D>(lhs,rhs){
    }
    MultiplyIsoFunctional(const CopiedBasePtr<IsoFunctional<D> >& lhs, const D& rhs):
      BinaryIsoFunctional<D>(
        lhs,
        InterfacedObjPtr< IsoFunctional<D>, ConstantIsoFunctional<D> >(new ConstantIsoFunctional<D>(rhs))
      ) {
    }
    virtual D operator()(D v) const {
       D s = lhs()(v);
       s *= rhs()(v);
       return s;
    }
};

template<class D>
class DivideIsoFunctional :
    public IsoFunctional<D>,
    protected BinaryIsoFunctional<D> {
public:
    DivideIsoFunctional(const CopiedBasePtr<IsoFunctional<D> >& lhs, const CopiedBasePtr<IsoFunctional<D> >& rhs):
      BinaryIsoFunctional<D>(lhs,rhs){
    }
    DivideIsoFunctional(const CopiedBasePtr<IsoFunctional<D> >& lhs, const D& rhs):
      BinaryIsoFunctional<D>(
        lhs,
        InterfacedObjPtr< IsoFunctional<D>, ConstantIsoFunctional<D> >(new ConstantIsoFunctional<D>(rhs))
      ) {
    }
    virtual D operator()(D v) const {
       D s = lhs()(v);
       s /= rhs()(v);
       return s;
    }
};

template<class D>
class UnaryIsoFunctional {
public:
    UnaryIsoFunctional(const CopiedBasePtr<IsoFunctional<D> >& lhs):
      the_lhs(lhs){
    }
    const IsoFunctional<D>& lhs() const { return *the_lhs;}
private:
    CopiedBasePtr<IsoFunctional<D> > the_lhs;
};

template<class D>
class AdditiveInverseIsoFunctional :
    public IsoFunctional<D>,
    protected UnaryIsoFunctional<D>{
public:
    AdditiveInverseIsoFunctional(const CopiedBasePtr<IsoFunctional<D> >& lhs):
      UnaryIsoFunctional<D>(lhs){
    }
    virtual D operator()(D v) const {
       return -lhs()(v);
    }
};

template<class D>
class MultiplicativeInverseIsoFunctional :
    public IsoFunctional<D>,
    protected UnaryIsoFunctional<D> {
public:
    MultiplicativeInverseIsoFunctional(const CopiedBasePtr<IsoFunctional<D> >& lhs):
      UnaryIsoFunctional<D>(lhs){
    }
    virtual D operator()(D v) const {
       return 1./lhs()(v);
    }
};

template<class D>
class IsoFunctionalAlgebra :
     public IsoFunctional<D>,
     public DivisionAlgebraCategory<IsoFunctionalAlgebra<D>,D> {
public:
   virtual D operator()(D v) const { return (*f)(v);}
   IsoFunctionalAlgebra(const D& d) : 
     f(InterfacedObjPtr<IsoFunctional<D>,ConstantIsoFunctional<D> >( new ConstantIsoFunctional<D>(d) )) {}
   IsoFunctionalAlgebra(const CloneablePtr< IsoFunctional<D> >& fp) : f(fp) {}
   
   IsoFunctionalAlgebra<D> operator+=(IsoFunctionalAlgebra<D> rhs);
   IsoFunctionalAlgebra<D> operator-=(IsoFunctionalAlgebra<D> rhs);
   IsoFunctionalAlgebra<D> operator*=(IsoFunctionalAlgebra<D> rhs);
   IsoFunctionalAlgebra<D> operator/=(IsoFunctionalAlgebra<D> rhs);
   IsoFunctionalAlgebra<D> operator*=(const D&);
   IsoFunctionalAlgebra<D> operator/=(const D&);
   IsoFunctionalAlgebra<D> setToZero();
   IsoFunctionalAlgebra<D> setToOne();
   IsoFunctionalAlgebra<D> negate();
   IsoFunctionalAlgebra<D> invert();
   
   static IsoFunctionalAlgebra<D> x;
   
private:
   const CopiedBasePtr<IsoFunctional<D> >& operator()(){return f;}
   CopiedBasePtr<IsoFunctional<D> > f;
   IsoFunctionalAlgebra() : f(InterfacedObjPtr<IsoFunctional<D>,XIsoFunctional<D> >( new XIsoFunctional<D>() )) {}
};

template<class D>
IsoFunctionalAlgebra<D> IsoFunctionalAlgebra<D>::x = IsoFunctionalAlgebra<D>();

template<class D>
IsoFunctionalAlgebra<D> IsoFunctionalAlgebra<D>::operator+=(IsoFunctionalAlgebra<D> rhs){
   f = InterfacedObjPtr<IsoFunctional<D>,AddIsoFunctional<D> >(new AddIsoFunctional<D>( (*this)(), rhs() ));
   return *this;
}
template<class D>
IsoFunctionalAlgebra<D> IsoFunctionalAlgebra<D>::operator-=(IsoFunctionalAlgebra<D> rhs){
   f = InterfacedObjPtr<IsoFunctional<D>,SubtractIsoFunctional<D> >(new SubtractIsoFunctional<D>( (*this)(), rhs() ));
   return *this;
}
template<class D>
IsoFunctionalAlgebra<D> IsoFunctionalAlgebra<D>::operator*=(IsoFunctionalAlgebra<D> rhs){
   f = InterfacedObjPtr<IsoFunctional<D>,MultiplyIsoFunctional<D> >(new MultiplyIsoFunctional<D>( (*this)(), rhs() ));
   return *this;
}
template<class D>
IsoFunctionalAlgebra<D> IsoFunctionalAlgebra<D>::operator/=(IsoFunctionalAlgebra<D> rhs){
   f = InterfacedObjPtr<IsoFunctional<D>,DivideIsoFunctional<D> >(new DivideIsoFunctional<D>( (*this)(), rhs() ));
   return *this;
}
template<class D>
IsoFunctionalAlgebra<D> IsoFunctionalAlgebra<D>::setToZero(){
   f = InterfacedObjPtr<IsoFunctional<D>,ZeroIsoFunctional<D> >(new ZeroIsoFunctional<D>());
   return *this;
}
template<class D>
IsoFunctionalAlgebra<D> IsoFunctionalAlgebra<D>::setToOne(){
   f = InterfacedObjPtr<IsoFunctional<D>,OneIsoFunctional<D> >(new OneIsoFunctional<D>());
   return *this;
}
template<class D>
IsoFunctionalAlgebra<D> IsoFunctionalAlgebra<D>::negate(){
   f = InterfacedObjPtr<IsoFunctional<D>,AdditiveInverseIsoFunctional<D> >(new AdditiveInverseIsoFunctional<D>( (*this)() ));
   return *this;
}
template<class D>
IsoFunctionalAlgebra<D> IsoFunctionalAlgebra<D>::invert(){
   f = InterfacedObjPtr<IsoFunctional<D>,MultiplicativeInverseIsoFunctional<D> >(new MultiplicativeInverseIsoFunctional<D>( (*this)() ));
   return *this;
}
template<class D>
IsoFunctionalAlgebra<D> IsoFunctionalAlgebra<D>::operator*=(const D& rhs){
   f = InterfacedObjPtr<IsoFunctional<D>,MultiplyIsoFunctional<D> >(new MultiplyIsoFunctional<D>( (*this)(), rhs ));
   return *this;
}
template<class D>
IsoFunctionalAlgebra<D> IsoFunctionalAlgebra<D>::operator/=(const D& rhs){
   f = InterfacedObjPtr<IsoFunctional<D>,DivideIsoFunctional<D> >(new DivideIsoFunctional<D>( (*this)(), rhs ));
   return *this;
}

