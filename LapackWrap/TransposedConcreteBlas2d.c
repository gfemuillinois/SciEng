/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

template<class T>
TransposedConcreteBlas2d<T>::TransposedConcreteBlas2d(ConcreteBlas2d<T>& a) :
    ConcreteArray2dRef<ConcreteRowMajorSubscriptor<2>, T>(
        SubscriptArray<2>(a.shape(1), a.shape(0)), // Subscriptor initializer
        a.firstDatum() 
    ) { 
}

/* CAD
template<class T>
TransposedConcreteBlas2d<T>::operator ConcreteBlas2d<T>() const { 
    ConcreteBlas2d<T> result(shape(1), shape(0));
    concreteCopy(result, ConcreteArray2dConstRef< SubscriptorType, T>(*this));
    return result;
}
*/

template<class T>
ConcreteBlas2d<T> operator*(const TransposedConcreteBlas2d<T>& t, 
                            const TransposedConcreteBlas2d<T>& u) { 

  if ( t.shape(1) != u.shape(0) ) throw  ArrayErr::Shape();

    ConcreteBlas2d<T> result(t.shape(0), u.shape(1));
    Blas3Subroutines::xgemm(
        Blas3Subroutines::trans, Blas3Subroutines::trans, 
        t.shape(0), u.shape(1), t.shape(1),
        T(1), t.firstDatum(), t.shape(1),
        u.firstDatum(), u.shape(1),
        T(0), result.firstDatum(), result.shape(0)
    );
    return result;
}

template<class T>
void
mult(const TransposedConcreteBlas2d<T>& A, 
     const TransposedConcreteBlas2d<T>& B, ConcreteBlas2d<T>& C ) {

  // same as above: c = A^t * B^t

  if ( C.shape(0) != A.shape(0) ) throw  ArrayErr::Shape();
  if ( C.shape(1) != B.shape(1) ) throw  ArrayErr::Shape();
  if ( A.shape(1) != B.shape(0) ) throw  ArrayErr::Shape();

  Blas3Subroutines::xgemm( Blas3Subroutines::trans, 
			   Blas3Subroutines::trans, 
			   A.shape(0), B.shape(1), A.shape(1),
			   T(1), A.firstDatum(), A.shape(1),
			   B.firstDatum(), B.shape(1),
			   T(0), C.firstDatum(), C.shape(0) );
}

template<class T>
ConcreteBlas2d<T> operator*(const ConcreteBlas2d<T>& u, 
			    const TransposedConcreteBlas2d<T>& t) {

  if ( u.shape(1) != t.shape(0) ) throw  ArrayErr::Shape();

  ConcreteBlas2d<T> result(u.shape(0), t.shape(1));
  Blas3Subroutines::xgemm( 
      Blas3Subroutines::no_trans, Blas3Subroutines::trans, 
      u.shape(0), t.shape(1), u.shape(1),
      T(1), u.firstDatum(), u.shape(0),
      t.firstDatum(), t.shape(1),
      T(0), result.firstDatum(), result.shape(0)
   );
  return result;
}

template<class T>
void
mult(const ConcreteBlas2d<T>& a, const TransposedConcreteBlas2d<T>& b, 
     ConcreteBlas2d<T>& c ) {

  // same as above: c = a * b^t

  if ( c.shape(0) != a.shape(0) ) throw  ArrayErr::Shape();
  if ( c.shape(1) != b.shape(1) ) throw  ArrayErr::Shape();
  if ( a.shape(1) != b.shape(0) ) throw  ArrayErr::Shape();

  Blas3Subroutines::xgemm( Blas3Subroutines::no_trans, 
			   Blas3Subroutines::trans, 
			   a.shape(0), b.shape(1), a.shape(1),
			   T(1), a.firstDatum(), a.shape(0),
			   b.firstDatum(), b.shape(1),
			   T(0), c.firstDatum(), c.shape(0) );
}

template<class T>
ConcreteBlas2d<T> 
operator*(const TransposedConcreteBlas2d<T>& t, const ConcreteBlas2d<T>& u){

  if ( t.shape(1) != u.shape(0) ) throw  ArrayErr::Shape();

  ConcreteBlas2d<T> result(t.shape(0), u.shape(1));
  Blas3Subroutines::xgemm(
      Blas3Subroutines::trans, Blas3Subroutines::no_trans, 
      t.shape(0), u.shape(1), t.shape(1),
      T(1), t.firstDatum(), t.shape(1),
      u.firstDatum(), u.shape(0),
      T(0), result.firstDatum(), result.shape(0)
   );
  return result;
}


template<class T>
void 
mult(const TransposedConcreteBlas2d<T>& A, const ConcreteBlas2d<T>& B, 
     ConcreteBlas2d<T>& C ) {
  // same as above: C = A^t * B

  if ( C.shape(0) != A.shape(0) ) throw  ArrayErr::Shape();
  if ( C.shape(1) != B.shape(1) ) throw  ArrayErr::Shape();
  if ( A.shape(1) != B.shape(0) ) throw  ArrayErr::Shape();

  Blas3Subroutines::xgemm(Blas3Subroutines::trans, Blas3Subroutines::no_trans, 
			  A.shape(0), B.shape(1), A.shape(1),
			  T(1), A.firstDatum(), A.shape(1),
			  B.firstDatum(), B.shape(0),
			  T(0), C.firstDatum(), C.shape(0) );
}

template<class T>
ConcreteBlas1d<T> operator*(const TransposedConcreteBlas2d<T>& t, 
			    const ConcreteBlas1d<T>& u){

  if ( t.shape(1) != u.shape(0) ) throw  ArrayErr::Shape();

  ConcreteBlas1d<T> result( t.shape(0) );
  Blas3Subroutines::xgemv(
      Blas3Subroutines::trans,
      t.shape(1), t.shape(0),
      T(1), t.firstDatum(), t.shape(1),
      u.firstDatum(), 1,
      T(0), result.firstDatum(), 1
   );
  return result;
}


template<class T>
void 
mult(const TransposedConcreteBlas2d<T>& A, const ConcreteBlas1d<T>& b, 
     ConcreteBlas1d<T>& c ) {

  // same as above: c = A^t * c

  if ( c.shape(0) != A.shape(0) ) throw  ArrayErr::Shape();
  if ( A.shape(1) != b.shape(0) ) throw  ArrayErr::Shape();


  Blas3Subroutines::xgemv( Blas3Subroutines::trans,
			   A.shape(1), A.shape(0),
			   T(1), A.firstDatum(), A.shape(1),
			   b.firstDatum(), 1,
			   T(0), c.firstDatum(), 1 );
}
