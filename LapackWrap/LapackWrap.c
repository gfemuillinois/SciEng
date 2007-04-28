
#include "Array/ConcreteRigidArray1d.h"
#include "Array/ConcreteRigidArray2d.h"

namespace LapackWrap {

template<class T, Subscript n0>
bool factAndSolve(ConcreteRigidArray2d< T, n0,n0>&  A, 
		  const int prob_dim,
		  ConcreteRigidArray1d< T, n0>& rhs) {

  /* Solving a system of equations (prob_dim x prob_dim) using Lapack.
   *
   * Output:
   * rhs = solution
   *
   * The function value is true if successful and false otherwise
   *
   */

  int ipiv[n0], info;

  // compute an LU factorization of a general M-by-N matrix A using
  // partial pivoting with row interchanges
  LapackSubroutines::xgetrf( prob_dim /*m*/, prob_dim /*n*/, A.firstDatum(),
			     n0 /*lda*/, ipiv, info);
  if (info < 0) {
    std::cerr << "\nLapackWrap::factAndSolve: Invalid argument " << -info 
	 << " to LapackSubroutines::xgetrf " << std::endl;
    return false;
  }
  if (info > 0) {
    /* if info = i, U(i-1,i-1) is exactly zero. The factorization
     * has been completed, but the factor U is exactly singular, and
     * division by zero will occur if it is used to solve a system
     * of equations. */
    std::cerr << "\nLapackWrap::factAndSolve: Matrix is singular " 
	      << std::endl;
    return false;
  }

  // solve a system of linear equations A * X = B or A' * X = B with a
  // general N-by-N matrix A using the LU factorization computed by
  // XGETRF

  // Use transpose bcz matrix A is row major and Lapack is Fortran
  LapackSubroutines::Trans  ta = LapackSubroutines::trans;

  LapackSubroutines::xgetrs(ta, prob_dim /*n*/, 1 /*nrhs*/, A.firstDatum(),
			    n0 /*lda*/, ipiv, rhs.firstDatum() /*p_b*/,
			    n0 /*ldb*/, info);

  if (info < 0) {
    std::cerr << "\nLapackWrap::factAndSolve: Invalid argument " << -info 
	 << " to LapackSubroutines::xgetrs " << std::endl;
    return false;
  }

  return true;
}
// **************************************************************
// **************************************************************

template<class T, Subscript n0>
bool eigens(ConcreteRigidArray2d< T, n0,n0>&  A, const int prob_dim,
	    const bool eigenVectors,
	    ConcreteRigidArray1d< T, n0>& eigenValues) {

  // Eigenvalues and eigenvectors (if eigenVectors = true) of a symmetric matrix

  // On input, we use only the LOWER triangle part of A.
  //
  // The function value is true if successful and false otherwise
  //
  // Computes all the eigenvalues and, optionally, eigenvectors.
  // If eigenVectors = true, A will contain, on exit, the orthonormal eigenvectors
  // of A.
  // 
  // If eigenVectors != true, the data of A is destroyed on exit.
  // See Lapack manual pg. 211 for more details.

  if ( prob_dim > n0 ) {
    std::cerr << "\nLapackWrap::eigens: Invalid prob_dim = " << prob_dim
	      << " n0 = " << n0 << std::endl;
    return false;
  }

  char* job = "No Evectors";
  if (eigenVectors) job = "Vectors";

  ConcreteRigidArray1d< T, 3*n0> work;
  int info = 0;
  // call Lapack FORTRAN subroutine.
  //
  // Telling Lapack to use upper triangle part of A. Since A is row-major,
  // it will actually use the LOWER triangle part of A.
  LapackSubroutines::xsyev(job, "Upper", prob_dim /*N*/, A.firstDatum(), n0 /*LDA*/,
			   eigenValues.firstDatum(), work.firstDatum(), 3*n0, info);  

  if(info > 0) {
    std::cerr << "\nLapackWrap::eigens: The algorithm failed to converge \n"
	      << "after finding only " << info-1 << " eigenvalues " << std::endl;
    return false;
  }
  if (info < 0) {
    std::cerr << "\nLapackWrap::eigens: xsyev called with invalid argument "
	      << -info << std::endl;
    return false;
  }
  return true;

}
// **************************************************************
// **************************************************************

} // end of namespace LapackWrap
