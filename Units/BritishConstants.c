/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
// CAD: Had to do this to avoid undefined references

template<> 
const BritishConstants<double>::Mass  BritishConstants<double>::slug = 14.59;
template<> 
const BritishConstants<double>::Force BritishConstants<double>::pound = 4.448;
template<> 
const BritishConstants<double>::Acceleration BritishConstants<double>::ft_per_sec2 = .3048;


template<class T> 
const BritishConstants<T>::Mass BritishConstants<T>::slug = 14.59;
template<class T> 
const BritishConstants<T>::Length BritishConstants<T>::foot = .3048;
template<class T> 
const BritishConstants<T>::Length BritishConstants<T>::inch = .0254;
template<class T> 
const BritishConstants<T>::Force BritishConstants<T>::pound = 4.448;
template<class T> 
const BritishConstants<T>::Acceleration BritishConstants<T>::ft_per_sec2 = .3048;

