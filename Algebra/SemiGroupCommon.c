/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

template<class T, class Structure>
T& SemiGroupCommon<T, Structure>::repeatedComposition(T& x, Positive<int> n) { 
    if (n > 1) {  
        T t = x;
        int m = n;
        while (--m) Structure::compositionLaw(x, t);
    }
    return x;
}

