/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef LAPACK_subroutinesH
#define LAPACK_subroutinesH

#include "SciEng/clarch.h"

// Declarations for LAPACK Fortran routines that we use.

extern "C" {
    // General matrices
    void FTNAME(sgetrf)(const int& M, const int& N, float A[], const int& LDA, int IPIV[], int& INFO);
    void FTNAME(dgetrf)(const int& M, const int& N, double A[], const int& LDA, int IPIV[], int& INFO);

    void FTNAME(sgetrs)(const char TRANS[], const int& N, const int& NRHS, float A[], const int& LDA,
    	           const int IPIV[], float B[], const int& LDB, int& INFO);


    void FTNAME(dgetrs)(const char TRANS[], const int& N, const int& NRHS, double A[], const int& LDA,
    	           const int IPIV[], double B[], const int& LDB, int& INFO);


    // Symmetric, positive-definite, packed matrices
    void FTNAME(spptrf)(const char UPLO[], const int& N, float AP[], int& INFO);
    void FTNAME(dpptrf)(const char UPLO[], const int& N, double AP[], int& INFO);

    void FTNAME(spptrs)(const char UPLO[], const int& N, const int& NRHS, const float AP[],
    	           float B[], const int& LDB, int& INFO);


    void FTNAME(dpptrs)(const char UPLO[], const int& N, const int& NRHS, const double AP[],
    	           double B[], const int& LDB, int& INFO);


  // Factoring and solving symmetric systems of equations. Dense storage matrices.

  // expert driver to solve a symmeric system of equations, possible not positive definite.
  void FTNAME(dsysvx)(const char fact[], const char uplo[], const int& n, const int& nhrs, 
		      const double* a, const int& lda, double* af, const int& ldaf,
		      int* ipiv,  
		      const double* b, const int& ldab, double* x, const int& ldx, 
		      double& rcond, double* ferr, double* berr, 
		      double* work, const int& lwork, int* iwork, int& info);

  void FTNAME(ssysvx)(const char fact[], const char uplo[], const int& n, const int& nhrs, 
		      const float* a, const int& lda, float* af, const int& ldaf,
		      int* ipiv,  
		      const float* b, const int& ldab, float* x, const int& ldx, 
		      float& rcond, float* ferr, float* berr, 
		      float* work, const int& lwork, int* iwork, int& info);
   

  // Eigenvalue and eigenvector calculation for symmetric matrices
  
  void FTNAME(ssyev)(const char JOBZ[], const char UPLO[], const int& N, float A[], const int& LDA, 
		     float EIGEN[], float WORK[], const int& LWORK, const int& INFO);
  void FTNAME(dsyev)(const char JOBZ[], const char UPLO[], const int& N, double A[], const int& LDA, 
		     double EIGEN[], double WORK[], const int& LWORK, const int& INFO);


  // SVD
    void FTNAME(dgesvd)(const char JOBU[], const char JOBVT[], const int& M, const int& N, const double AP[],   
    const int& LDA, double SP[], double UP[], const int& LDU, double VTP[], const int& LDVT, 
    double WORK[], const int& LWORK, int& INFO);                                             
    void FTNAME(sgesvd)(const char JOBU[], const char JOBVT[], const int& M, const int& N, const float AP[],   
    const int& LDA, float SP[], float UP[], const int& LDU, float VTP[], const int& LDVT, 
    float WORK[], const int& LWORK, int& INFO);                                             
}



class LapackSubroutines { 
public:
    enum Job { all, separate, overwrite, none_job };                                                      
    static char job_symbol[4];                                                                         

    enum Trans {no_trans, trans, conj};
    static char trans_char[3];

  enum UpLo { upper, lower };
  static char up_lo[2]; 

    // Factoring general matrices
    static void xgetrf(
        const int& M, const int& N, float* A, const int& LDA, 
        int* IPIV, int& INFO
    );
    static void xgetrf( 
        const int& M, const int& N, double* A, const int& LDA, 
        int* IPIV, int& INFO
    );

    //Solving general factored matrices

    static void xgetrs(const char TRANS[], 
        const int& N, const int& NRHS, float* A, const int& LDA,
        const int IPIV[], 
        float* B, const int& LDB, 
        int& INFO
    );

    static void xgetrs(const Trans t, 
        const int& N, const int& NRHS, float* A, const int& LDA,
        const int IPIV[], 
        float* B, const int& LDB, 
        int& INFO
    );

    static void xgetrs(const char TRANS[], 
        const int& N, const int& NRHS, double* A, const int& LDA,
        	    const int* IPIV, double* B, const int& LDB,
        	    int& INFO
    );  	    

