
#include "ConcreteArray1dUtil.h"
#include "ConcreteFormedArray1d.h"

template<class T>
void addSubVector(ConcreteFormedArray1d<T>& vect, const ConcreteFormedArray1d<T>& subv, 
		  const ConcreteFormedArray1d<int>& firstEq, 
		  const ConcreteFormedArray1d<short>& blockSize, const int numBlocks) {

  // Adds a subvector to a vector. The vector and subvector have a
  // block structure. Block ibl starts at position firstEq(ibl) of
  // vect and has dimension blockSize(ibl)

  Subscript ipos, ibl_size, irow = 0;
  for(Subscript ibl=0; ibl<numBlocks; ++ibl) {
    ipos = firstEq(ibl);
    ibl_size = blockSize(ibl);
    for(Subscript isub=0; isub<ibl_size; ++isub)
      vect(ipos++) += subv(irow++);
  }


}
// *************************************************************
// *************************************************************


template<class T>
void addSubVector(ConcreteFormedArray1d<T>& vect, const ConcreteFormedArray1d<T>& subv,
		  const int dim, const ConcreteFormedArray1d<int>& destIndex) {

  // Adds a subvector of dimension dim to a vector. The subvector is
  // added at the positions destIndex of the vector

  // vect( desIndex(i) ) += subv(i)

  for(Subscript irow=0; irow<dim; ++irow)
    vect( destIndex(irow) ) += subv(irow);


#if 0
  // This optimization does not bring anything...

  Subscript gl_row, ipos = -10;
  // gl_row_1 = gl_row - 1
  Subscript gl_row_1 = -10; // to force computation of ipos at least once 
  for(Subscript irow=0; irow<dim; ++irow) {
    gl_row = destIndex(irow);

    // Since the data is contiguous in memory: offset(row) = offset(row-1) + 1
    if ( (gl_row != gl_row_1+1) ) {
      ipos = vect.offset(gl_row);
    }
#if DBUG_ON > 0
    else {
      ERRCHK( ipos != offset(gl_row), "template<class T> addSubVector: Algorithm error");
    }
#endif
    vect.firstDatum()[ ipos++ ] += subv.firstDatum()[irow];
    gl_row_1 = gl_row;
  } // next row 
#endif

}
// *************************************************************
// *************************************************************
