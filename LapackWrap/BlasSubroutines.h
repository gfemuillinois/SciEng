/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef BlasSubroutinesH
#define BlasSubroutinesH

#include "clarch.h"

extern "C" {          // Raw BLAS prototypes.
  void FTNAME(dgemv)(const char TRANS[], const int& M, const int& N, const double& ALPHA,
             const double* AP, const int& LDA, const double* XP, const int& INCX,
             const double& BETA, double* YP, const int& INCY);
  void FTNAME(sgemv)(const char TRANS[], const int& M, const int& N, const float& ALPHA,
             const float* AP, const int& LDA, const float* XP, const int& INCX,
             const float& BETA, float* YP, const int& INCY);
  void FTNAME(dgemm)(const char TRANSA[], const char TRANSB[], const int& M, const int& N, const int& K, const double& ALPHA,
             const double* AP, const int& LDA, const double* BP, const int& LDB,
             const double& BETA, double* CP, const int& LDC);
  void FTNAME(sgemm)(const char TRANSA[], const char TRANSB[], const int& M, const int& N, const int& K, const float& ALPHA,
             const float* AP, const int& LDA, const float* BP, const int& LDB,
             const float& BETA, float* CP, const int& LDC);
  double FTNAME(ddot)(const int& n, const double* xp, const int& incx, const double* yp, const int& incy);
  float  FTNAME(sdot)(const int& n, const float* xp, const int& incx, const float* yp, const int& incy);
  void   FTNAME(sscal)(const int& n, const float& alpha, const float* xp, const int& incx);
  void   FTNAME(dscal)(const int& n, const double& alpha, const double* xp, const int& incx);
  float  FTNAME(snrm2)(const int& n, const float* xp, const int& incx);
  double FTNAME(dnrm2)(const int& n, const double* xp, const int& incx);

  // y <- alpha * x + y
  void   FTNAME(saxpy)(const int& n, const float& alpha, const float* xp, const int& incx,
		       const float* yp, const int& incy);
  void   FTNAME(daxpy)(const int& n, const double& alpha, const double* xp, const int& incx,
		       const double* yp, const int& incy);
};


class Blas1Subroutines {
public:
    static double xdot(int n, const double* xp, int incx, const double* yp, int incy);
    static float xdot(int n, const float* xp, int incx, const float* yp, int incy);
    static void  xscal(int n, const double alpha, const double* xp, int incx);
    static void  xscal(int n, const float alpha, const float* xp, int incx);
    static double xnrm2(int n, const double* xp, int incx);
    static float xnrm2(int n, const float* xp, int incx);

  static void xaxpy(int n, const float alpha, const float* xp, int incx, const float* yp, int incy);
  static void xaxpy(int n, const double alpha, const double* xp, int incx, const double* yp, int incy);

    // ...
};


class Blas2Subroutines :
  public Blas1Subroutines {
public:
  enum Trans {no_trans, trans, conj};
  static char trans_char[];
  static void xgemv(
     Trans t,
     int m, int n, double alpha, const double* a_p, int lda,
     const double* x_p, int inc_x, double beta,
     double* y_p, int inc_y
  );
  static void xgemv(
     Trans t,
     int m, int n, float alpha, const float* a_p, int lda,
     const float* x_p, int inc_x, float beta,
     float* y_p, int inc_y
  );
  // ...
};


class Blas3Subroutines : 
    public Blas2Subroutines {
public:
    static char trans_char[];
    static void xgemm(  
        Trans t_a,
        Trans t_b,
        int m, int n, int k, 
        double alpha, const double* a_p, int lda,
        const double* b_p, int ldb, double beta,
        double* c_p, int ldc
    );
    static void xgemm( 
        Trans t_a,
        Trans t_b,
        int m, int n, int k, 
        float alpha, const float* a_p, int lda,
        const float* b_p, int ldb, float beta,
        float* c_p, int ldc
    );
    // ...
};

      
inline double Blas1Subroutines::xdot(int n, const double* xp, int incx, const double* yp, int incy){
     return FTNAME(ddot)(n,xp,incx,yp,incy);
}

inline float Blas1Subroutines::xdot(int n, const float* xp, int incx, const float* yp, int incy){
     return FTNAME(sdot)(n,xp,incx,yp,incy);
}

inline void Blas1Subroutines::xscal(int n, const double alpha, const double* xp, int incx){
     FTNAME(dscal)(n,alpha,xp,incx);
}
inline void Blas1Subroutines::xscal(int n, const float alpha, const float* xp, int incx){
     FTNAME(sscal)(n,alpha,xp,incx);
}
inline double Blas1Subroutines::xnrm2(int n, const double* xp, int incx){
     return FTNAME(dnrm2)(n,xp,incx);
}
inline float Blas1Subroutines::xnrm2(int n, const float* xp, int incx){
     return FTNAME(snrm2)(n,xp,incx);
}

inline void Blas1Subroutines::xaxpy(int n, const float alpha, const float* xp, int incx, 
				    const float* yp, int incy) {
  FTNAME(saxpy)(n, alpha, xp, incx, yp, incy);
}
inline void Blas1Subroutines::xaxpy(int n, const double alpha, const double* xp, int incx, 
				    const double* yp, int incy) {
  FTNAME(daxpy)(n, alpha, xp, incx, yp, incy);
}                                                                             


inline void Blas2Subroutines::xgemv(Blas2Subroutines::Trans t,
     int m, int n, double alpha, const double* a_p, int lda,
     const double* x_p, int inc_x, double beta,
     double* y_p, int inc_y){
  FTNAME(dgemv)(&trans_char[t], m, n, alpha, a_p, lda, x_p, inc_x, beta, y_p, inc_y);
}

inline void Blas2Subroutines::xgemv(Blas2Subroutines::Trans t,
     int m, int n, float alpha, const float* a_p, int lda,
     const float* x_p, int inc_x, float beta,
     float* y_p, int inc_y){
  FTNAME(sgemv)(&trans_char[t], m, n, alpha, a_p, lda, x_p, inc_x, beta, y_p, inc_y);
}

inline void Blas3Subroutines::xgemm(Blas3Subroutines::Trans ta, Blas3Subroutines::Trans tb,
     int m, int n, int k, double alpha, const double* a_p, int lda,
     const double* b_p, int ldb, double beta,
     double* c_p, int ldc){
  FTNAME(dgemm)(&trans_char[ta], &trans_char[tb], m, n, k, alpha, a_p, lda, b_p, ldb, beta, c_p, ldc);
}

inline void Blas3Subroutines::xgemm(Blas3Subroutines::Trans ta, Blas3Subroutines::Trans tb,
     int m, int n, int k, float alpha, const float* a_p, int lda,
     const float* b_p, int ldb, float beta,
     float* c_p, int ldc){
  FTNAME(sgemm)(&trans_char[ta], &trans_char[tb], m, n, k, alpha, a_p, lda, b_p, ldb, beta, c_p, ldc);
}

#include "SciEng/String.h"


class BlasErr : 
    public SciEngErr {
public:
    BlasErr(String subr_name, int arg_num): 
        the_subr_name(subr_name),
        the_arg_num(arg_num) {
    }
    String message() const;
private:
    String the_subr_name;
    int the_arg_num;
};


#endif
