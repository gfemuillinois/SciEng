
#ifndef TMPL1H
#define TMPL1H

#include "Array/Array2d.h"
#include "Array/FortranArray1d.h"
#include "Array/FortranArray2d.h"
#include "SciEng/CopiedObjPtr.h"
#include "SciEng/Boolean.h"
#include "SciEng/utils.h"
#include "SciEng/SciEngEnvironment.h"


template<class T> class LapackRect;
template<class T> class FactoredLapackRect;
template<class T> class LapackSymPosDefPacked;
template<class T> class FactoredLapackSymPosDefPacked;

class InvalidFactoredMatrixUse {};  // Dummy exception class


template<class T>
class LapackRect :
    public virtual Array2d<T> {
public:
    LapackRect(Subscript nrows, Subscript ncols);
    FactoredLapackRect<T> factor();
    // ...

    // Array interface declarations ...
    virtual Subscript shape(Dimension d) const; 
    virtual Dimension dim() const; 
    virtual Array2d<T>& operator=(const T&);
    virtual Array2d<T>& operator=(const ConstArray2d<T>&);
    virtual T& operator()(Subscript,Subscript);
    virtual const T& operator()(Subscript,Subscript) const;
    virtual typename Array2d<T>::ProjectionT project(Subscript, Dimension);
    virtual typename Array2d<T>::ConstProjectionT project(Subscript, Dimension) const;
private:

    CopiedObjPtr< FortranArray2d<T> > ap;         // Lapack A
    Boolean                           valid;  


    // Check validity -- throw exception if not valid
    void checkValidity() const;
};

template<class T>
LapackRect<T>::LapackRect(Subscript nrows, Subscript ncols) :
    ap(new FortranArray2d<T>(nrows, ncols)), valid(Boolean::IsTrue)  {
}

template<class T>
FactoredLapackRect<T> LapackRect<T>::factor() {
    checkValidity();
    valid = Boolean::IsFalse;
    return FactoredLapackRect<T>( ap.releaseControl() );
}

template<class T>
Subscript LapackRect<T>::shape(Dimension d) const {
    checkValidity();
    return ap->shape(d);
}

template<class T>
Dimension LapackRect<T>::dim() const {
  checkValidity();
  return 2;
}

template<class T>
void LapackRect<T>::checkValidity() const {
  if (! valid) throw InvalidFactoredMatrixUse();
}

template<class T>
Array2d<T>& LapackRect<T>::operator=(const T& rhs) { return Array2d<T>::operator=(rhs); }

template<class T>
Array2d<T>& LapackRect<T>::operator=(const ConstArray2d<T>& rhs) { return Array2d<T>::operator=(rhs); }

template<class T>
T& LapackRect<T>::operator()(Subscript s0, Subscript s1) { checkValidity(); return ap->operator()(s0, s1); }

template<class T>
const T& LapackRect<T>::operator()(Subscript s0, Subscript s1) const { checkValidity(); return ap->operator()(s0, s1); }

template<class T>
typename Array2d<T>::ProjectionT 
LapackRect<T>::project(Subscript s, Dimension d) { checkValidity(); return ap->project(s, d); }

template<class T>
typename Array2d<T>::ConstProjectionT 
LapackRect<T>::project(Subscript s, Dimension d) const { 
  checkValidity();
  // Following code is to get back a const projection even though the
  // pointer is not const.
  const FortranArray2d<T>& fm = *ap;
  return fm.project(s, d); 
}

template<class T>
class FactoredLapackRect {
public:
    LapackRect<T>& solve(LapackRect<T>&);
private:
    friend FactoredLapackRect<T> LapackRect<T>::factor();
    FactoredLapackRect(FortranArray2d<T>* ap);


    CopiedObjPtr< FortranArray2d<T> > fmat_p;     // LAPACK "A"
    FortranArray1d<int>               pivots;     // LAPACK "IPIV"
};


template<class T>
FactoredLapackRect<T>::FactoredLapackRect(FortranArray2d<T>* ap) :
    fmat_p(ap), 
    pivots( sce::min(ap->shape(0), ap->shape(1)) ) {
    // Call LAPACK factoring routine ...
}

template<class T>
LapackRect<T>& FactoredLapackRect<T>::solve(LapackRect<T>& b) {
  // Dummy routine
  return b;
}


#endif