    static void xgetrs(const Trans t, 
        const int& N, const int& NRHS, double* A, const int& LDA,
        	    const int* IPIV, double* B, const int& LDB,
        	    int& INFO
    );

    // Factoring symmetric, positive-definite, packed matrices
    static void xpptrf(const char UPLO[], const int& N, float* AP, int& INFO);
    static void xpptrf(const char UPLO[], const int& N, double* AP, int& INFO);

    // Solving factored symmetric, positive-definite, packed matrices

    static void xpptrs(const char UPLO[], 
        const int& N, const int& NRHS, const float AP[],
        float B[], const int& LDB, 
        int& INFO
    );

    static void xpptrs(const char* UPLO, 
        const int& N, const int& NRHS, const double AP[],
        	  double B[], const int& LDB, 
        	  int& INFO
    );  	  


  // Factoring and solving symmetric systems of equations. Dense storage matrices.

  // expert driver to solve a symmeric system of equations, possible not positive definite.
  static void xsysvx(const char fact, const LapackSubroutines::UpLo uplo, const int& n, const int& nhrs, 
		     const double* a, const int& lda, double* af, const int& ldaf,
		     int* ipiv,  
		     const double* b, const int& ldab, double* x, const int& ldx, 
		     double& rcond, double* ferr, double* berr, 
		     double* work, const int& lwork, int* iwork, int& info);

  static void xsysvx(const char fact, const LapackSubroutines::UpLo uplo, const int& n, const int& nhrs, 
		     const float* a, const int& lda, float* af, const int& ldaf,
		     int* ipiv,  
		     const float* b, const int& ldab, float* x, const int& ldx, 
		     float& rcond, float* ferr, float* berr, 
		     float* work, const int& lwork, int* iwork, int& info);


  // Eigenvalue and eigenvector calculation for symmetric matrices
  static void xsyev(const char JOBZ[], const char UPLO[], const int& N, float A[], const int& LDA, 
		    float EIGEN[], float WORK[], const int& LWORK, const int& INFO);
  static void xsyev(const char JOBZ[], const char UPLO[], const int& N, double A[], const int& LDA, 
		    double EIGEN[], double WORK[], const int& LWORK, const int& INFO);


  // SVD
    static void xgesvd(Job u_storage, Job vt_storage, const int& M, const int& N, const double AP[],   
        const int& LDA, double SP[], double UP[], const int& LDU, double VTP[], const int& LDVT, 
        double WORK[], const int& LWORK, int& INFO);                                             
    static void xgesvd(Job u_storage, Job vt_storage, const int& M, const int& N, const float AP[],   
        const int& LDA, float SP[], float UP[], const int& LDU, float VTP[], const int& LDVT, 
        float WORK[], const int& LWORK, int& INFO);                                             

};


// Factoring general matrices
inline 
void LapackSubroutines::
xgetrf(const int& M, const int& N, float* A, const int& LDA, int* IPIV, int& INFO) {
    FTNAME(sgetrf)(M, N, A, LDA, IPIV, INFO);
}

inline 
void LapackSubroutines::
xgetrf(const int& M, const int& N, double* A, const int& LDA, int* IPIV, int& INFO) {
    FTNAME(dgetrf)(M, N, A, LDA, IPIV, INFO);
}


//Solving general factored matrices

inline void LapackSubroutines::xgetrs(const char TRANS[], const int& N, const int& NRHS, float* A, const int& LDA,
                                      const int IPIV[], float* B, const int& LDB, int& INFO) {

    FTNAME(sgetrs)(TRANS, N, NRHS, A, LDA, IPIV, B, LDB, INFO);
}

inline void LapackSubroutines::xgetrs(const LapackSubroutines::Trans t, const int& N, const int& NRHS, float* A, 
				      const int& LDA, const int IPIV[], float* B, const int& LDB, int& INFO) {

    FTNAME(sgetrs)( &trans_char[t], N, NRHS, A, LDA, IPIV, B, LDB, INFO);
}

inline void LapackSubroutines::xgetrs(const char TRANS[], const int& N, const int& NRHS, double* A, const int& LDA,
	                                     const int* IPIV, double* B, const int& LDB, int& INFO) {

    FTNAME(dgetrs)(TRANS, N, NRHS, A, LDA, IPIV, B, LDB, INFO);
}

