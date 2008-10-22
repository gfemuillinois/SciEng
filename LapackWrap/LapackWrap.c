
#include "Array/ConcreteRigidArray1d.h"
#include "Array/ConcreteRigidArray2d.h"
#include "Array/ConcreteFortranArray2d.h"
#include "Array/ConcreteFortranArray1d.h"

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

template<class T>
bool factAndSolveSymExpert(const ConcreteFortranArray2d<T>& A,
			   const LapackSubroutines::UpLo uplo,
			   const int prob_dim,
			   const ConcreteFortranArray2d<T>& B,
			   ConcreteFortranArray2d<T>& X) {

  /* Solving a symmetric system of equations 
   *
   * A * X = B      nrhs = B.cols()
   *
   * of dimension (prob_dim x prob_dim) using Lapack expert drive DSYSVX (or
   * SSYSVX) which performs the following factorization:
   *
   * A = U * D * U^t,  if uplo = LapackSubroutines::upper
   * A = L * D * L^t,  if uplo = LapackSubroutines::lower
   *
   * Output:
   * X = solution
   *
   * The function value is true if successful and false otherwise
   *
   *  DSYSVX uses the diagonal pivoting factorization A = L*D*L^t (or U*D*U^t)
   *  to compute the solution to a real system of linear equations A * X = B,
   *  where A is an N-by-N symmetric matrix and X and B are N-by-NRHS
   *  matrices ( N == prob_dim).
   *
   *  NOTE: A may be an indefite matrix.
   *
   *  - Estimate the condition number of A and check for near singularity.
   *  - Refine the solution and compute forward and backward error bounds.
   *
   *  Note that the matrix will be overwritten by its factors L and D (or U
   *  and D).  Thus, in order to use the factorization to solve for others
   *  rhs, we have to pivot the rhs and use L and D. At this point this is NOT
   *  implemented !!!
   *
   * if uplo = LapackSubroutines::lower, the lower triangle of A is stored.
   * The leading N-by-N lower triangular part of A contains the lower
   * triangular part of the matrix A, and the strictly upper triangular part
   * of A is not referenced.
   * Similarly if uplo = LapackSubroutines::upper
   *
   *  IMPROVEMENTS: implement methods to solve for others rhs, re-using
   *  previously computed factors.
   *
   * NOTE: This came from method d_bl_matrix::solve_sym_expert from folder 
   *       ~/home_alberta_part2/Galileu_arm/util++_ut/util
  */

    std::cout << "\n+++ LapackWrap::factAndSolveSymExpert +++\n\n"; 

    int nrhs = B.shape(1);

    if (prob_dim > A.shape(0)) {
      std::cerr << "\nLapackWrap::factAndSolveSymExpert: invalid dimentions:\n"
		<< " A.rows =" << A.shape(0) << " prob_dim = " << prob_dim << std::endl;
      return false;
    }
    if (prob_dim > A.shape(1)) {
      std::cerr << "\nLapackWrap::factAndSolveSymExpert: invalid dimentions:\n"
		<< " A.cols =" << A.shape(1) << " prob_dim = " << prob_dim << std::endl;
      return false;
    }
    if (prob_dim > B.shape(0)) {
      std::cerr << "\nLapackWrap::factAndSolveSymExpert: invalid dimentions:\n"
		<< " B.rows =" << B.shape(0) << " prob_dim = " << prob_dim << std::endl;
      return false;
    }
    if (prob_dim > X.shape(0)) {
      std::cerr << "\nLapackWrap::factAndSolveSymExpert: invalid dimentions:\n"
		<< " X.rows =" << X.shape(0) << " prob_dim = " << prob_dim << std::endl;
      return false;
    }
    if (nrhs > X.shape(1)) {
      std::cerr << "\nLapackWrap::factAndSolveSymExpert: invalid dimentions:\n"
		<< " nrhs = " << nrhs << " X.cols = " << X.shape(1) << std::endl;
      return false;
    }

    std::cout << "LapackWrap::factAndSolveSymExpert: Number of Equations = " 
	      << A.shape(0) << std::endl;

    // Note that ipiv is NOT exactly like the one returned by DGESVX. See
    // Lapack manual (pg. 217) for details. !!!!!
    ConcreteFortranArray1d<int> ipiv( prob_dim );

    // Returns the block diagonal matrix D and the multipliers used to obtain
    // the factor U or L from the factorization A = U*D*U^T or A = L*D*L^T.
    ConcreteFortranArray2d<T> af(prob_dim, prob_dim);

    // The matrix A will be copied to af and factored.  I.e., the factors are
    // not being provided as input.
    char fact = 'N';

    // Estimate of the reciprocal condition number
    T rcond = 0.0; 

    // Estimated forward error bound for each solution vector X(.,i)
    ConcreteFortranArray1d<T> ferr(nrhs);

    // Relative backward error of solution vector X(.,i)
    ConcreteFortranArray1d<T> berr(nrhs);

    // Work areas. nb = optimal blocksize for DSYTRF (my guess...)
    int nb = 32;
    int lwork = nb * prob_dim;
    ConcreteFortranArray1d<T>   work(lwork);
    ConcreteFortranArray1d<int> iwork(lwork);

    int info;

    // Lapack subroutine. See manual pg. 148 for more details.
    // LAPACK uses data stored by columns

    //                        fact  uplo     N      nrhs      A            lda      
    LapackSubroutines::xsysvx(fact, uplo, prob_dim, nrhs, A.firstDatum(), A.shape(0), 
			      /*   AF            ldaf           ipiv          */
			      af.firstDatum(), af.shape(0), ipiv.firstDatum(),
			      /*       B       ldb           X           ldx  */
			      B.firstDatum(), B.shape(0), X.firstDatum(), X.shape(0), 
			      rcond, ferr.firstDatum(), berr.firstDatum(),
			      work.firstDatum(), lwork, iwork.firstDatum(), info);

    if (info > 0) {
      if (info <= prob_dim) {
	std::cerr << "\nLapackWrap::factAndSolveSymExpert: This matrix is singular \n"
		  << " info = " << info << " Factor U(" << info-1 << ","
		  << info-1 << ")= " << 0.0 << std::endl;
      }
      if (info == prob_dim+1) {
	 std::cerr << "\nLapackWrap::factAndSolveSymExpert: WARNING: RCOND is less "
		   << " than machine precision, RCOND = " << rcond << std::endl 
		   << "\nThe matrix is singular to working precision.\n" << std::endl;
      }
    }

    if (info < 0) {
	std::cerr << "\nLapackWrap::factAndSolveSymExpert: xsysvx called with invalid "
		  << " argumnt: \n" << " info = " << info << std::endl;
    }

    std::cout << "\nLapackWrap::factAndSolveSymExpert: The estimate of the reciprocal"
      << " condition number:\nRCOND = " << rcond << "\nCOND = " << 1.0/rcond  << std::endl;

    std::cout << "\nLapackWrap::factAndSolveSymExpert: The optimal nb should be = " 
	      << work(0)/prob_dim << std::endl;
    std::cout << "We used nb = " << nb << std::endl;

    if(!info) {
      std::cout << "\nLapackWrap::factAndSolveSymExpert:\n"
		<< "Estimated forward error bound for each solution vector x(.,i), ferr:\n"
		<< "Relative backward error of solution vector x(.,i), berr : \n\n";
      for(int i=0; i<nrhs; i++){
	std::cout << "ferr(" << i << ")= " << ferr(i) 
		  << " berr(" << i << ")= " << berr(i) << std::endl;
      }
    }
    if (info) {
      return false;
    } 
    return true;
}
// **************************************************************
// **************************************************************


} // end of namespace LapackWrap
