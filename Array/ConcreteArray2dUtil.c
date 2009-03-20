
#include "ConcreteArray2dUtil.h"
#include "ConcreteFortranArray2d.h"
#include "ConcreteFormedArray1d.h"
#include "error.h"

template<class T>
void addSubVector(ConcreteFortranArray2d<T>& vect, 
		  const ConcreteFortranArray2d<T>& subv, 
		  const ConcreteFormedArray1d<int>& firstEq, 
		  const ConcreteFormedArray1d<short>& blockSize, 
		  const int numBlocks) {

  // Here we imagine that the Arrays have a block structure defined by
  // the arguments firstEq and blockSize
  // The number of columns of the vector and subvector must be the same

  // Adds sub (block) vectors to a (block) vector. The vector and
  // subvector have a block structure. Block ibl starts at row
  // firstEq(ibl) of vect and has blockSize(ibl) rows.
  // The above is done for all columns of the (block) vectors.

  ERRCHK( vect.shape(1) != subv.shape(1), 
	  "template<class T> addSubVector: Invalid Arguments");

  Subscript irow_vec, irow_sv, ibl_size;
  const Subscript jbl_size = vect.shape(1);

  for(Subscript kol=0; kol<jbl_size; ++kol) {
    irow_sv = 0;
    for(Subscript ibl=0; ibl<numBlocks; ++ibl) {
      irow_vec = firstEq(ibl);
      ibl_size = blockSize(ibl);
      for(Subscript isub=0; isub<ibl_size; ++isub)
	vect(irow_vec++,kol) += subv(irow_sv++,kol);
    }
  }

}
// *************************************************************
// *************************************************************

template<class T>
void addSubVector(ConcreteFortranArray2d<T>& vect, 
		  const ConcreteFortranArray2d<T>& subv,
		  const int dim, const ConcreteFormedArray1d<int>& destIndex) {

  // Adds a subvector of dimension dim to a vector. The subvector is
  // added at the positions destIndex of the vector.
  // We repeat this for all columns. 
  // The number of columns of the vector and subvector must be the same

  // vect( desIndex(i), kol ) += subv(i, kol)

  ERRCHK( vect.shape(1) != subv.shape(1), 
	  "template<class T> addSubVector: Invalid Arguments");

  const Subscript jbl_size = vect.shape(1);
  for(Subscript kol=0; kol<jbl_size; ++kol) {
    for(Subscript irow=0; irow<dim; ++irow)
      vect( destIndex(irow), kol ) += subv(irow, kol);
  }

}
// *************************************************************
// *************************************************************

// added by DJK

template<class T>
void addVector(ConcreteFortranArray2d<T>& vect1, 
	       const ConcreteFortranArray2d<T>& vect2) {

  // Add a vector to another vector. These two vectors have exactly
  // the same dimension. (vect1 = vect1 + vect2)

  ERRCHK( vect1.shape(0) != vect2.shape(0), 
	  "template<class T> addSubVector: Invalid Arguments");
  ERRCHK( vect1.shape(1) != vect2.shape(1), 
	  "template<class T> addSubVector: Invalid Arguments");

  const Subscript row_size = vect1.shape(0);
  const Subscript col_size = vect1.shape(1);

  for(Subscript icol=0; icol < col_size; ++icol) {
    for(Subscript irow=0; irow < row_size; ++irow)
      vect1( irow, icol ) += vect2( irow, icol );
  }

}
// *************************************************************
// *************************************************************
