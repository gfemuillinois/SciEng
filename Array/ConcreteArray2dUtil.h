
#ifndef CONCRETEARRAY2DUTILH
#define CONCRETEARRAY2DUTILH

template <class T> class ConcreteFortranArray2d;
template <class T> class ConcreteFormedArray1d;

// NOTE: We could generalize this to ConcreteArray2d but the
// implementation assumes column major. Therefore, it would not be
// very efficient for row major arrays derived from ConcreteArray2d


// -----------------------------------------------------------------
// Here we imagine that the Arrays have a block structure defined by
// the arguments firstEq and blockSize
// The number of columns of the vector and subvector must be the same

// Adds sub (block) vectors to a (block) vector. The vector and
// subvector have a block structure. Block ibl starts at row
// firstEq(ibl) of vect and has blockSize(ibl) rows.
// The above is done for all columns of the vectors.


template<class T>
void addSubVector(ConcreteFortranArray2d<T>& vect, 
		  const ConcreteFortranArray2d<T>& subv, 
		  const ConcreteFormedArray1d<int>& firstEq, 
		  const ConcreteFormedArray1d<short>& blockSize, 
		  const int numBlocks);

// -----------------------------------------------------------------
// Adds a subvector of dimension dim to a vector. The subvector is
// added at the positions destIndex of the vector.
// We repeat this for all columns. 
// The number of columns of the vector and subvector must be the same

template<class T>
void addSubVector(ConcreteFortranArray2d<T>& vect, 
		  const ConcreteFortranArray2d<T>& subv,
		  const int dim, const ConcreteFormedArray1d<int>& destIndex);

// -----------------------------------------------------------------
// added by DJK
//
// Add a vector to another vector. These two vectors have exactly
// the same dimension. (vect1 = vect1 + vect2)

template<class T>
void addVector(ConcreteFortranArray2d<T>& vect1, 
	       const ConcreteFortranArray2d<T>& vect2);


#ifdef XLC_QNOTEMPINC
#include "Array/ConcreteArray2dUtil.c"
#endif

#endif