inline void LapackSubroutines::xgetrs(const LapackSubroutines::Trans t, const int& N, const int& NRHS, double* A, 
				      const int& LDA, const int* IPIV, double* B, const int& LDB, int& INFO) {

    FTNAME(dgetrs)( &trans_char[t], N, NRHS, A, LDA, IPIV, B, LDB, INFO);
}


// Factoring symmetric, positive-definite, packed matrices
inline void LapackSubroutines::xpptrf(const char UPLO[], const int& N, float* AP, int& INFO) {
    FTNAME(spptrf)(UPLO, N, AP, INFO);
}
inline void LapackSubroutines::xpptrf(const char UPLO[], const int& N, double* AP, int& INFO) {
    FTNAME(dpptrf)(UPLO, N, AP, INFO);
}

// Solving factored symmetric, positive-definite, packed matrices

inline void LapackSubroutines::xpptrs(const char UPLO[], const int& N, const int& NRHS, const float AP[],
	                                     float B[], const int& LDB, int& INFO) {

    FTNAME(spptrs)(UPLO, N, NRHS, AP, B, LDB, INFO);
}

inline void LapackSubroutines::xpptrs(const char* UPLO, const int& N, const int& NRHS, const double AP[],
	                                     double B[], const int& LDB, int& INFO) {

    FTNAME(dpptrs)(UPLO, N, NRHS, AP, B, LDB, INFO);
}


// expert driver to solve a symmeric system of equations, possible not positive definite.
inline void LapackSubroutines::xsysvx(const char fact, const LapackSubroutines::UpLo uplo, 
				      const int& n, const int& nhrs, 
				      const double* a, const int& lda, double* af, const int& ldaf,
				      int* ipiv,  
				      const double* b, const int& ldab, double* x, const int& ldx, 
				      double& rcond, double* ferr, double* berr, 
				      double* work, const int& lwork, int* iwork, int& info) {

  FTNAME(dsysvx)(&fact, &up_lo[uplo], n, nhrs, a, lda, af, ldaf, ipiv, b, ldab, x, ldx, 
		 rcond, ferr, berr, work, lwork, iwork, info);
}

inline void LapackSubroutines::xsysvx(const char fact, const LapackSubroutines::UpLo uplo, 
				      const int& n, const int& nhrs, 
				      const float* a, const int& lda, float* af, const int& ldaf,
				      int* ipiv,  
				      const float* b, const int& ldab, float* x, const int& ldx, 
				      float& rcond, float* ferr, float* berr, 
				      float* work, const int& lwork, int* iwork, int& info){

  FTNAME(ssysvx)(&fact, &up_lo[uplo], n, nhrs, a, lda, af, ldaf, ipiv, b, ldab, x, ldx, 
		 rcond, ferr, berr, work, lwork, iwork, info);
}


// Eigenvalue and eigenvector calculation for symmetric matrices
inline void LapackSubroutines::
xsyev(const char JOBZ[], const char UPLO[], const int& N, float A[], const int& LDA, 
      float EIGEN[], float WORK[], const int& LWORK, const int& INFO) {

  FTNAME(ssyev)(JOBZ, UPLO, N, A, LDA, EIGEN, WORK, LWORK, INFO);
}

inline void LapackSubroutines::
xsyev(const char JOBZ[], const char UPLO[], const int& N, double A[], const int& LDA, 
      double EIGEN[], double WORK[], const int& LWORK, const int& INFO) {

  FTNAME(dsyev)(JOBZ, UPLO, N, A, LDA, EIGEN, WORK, LWORK, INFO);
}

// SVD  
inline void LapackSubroutines::xgesvd(                                                                 
              Job u_storage, Job vt_storage,                                                           
              const int& M, const int& N, const double AP[], const int& LDA,                           
              double SP[], double UP[], const int& LDU, double VTP[], const int& LDVT,                 
              double WORK[], const int& LWORK, int& INFO
       ){
       FTNAME(dgesvd)( &job_symbol[u_storage], &job_symbol[vt_storage],
              M, N, AP, LDA,
              SP, UP, LDU, VTP, LDVT,
              WORK, LWORK, INFO);
}

inline void LapackSubroutines::xgesvd(                                                                 
              Job u_storage, Job vt_storage,                                                           
              const int& M, const int& N, const float AP[], const int& LDA,
              float SP[], float UP[], const int& LDU, float VTP[], const int& LDVT,
              float WORK[], const int& LWORK, int& INFO
       ){
       FTNAME(sgesvd)( &job_symbol[u_storage], &job_symbol[vt_storage],
              M, N, AP, LDA,
              SP, UP, LDU, VTP, LDVT,
              WORK, LWORK, INFO);
}

#endif
