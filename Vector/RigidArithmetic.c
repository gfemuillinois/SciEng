
template <class T>
void crossProd(const RigidArithmetic1d<T, 3>& a, 
	       const RigidArithmetic1d<T, 3>& b, 
	       RigidArithmetic1d<T, 3>& c) {
  c.data[0] =  a.data[1]*b.data[2] - a.data[2]*b.data[1]; 
  c.data[1] = -a.data[0]*b.data[2] + a.data[2]*b.data[0]; 
  c.data[2] =  a.data[0]*b.data[1] - a.data[1]*b.data[0]; 
}
