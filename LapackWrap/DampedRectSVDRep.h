/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef DampedRectSVDRepH
#define DampedRectSVDRepH

#include "LapackWrap/RectSVDRep.h"
#include "SciEng/NumericalLimits.h"


template<class T>
class DampedRectSVDRep : 
    public RectSVDRep<T> { 
public:
    class Factored :  
        public RectSVDRep<T>::Factored {
    public:
        Factored(Unfactored* mp) :  
            RectSVDRep<T>::Factored(mp),
            lambda2(NumericalLimits<T>::epsilon) {
        }


        T  dampingFactor() const { return lambda2; }
        T& dampingFactor()       { return lambda2; }


    protected:
        virtual void pseudoInvert(ConcreteBlas2d<T>& utb);
        virtual void pseudoInvert(ConcreteBlas1d<T>& utb);

    private:
        T lambda2;
    };
};


#ifdef XLC_QNOTEMPINC
#include "LapackWrap/DampedRectSVDRep.c"
#endif

#endif
