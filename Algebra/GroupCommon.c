/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

template<class T, class Structure>
T& GroupCommon<T, Structure>::repeatedComposition(T& x, int n) { 
    if (n < 0) { 
        Structure::selfInversion(x);
        n = -n;
    }
    return MonoidCommon<T, Structure>::repeatedComposition(x, n);
}

