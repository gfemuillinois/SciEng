/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

template<class T, class Structure>
T& MonoidCommon<T, Structure>::repeatedComposition(T& x, NonNegative<int> n) { 
    // Raise x to the n-th power using the right-to-left binary method
    // of algorithm A, Knuth, The Art of Computer Programming: Seminumerical
    // Algorithms, volume 2, 2nd edition, p. 442.   The variables N, Y,
    // and Z correspond to the variables of the same name in his book.
    int N = n;
    T& Y = x;   // use Knuth's name for the output variable
    T Z = x;
    Structure::identityElement(Y);

    while (1) {
        int halfN = N / 2;
        if (halfN + halfN != N) Structure::compositionLaw(Y, Z);
        N = halfN;
        if (N == 0 ) return Y;
        Structure::compositionLaw(Z, Z);
    }
}

