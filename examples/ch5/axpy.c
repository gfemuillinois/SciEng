/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

template<class EltType>
void axpy(EltType alpha, const Vector<EltType>& x, Vector<EltType>& y) {
    if (alpha != 0.0) {
        int n = x.numElts();
        for (int i = 0; i < n; i++) y(i) += alpha * x(i);
    }
}

