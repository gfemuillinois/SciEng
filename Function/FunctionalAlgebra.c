/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

template<class Domain>
FunctionalAlgebra<Domain>& FunctionalAlgebra<Domain>::
operator+=(const FunctionalAlgebra<Domain>& rhs) { 
    f = new AddFunctional<Domain>( f, rhs.f );
    return *this;
}


template<class Domain>
CloneableObjPtr< IsoFunctional<Domain> >
FunctionalAlgebra<Domain>::operator()(const FunctionalAlgebra<Domain>& inner) const{
   CloneableObjPtr< IsoFunctional<Domain> > it(inner.clone());
   CloneableObjPtr< IsoFunctional<Domain> >  ot(f);
   return   new CompositionFunctional<Domain>( it , ot );
}

template<class Domain>
FunctionalAlgebra<Domain>& FunctionalAlgebra<Domain>::operator-=(const FunctionalAlgebra<Domain>& rhs) {
   f =  new SubtractFunctional<Domain>( f, rhs.f );
   return *this;
}
template<class Domain>
FunctionalAlgebra<Domain>& FunctionalAlgebra<Domain>::operator*=(const FunctionalAlgebra<Domain>& rhs) {
   f =  new MultiplyFunctional<Domain>( f, rhs.f );
   return *this;
}
template<class Domain>
FunctionalAlgebra<Domain>& FunctionalAlgebra<Domain>::operator/=(const FunctionalAlgebra<Domain>& rhs) {
   f =  new DivideFunctional<Domain>( f, rhs.f );
   return *this;
}
template<class Domain>
FunctionalAlgebra<Domain>& FunctionalAlgebra<Domain>::setToZero() {
   f =  new ZeroFunctional<Domain>();
   return *this;
}
template<class Domain>
FunctionalAlgebra<Domain>& FunctionalAlgebra<Domain>::setToOne() {
   f =  new OneFunctional<Domain>();
   return *this;
}
template<class Domain>
FunctionalAlgebra<Domain>& FunctionalAlgebra<Domain>::negate() {
   f =  new AdditiveInverseFunctional<Domain>(f);
   return *this;
}
template<class Domain>
FunctionalAlgebra<Domain>& FunctionalAlgebra<Domain>::invert() {
   f =  new MultiplicativeInverseFunctional<Domain>(f);
   return *this;
}
template<class Domain>
FunctionalAlgebra<Domain>& FunctionalAlgebra<Domain>::operator*=(const Domain& rhs) {
   f =  new MultiplyFunctional<Domain>(f, rhs);
   return *this;
}
template<class Domain>
FunctionalAlgebra<Domain>& FunctionalAlgebra<Domain>::operator/=(const Domain& rhs) {
   f =  new DivideFunctional<Domain>(f, rhs);
   return *this;
}
template<class Domain>
FunctionalAlgebra<Domain>::FunctionalAlgebra(const Domain& d) :
     f(  new ConstantFunctional<Domain>(d) )  {
}


template<class Domain>
FunctionalAlgebra<Domain>::FunctionalAlgebra(const CountedBuiltInPtr<Domain>& d) :
    f(  new ParameterFunctional<Domain>(d) ) {
}



template<class Domain>
FunctionalAlgebra<Domain>::FunctionalAlgebra() :
    f( new XFunctional<Domain>() ) {
}


#include "Function/CompositionFunctional.h"
#include "Function/ExpFunctional.h"
template<class Domain>
FunctionalAlgebra<Domain> exp(const FunctionalAlgebra<Domain>& f) {
   return new CompositionFunctional<Domain>( f.f, new ExpFunctional<Domain>() );
}
     
#include "Function/LogFunctional.h"
template<class Domain>
FunctionalAlgebra<Domain> log(const FunctionalAlgebra<Domain>& f){
   return new CompositionFunctional<Domain>( f.f, new LogFunctional<Domain>() );
}

#include "Function/SqrtFunctional.h"
template<class Domain>
FunctionalAlgebra<Domain> sqrt(const FunctionalAlgebra<Domain>& f){
   return new CompositionFunctional<Domain>( f.f, new SqrtFunctional<Domain>() );
}

#include "Function/Log10Functional.h"
template<class Domain>
FunctionalAlgebra<Domain> log10(const FunctionalAlgebra<Domain>& f){
   return new CompositionFunctional<Domain>( f.f, new Log10Functional<Domain>() );
}

#include "Function/SinFunctional.h"
template<class Domain>
FunctionalAlgebra<Domain> sin(const FunctionalAlgebra<Domain>& f){
   return new CompositionFunctional<Domain>( f.f, new SinFunctional<Domain>() );
}

#include "Function/CosFunctional.h"
template<class Domain>
FunctionalAlgebra<Domain> cos(const FunctionalAlgebra<Domain>& f){
   return new CompositionFunctional<Domain>( f.f, new CosFunctional<Domain>() );
}
#include "Function/ASinFunctional.h"
template<class Domain>
FunctionalAlgebra<Domain> asin(const FunctionalAlgebra<Domain>& f){
   return new CompositionFunctional<Domain>( f.f, new ASinFunctional<Domain>() );
}

#include "Function/ACosFunctional.h"
template<class Domain>
FunctionalAlgebra<Domain> acos(const FunctionalAlgebra<Domain>& f){
   return new CompositionFunctional<Domain>( f.f, new ACosFunctional<Domain>() );
}

template<class Domain>
FunctionalAlgebra<Domain>::FunctionalAlgebra(const IsoFunctional<Domain>& fp)  :
  f(fp.clone()) {
}

template<class Domain>
FunctionalAlgebra<Domain>::FunctionalAlgebra(IsoFunctional<Domain>* just_newed)  :
  f(just_newed) {
}
