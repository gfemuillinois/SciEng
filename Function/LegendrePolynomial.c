/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

template<class D>
LegendrePolynomial<D>::LegendrePolynomial(int n) :
    FunctionalAlgebra<D>( recur(n) ) {
}

template<class D>
FunctionalAlgebra<D> LegendrePolynomial<D>::recur(int n) {

    if      (n == 0)  return D(1);
    else if (n == 1)  return FunctionalAlgebra<D>();
    else    return D(2*n-1)/D(n) * FunctionalAlgebra<D>() * LegendrePolynomial<D>(n-1) 
            - (D(n-1)/D(n)) * LegendrePolynomial<D>(n-2);

}

