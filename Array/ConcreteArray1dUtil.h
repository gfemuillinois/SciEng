
#ifndef CONCRETEARRAY1DUTILH
#define CONCRETEARRAY1DUTILH

template <class T> class ConcreteFormedArray1d;


// Adds a subvector to a vector. The vector and subvector have a
// block structure. Block ibl starts at position firstEq(ibl) of
// vect and has dimension blockSize(ibl)

template<class T>
void addSubVector(ConcreteFormedArray1d<T>& vect, 
                  const ConcreteFormedArray1d<T>& subv, 
                  const ConcreteFormedArray1d<int>& firstEq, 
                  const ConcreteFormedArray1d<short>& blockSize, 
                  const int numBlocks);

// Adds a subvector of dimension dim to a vector. The subvector is
// added at the positions destIndex of the vector
template<class T>
void addSubVector(ConcreteFormedArray1d<T>& vect, 
                  const ConcreteFormedArray1d<T>& subv,
                  const int dim, const ConcreteFormedArray1d<int>& destIndex);

// Returns a pointer to the maximum value in the vector
template<class T>
const T* maxElement(const ConcreteFormedArray1d<T>& vect,
                    int& indexOfMaxElem) {
  const T* p_max_val = std::max_element( vect.firstDatum(),
                                         vect.firstDatum() + vect.shape(0) );
  indexOfMaxElem = p_max_val - vect.firstDatum();
  return p_max_val; }


#ifdef XLC_QNOTEMPINC
#include "Array/ConcreteArray1dUtil.c"
#endif

#endif
