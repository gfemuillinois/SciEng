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

#include "clarch.h"

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

    void FTNAME(dgesvd)(const char JOBU[], const char JOBVT[], const int& M, const int& N, const double AP[],   
    const int& LDA, double SP[], double UP[], const int& LDU, double VTP[], const int& LDVT, 
    double WORK[], const int& LWORK, int& INFO);                                             
    void FTNAME(sgesvd)(const char JOBU[], const char JOBVT[], const int& M, const int& N, const float AP[],   
    const int& LDA, float SP[], float UP[], const int& LDU, float VTP[], const int& LDVT, 
    float WORK[], const int& LWORK, int& INFO);                                             
}



class LapackSubroutines { 
public:
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

    static void xgetrs(const char TRANS[], 
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

    enum Job { all, separate, overwrite, none };                                                      
    static char job_symbol[4];                                                                         
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

inline void LapackSubroutines::xgetrs(const char TRANS[], const int& N, const int& NRHS, double* A, const int& LDA,
	                                     const int* IPIV, double* B, const int& LDB, int& INFO) {

    FTNAME(dgetrs)(TRANS, N, NRHS, A, LDA, IPIV, B, LDB, INFO);
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

char LapackSubroutines::job_symbol[] = { 'A', 'S', 'O', 'N' };

#endif
