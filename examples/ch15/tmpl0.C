/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "Array/ConcreteFortranArray1d.h"
#include "Array/ConcreteFortranArray2d.h"
#include "Array/ConcreteFortranSymmetricPackedArray2d.h"

template<class T> class LapackRect;
template<class T> class FactoredLapackRect;
template<class T> class LapackSymPosDefPacked;
template<class T> class FactoredLapackSymPosDefPacked;


template<class T>
class LapackRect :
    public ConcreteFortranArray2d<T> { // LAPACK A, M, and N
public:
    LapackRect(Subscript nrows, Subscript ncols);
    FactoredLapackRect<T> factor();
    // ...
};



template<class T>
class LapackSymPosDefPacked :
    public ConcreteFortranSymmetricPackedArray2d<T> {
public:
    LapackSymPosDefPacked(Subscript size);
    FactoredLapackSymPosDefPacked<T> factor();
};



template<class T>
class FactoredLapackRect {
public:
    LapackRect<T>& solve(LapackRect<T>&);
private:
    friend FactoredLapackRect<T> LapackRect<T>::factor();
    FactoredLapackRect(Subscript nrows, Subscript ncols);


    ConcreteFortranArray2d<T>   fmat;     // LAPACK "A"
    ConcreteFortranArray1d<int> pivots;   // LAPACK "IPIV"

};


template<class T>
class FactoredLapackSymPosDefPacked {
public:
    LapackRect<T>& solve(LapackRect<T>&);
private:
    friend FactoredLapackSymPosDefPacked<T> LapackSymPosDefPacked<T>::factor();
    FactoredLapackSymPosDefPacked(Subscript size);


    ConcreteFortranArray2d<T>   fmat;     // LAPACK "A"

};

void solve1() {

LapackRect<float> a1(10,10);
// ... fill a1 ...
FactoredLapackRect<float> factored_a1 = a1.factor();
LapackRect<float> b1(10, 1);
// ... fill b1 with right hand side  ...
factored_a1.solve(b1); // Solution is in b1

LapackSymPosDefPacked<float> a2(10);
// ... fill a2 ...
FactoredLapackSymPosDefPacked<float> factored_a2 = a2.factor();
LapackRect<float> b2(10, 1);
// ... fill b2 with right hand side  ...
factored_a2.solve(b2); // Solution is in b2

}
