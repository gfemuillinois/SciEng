/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

#include "SIConstants.h"

// CAD: Had to do this to avoid undefined references

template<> const SIConstants<double>::Mass         SIConstants<double>::kilogram       = 1;
template<> const SIConstants<double>::Acceleration SIConstants<double>::g              = 9.80665;


template<class T> const typename SIConstants<T>::Mass         SIConstants<T>::kilogram       = 1;
template<class T> const typename SIConstants<T>::Length       SIConstants<T>::meter          = 1;
template<class T> const typename SIConstants<T>::Force        SIConstants<T>::newton         = 1;
template<class T> const typename SIConstants<T>::Time         SIConstants<T>::second         = 1;
template<class T> const typename SIConstants<T>::Acceleration SIConstants<T>::meter_per_sec2 = 1;
template<class T> const typename SIConstants<T>::Acceleration SIConstants<T>::g              = 9.80665;



