//
// Tests for ConcreteFortranArray and ConcreteFormedArray
//

#include <iostream>
#include <cstdlib>

#include "Array/ConcreteFortranArray1d.h"
#include "Array/ConcreteFortranArray2d.h"
#include "Array/ConcreteFortranArray3d.h"

#include "Array/ConcreteArrayShape.h"

#include "Array/ConcreteFormedArray1d.h"
#include "Array/ConcreteFormedArray3d.h"

#include "Array/ConcreteArray2dUtil.h"

using std::cout;
using std::endl;

int main() {

  ConcreteRowMajorSubscriptor<1>  RowSub1( SubscriptArray<1>(5) );
  cout << " RowSub1.shape( 0 ) " << RowSub1.shape( 0 ) << endl;
  SubscriptArray<1> suba1(3);
  cout << " RowSub1.offset( 3 ) " << RowSub1.offset( suba1(0) ) << endl;

  SubscriptArray<1> suba(5);
  ConcreteRowMajorSubscriptor<1>  RowSub2( suba );
  cout << " RowSub2.offset( 4 ) " 
       << RowSub2.offset( 4 ) << endl;


  ConcreteColumnMajorSubscriptor<1> ColSub( SubscriptArray<1>(10) );
  cout << " ColSub.shape( 0 ) " << ColSub.shape( 0 ) << endl;
  cout << " ColSub.offset( 8 ) " 
       << ColSub.offset( SubscriptArray<1>(8)(0) ) << endl;

  ConcreteColumnMajorProjectionSubscriptor<1> 
    ColProjSub( SubscriptArray<1>(5) /* shape */, SubscriptArray<1> (3) /*strides*/); 

  cout << " ColProjSub.dim() = " << ColProjSub.dim() << endl;
  cout << " ColProjSub.shape(0) = " << ColProjSub.shape(0) << endl;
  cout << " ColProjSub.numElts() = " << ColProjSub.numElts() << endl;
  cout << " ColProjSub.offset(4) = " << ColProjSub.offset(4) << endl;

  ConcreteRowMajorProjectionSubscriptor<1> 
    RowProjSub( SubscriptArray<1>(7) /* shape */, SubscriptArray<1> (2) /*strides*/); 

  cout << " RowProjSub.dim() = " << RowProjSub.dim() << endl;
  cout << " RowProjSub.shape(0) = " << RowProjSub.shape(0) << endl;
  cout << " RowProjSub.numElts() = " << RowProjSub.numElts() << endl;
  cout << " RowProjSub.offset(4) = " << RowProjSub.offset(4) << endl;

  // ---------------------------------------------------------------

  ConcreteFortranArray1d<float> fa1d(5), fa1d_1(5);

  fa1d = 1.0;
  fa1d_1 = fa1d;

  cout << " fa1d(0) = " << fa1d(0) << endl;
  cout << " fa1d : " << fa1d << endl;
  cout << " fa1d_1 : " << fa1d_1 << endl;

  ConcreteFortranArray2d<float> fa2d(3,4), fa2d_1(3,4);

  fa2d = 1.0;

  fa2d_1 = fa2d;

  fa2d_1[1] =  2.0;

  cout << " fa2d(0,0) = " << fa2d(0,0) << endl;
  cout << " fa2d: " << fa2d << endl;

  cout << " fa2d_1: " << fa2d_1 << endl;

  //  ConcreteFortranArray3d<float> fa3d(3,4,2), fa3d_1(3,4,2);
  ConcreteFortranArray3d<float> fa3d(3,1,1), fa3d_1(3,1,1);

  fa3d = 1.0;

  fa3d_1 = fa3d;

  fa3d_1[1] =  2.0;

  cout << " fa3d(0,0,0) = " << fa3d(0,0,0) << endl;
  cout << " fa3d: " << fa3d << endl;

  cout << " fa3d_1: " << fa3d_1 << endl;

  ConcreteFormedArray3d<float> fma3d(3,1,1), fma3d_1(3,1,1);

  fma3d = 1.0;

  fma3d_1 = fma3d;

  fma3d_1[1] =  2.0;

  cout << " fma3d(0,0,0) = " << fma3d(0,0,0) << endl;
  cout << " fma3d: " << fma3d << endl;

  cout << " fma3d_1: " << fma3d_1 << endl;


  // --------------------------------------------------------

  ConcreteFormedArray1d<double> fa10(10), fa20(20);

  fa10 = 10.0;
  fa20 = 20.0;

  cout << "\nfa10: " << fa10 << "\nfa20: " << fa20 << endl;

  fa10.swap( fa20 );

  cout << "\nfa10: " << fa10 << "\nfa20: " << fa20 << endl;

  // --------------------------------------------------------

  const int dim = 6, nkol = 4, nblocks = 3;
  int nrow_block = dim / nblocks;

  ConcreteFortranArray2d<double> vect(4*dim, nkol), subv(dim,nkol);

  vect = 0.0;

  ConcreteFormedArray1d<int> destIndex(dim);
  ConcreteFormedArray1d<int> firstEq(nblocks);
  ConcreteFormedArray1d<short int> blockSize(nblocks);

  Subscript i=0;
  for(Subscript ibl=0; ibl<nblocks; ++ibl){
    firstEq(ibl) = (ibl*2 + 2)*nrow_block;
    blockSize(ibl) = nrow_block;
    for(Subscript irowbl=0; irowbl<nrow_block; ++irowbl, ++i){
      destIndex(i) = firstEq(ibl) + irowbl;
      for(Subscript kol=0; kol<nkol; ++kol){
	subv(i,kol) = ibl + 1.0;
      }
    }
  }
  cout << "\nvect = " << vect << endl;
  cout << "\ndestIndex = " << destIndex << endl;
  cout << "\firstEq = " << firstEq << endl;
  cout << "\blockSize = " << blockSize << endl;
  cout << "\nsubv = " << subv << endl;

  addSubVector( vect, subv, dim, destIndex);

  cout << "\nvect = " << vect << endl;

  vect = 0.0;

  addSubVector( vect, subv, firstEq, blockSize, nblocks);

  cout << "\nvect = " << vect << endl;

  vect.clear();
  destIndex.clear();

  //  cout << "\nvect = " << vect << endl;
  // cout << "\ndestIndex = " << destIndex << endl;

  // TBD: Need to handle empty arrays
  //  ConcreteFormedArray1d<int> empty;

  //  cout << empty;

  return EXIT_SUCCESS;

}
