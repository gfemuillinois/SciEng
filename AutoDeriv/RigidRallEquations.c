/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
template<class T, Subscript nvars>
void RigidRallEquations<T,nvars>::evaluateAt(const Array1d<T>& vars){

  FormedArray1d<RigidRall1d<T,nvars> > np(nvars);
  for (int in = 0; in < nvars; in++) np(in) = RigidRall1d<T,nvars>(in, vars(in));
  
  FormedArray1d<RigidRall1d<T,nvars> > op(nvars);
  for (int i = 0; i < nvars; i++){
    op(i) = ( (*this)(i) )(np);  // evaluate i_th equation with derivatives.
    j[i] = op(i).gradient();    // Unpack.
    v(i) = op(i)();
  }
}
template<class T, Subscript nvars>
Boolean RigidRallEquations<T,nvars>::converged_to(const T& limit) const {
  // Compare norm to limit, stop when we know answer.
  T norm(0.);
  for( int i = 0; i < nvars; i++ ){
   norm += v(i)*v(i);
  }
  return sqrt(norm) <= limit;
}

