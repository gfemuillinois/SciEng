//
// Test for static condensation algorithm we use in class LinReAnalysis
//
// The data is from example in epm_6tet4_L2_anal_p1_p2_SpBasLocPb_reAnalysis.tcl
//

#include <iostream>
#include <iomanip>
#include <math.h>
#include <cstdlib>

#include "timer.h"
#include "ConcreteBlas2d.h"
#include "TransposedConcreteBlas2d.h"
#include "LapackWrap/LapackWrap.h"

using std::cout;
using std::endl;

int main() {

  const int ndofs_enrich_prob = 9;

  ConcreteBlas2d<double> lhs_e(ndofs_enrich_prob, ndofs_enrich_prob);

  lhs_e = 0.0;

  // LinReAnalysis::assembleEnrichedProb lhs_e:
  
  lhs_e(0,0)= 0.05;  lhs_e(0,1)= 0.00833333;  lhs_e(0,2)= 0.0166667;  lhs_e(0,4)= 0.00833333;  lhs_e(0,5)= 0.0201389;  lhs_e(0,6)= 0.025; lhs_e(0,7)= 0.0166667;
  lhs_e(1,1)= 0.05;  lhs_e(1,2)= 0.025;	  lhs_e(1,3)= 0.00833333;	lhs_e(1,6)= 0.0166667;	lhs_e(1,8)= 0.0166667;
  lhs_e(2,2)= 0.0833333;	lhs_e(2,3)= 0.00833333;	lhs_e(2,6)= 0.0333333;	lhs_e(2,7)= 0.0166667;	lhs_e(2,8)= 0.025;
  lhs_e(3,3)= 0.0166667;	lhs_e(3,8)= 0.00833333;
  lhs_e(4,4)= 0.0166667;	lhs_e(4,5)= 0.043254;	lhs_e(4,6)= 0.00833333;	lhs_e(4,7)= 0.00833333;
  lhs_e(5,5)= 0.122649;	lhs_e(5,6)= 0.0291667;	lhs_e(5,7)= 0.0248016;
  lhs_e(6,6)= 0.0833333;	lhs_e(6,7)= 0.025;	lhs_e(6,8)= 0.0166667;
  lhs_e(7,7)= 0.05;	lhs_e(7,8)= 0.00833333;
  lhs_e(8,8)= 0.05;

  for(int j=1; j<ndofs_enrich_prob; ++j){
    for(int i=0; i<j; ++i)
      lhs_e(j,i) = lhs_e(i,j);
  }
  cout << "\n\nlhs_e: " << lhs_e << endl;

  
  ConcreteBlas2d<double> rhs_e(ndofs_enrich_prob, 1), sol_e(ndofs_enrich_prob, 1);

  // Using rhs_e integrated with higher order rule. 

  rhs_e(0,0) =0.361111; 
  rhs_e(1,0) =0.800694; 
  rhs_e(2,0) =1.05208;
  rhs_e(3,0) =0.348611; 
  rhs_e(4,0) =0.117361; 
  rhs_e(5,0) =0.368924; 
  rhs_e(6,0) =1.1375;
  rhs_e(7,0) =0.531944; 
  rhs_e(8,0) =1.02569;

  // Solve enriched global problem from scratch:

  // call Lapack to solve dense matrix system.
  LapackSubroutines::UpLo uplo = LapackSubroutines::upper;
  if ( !LapackWrap::factAndSolveSymExpert(lhs_e, uplo, ndofs_enrich_prob /*prob_dim*/, rhs_e /*B*/,
					  sol_e /*X*/) ) { 
    cout << "\n\nLapackWrap::factAndSolveSymExpert Failed " << endl;
  }
  cout << "\n\nSol_e: " << sol_e << endl;
  /*

  Sol_e:
  [
  [0.0487479],
  [6.52579],
  [2.00115],
  [10.4862],
  [2.9182],
  [-0.670134],
  [7.86105],
  [3.81543],
  [12.334]]
  */

  //  cout << "\n\nlhs_e: " << lhs_e << endl;

  // Build lhs_reanal and solve from scratch:

  ConcreteBlas2d<double> lhs_reanal(ndofs_enrich_prob, ndofs_enrich_prob),
    rhs_reanal(ndofs_enrich_prob, 1), sol_reanal(ndofs_enrich_prob, 1);

  ConcreteFortranArray1d<int>  u_enrich_2_u_reanal(ndofs_enrich_prob); 

  u_enrich_2_u_reanal(0) = 0;
  u_enrich_2_u_reanal(1) = 1;
  u_enrich_2_u_reanal(2) = 2;
  u_enrich_2_u_reanal(3) = 3;
  u_enrich_2_u_reanal(4) = 4;
  u_enrich_2_u_reanal(5) = 8;
  u_enrich_2_u_reanal(6) = 5;
  u_enrich_2_u_reanal(7) = 6;
  u_enrich_2_u_reanal(8) = 7;

  for(int j=0; j<ndofs_enrich_prob; ++j) {
    rhs_reanal( u_enrich_2_u_reanal(j), 0) = rhs_e(j, 0);
    for(int i=0; i<ndofs_enrich_prob; ++i) {
      lhs_reanal( u_enrich_2_u_reanal(i), u_enrich_2_u_reanal(j) ) = lhs_e(i,j);
    }
  }
  cout << "\n\nlhs_reanal: " << lhs_reanal << endl;
  cout << "\n\nrhs_reanal: " << rhs_reanal << endl;

  // call Lapack to solve dense matrix system.
  if ( !LapackWrap::factAndSolveSymExpert(lhs_reanal, uplo, ndofs_enrich_prob /*prob_dim*/, 
					  rhs_reanal /*B*/,
					  sol_reanal /*X*/) ) { 
    cout << "\n\nLapackWrap::factAndSolveSymExpert Failed " << endl;
  }
  cout << "\n\nSol_reanal: " << sol_reanal << endl;

  /*
    Sol_reanal:
    [
    [0.0487479],
    [6.52579],
    [2.00115],
    [10.4862],
    [2.9182],
    [7.86105],
    [3.81543],
    [12.334],
    [-0.670134]]
  */

  // Solve using static condensation of dof 5

  // Get K_0_gl, K_gl and F_gl

  const int ndofs_initial_prob = 8, num_enrich = 1;

  ConcreteBlas2d<double> 
    lhs_0(ndofs_initial_prob, ndofs_initial_prob),
    lhs_0_gl(ndofs_initial_prob, num_enrich),
    lhs_gl_0(num_enrich, ndofs_initial_prob),
    lhs_gl(num_enrich, num_enrich),

    rhs_0(ndofs_initial_prob, 1),
    rhs_gl(num_enrich, 1),

    sol_0(ndofs_initial_prob, 1),
    sol_gl(num_enrich, 1);

  for(int j=0; j<ndofs_initial_prob; ++j) {
    rhs_0(j, 0) = rhs_reanal(j, 0);
    for(int i=0; i<ndofs_initial_prob; ++i) {
      lhs_0(i,j) = lhs_reanal(i,j);
    }
  }
  
  for(int j=0; j<num_enrich; ++j) {
    rhs_gl(j, 0) = rhs_reanal(ndofs_initial_prob + j, 0);
    for(int i=0; i<ndofs_initial_prob; ++i) {
      lhs_0_gl(i,j) = lhs_reanal(i,ndofs_initial_prob + j);
      lhs_gl_0(j,i) = lhs_0_gl(i,j);
    }
    for(int i=0; i<num_enrich; ++i) {
      lhs_gl(i,j) = lhs_reanal(ndofs_initial_prob + i,ndofs_initial_prob + j);
    }
  }
  
  cout << "\nlhs_0_gl: " << lhs_0_gl << endl;
  cout << "\nlhs_gl: " << lhs_gl << endl;
  cout << "\nrhs_gl: " << rhs_gl << endl;

  /*
    lhs_0_gl:
    [
    [0.0201389],
    [0],
    [0],
    [0],
    [0.043254],
    [0.0291667],
    [0.0248016],
    [0]]

    lhs_gl:
    [
    [0.122649]]
    
    rhs_gl:
    [
    [0.368924]]
  */


  // Solve system of equations:  K_0 S_0_gl = K_0_gl
  ConcreteBlas2d<double> S_0_gl(ndofs_initial_prob, num_enrich);

  if ( !LapackWrap::factAndSolveSymExpert(lhs_0, uplo, ndofs_initial_prob /*prob_dim*/, 
					  lhs_0_gl /*B*/,
					  S_0_gl /*X*/) ) { 
    cout << "\n\nLapackWrap::factAndSolveSymExpert Failed " << endl;
  } 
  cout << "\n\nS_0_gl: " << S_0_gl << endl;

  /*
    S_0_gl:
    [
    [-0.0930397],
    [-0.00299164],
    [-0.0350907],
    [0.0391877],
    [2.54926],
    [0.12883],
    [0.0561669],
    [-0.0402933]]
  */


  // Build     lhs_gl_hat = lhs_gl - lhs_gl_0 * S_0_gl

  ConcreteBlas2d<double> lhs_gl_hat(num_enrich, num_enrich);

  mult( lhs_gl_0, S_0_gl,
	lhs_gl_hat);
  cout << "\nlhs_gl_hat: " << lhs_gl_hat << endl;

  for(int j=0; j<num_enrich; ++j)
    for(int i=0; i<num_enrich; ++i)
      lhs_gl_hat(i,j) = lhs_gl(i,j) - lhs_gl_hat(i,j);

  cout << "\nlhs_gl_hat: " << lhs_gl_hat << endl;

  /*
    lhs_gl_hat:
    [
    [0.113542]]

    lhs_gl_hat:
    [
    [0.00910661]]

    LinReAnalysis::solveEnrichedProbReAnalysis_SCondenseDense: K_gl_hat: 
    [
    [0.00910693]]

  */

  // Build  F_gl_hat = F_gl - trans(K_0_gl) * U_0

  // lhs_0 sol_0 = rhs_0
  
  cout << "\nlhs_0: " << lhs_0 << endl;
  cout << "\nrhs_0: " << rhs_0 << endl;

  if ( !LapackWrap::factAndSolveSymExpert(lhs_0, uplo, ndofs_initial_prob /*prob_dim*/, 
					  rhs_0 /*B*/,
					  sol_0 /*X*/) ) { 
    cout << "\n\nLapackWrap::factAndSolveSymExpert Failed " << endl;
  } 
  cout << "\n\nsol_0: " << sol_0 << endl;

  /*
 
  sol_0:
  [
  [0.111097],
  [6.52779],
  [2.02467],
  [10.4599],
  [1.20986],
  [7.77472],
  [3.77779],
  [12.361]]

  LinReAnalysis::solveEnrichedProbReAnalysis_SCondenseDense: U_0 = 
  [
  [0.111111], 
  [6.52778], 
  [2.02469], 
  [10.4599], 
  [1.20988], 
  [7.77469], 
  [3.77778], 
  [12.3611]]
  
  */

  // Build  F_gl_hat = F_gl - trans(K_0_gl) * U_0

  ConcreteBlas2d<double> rhs_gl_hat(num_enrich,1);

  mult( lhs_gl_0, sol_0,
	rhs_gl_hat);

  cout << "\n\nrhs_gl_hat: " << rhs_gl_hat << endl;

  for(int i=0; i<num_enrich; ++i)
    rhs_gl_hat(i,0) = rhs_gl(i,0) - rhs_gl_hat(i,0);

  cout << "\n\nrhs_gl_hat: " << rhs_gl_hat << endl;

  /*
 
  rhs_gl_hat:
  [
  [0.375027]]

  rhs_gl_hat:
  [
  [-0.00610265]]


  LinReAnalysis::solveEnrichedProbReAnalysis_SCondenseDense: F_gl_hat: 
  [
  [-0.00610272]]

  */

  // Solve:  K_gl_hat U_gl =  F_gl_hat
  
  // TBD: Finish this !!!

  if ( !LapackWrap::factAndSolveSymExpert(lhs_gl_hat, uplo, num_enrich /*prob_dim*/, 
					  rhs_gl_hat /*B*/,
					  sol_gl /*X*/) ) { 
    cout << "\n\nLapackWrap::factAndSolveSymExpert Failed " << endl;
  } 
  cout << "\n\nsol_gl: " << sol_gl << endl;

  /*
    sol_gl:
    [
    [-0.670134]]   =   Sol_reanal[8] !!

    LinReAnalysis::solveEnrichedProbReAnalysis_SCondenseDense: U_gl: 
    [
    [-0.670119]]
    
  */
  
  // Compute:  U_0_til = U_0 - S_0_gl * U_gl
  // Could also use:   U_0_til = U_0 - (K_0)^{-1} ( K_0_gl * U_gl )
  // The last form does not require that we keep the entire S_0_gl.


  ConcreteBlas2d<double> sol_0_til(ndofs_initial_prob, 1);

  mult( S_0_gl, sol_gl,
	sol_0_til);
  cout << "\nsol_0_til:" << sol_0_til << endl;

  for(int i=0; i<ndofs_initial_prob; ++i)
    sol_0_til(i,0) = sol_0(i,0) - sol_0_til(i,0);

  cout << "\nsol_0_til:" << sol_0_til << endl;

  /*
 
  sol_0_til:
  [
  [0.0487479],
  [6.52579],
  [2.00115],
  [10.4862],
  [2.9182],
  [7.86105],
  [3.81543],
  [12.334]]          = Sol_reanal[0:7] !!!!! Algorithm works  !!! 


  LinReAnalysis::solveEnrichedProbReAnalysis_SCondenseDense: Sol_e: 
  [
  [0.0487631], 
  [6.52577], 
  [2.00118], 
  [10.4861], 
  [2.91818], 
  [-0.670119], 
  [7.86102], 
  [3.81542], 
  [12.3341]]
  */

  return EXIT_SUCCESS;
}
