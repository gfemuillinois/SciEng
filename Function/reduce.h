/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef reduceH
#define reduceH


template<class Browseable>
Browseable::EltT 
reduce(const Browseable& b, void(Browseable::EltT::*f)(Browseable::EltT)) { 
    // Apply the member function "T::f(T)" between successive elements of "b".

    Browseable::BrowserType i(b);
    if (!i.more()) return Browseable::EltT();

    // Start with result being first element, then apply f to current
    // result and next element.
    Browseable::EltT result = i.current();
    i.advance();
    while (i.more()) {
        (result.*f)(i.current());
        i.advance();
    }
    return result;
}


#endif
